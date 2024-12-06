#include "quizdragdropwidget.h"
#include "ui_quizdragdropwidget.h"

#include <QMessageBox>

QuizDragDropWidget::QuizDragDropWidget(QWidget *parent, QuizModel *QuizModel)
    : QWidget(parent) ,
    ui(new Ui::QuizDragDropWidget),
    quizModel(QuizModel)
{
    ui->setupUi(this);
    connect(ui->backToQuizHomeButton, &QPushButton::clicked, this, &QuizDragDropWidget::backToQuizHomeButtonClicked);
    connect(ui->submitButton, &QPushButton::clicked, this, &QuizDragDropWidget::onSubmitClicked);

    ui->answer1->setQuestionText("Your gut produces important vitamins like _____ and K.");
    ui->answer2->setQuestionText("Nutrients are absorbed into your bloodstream in the _____.");
    ui->answer3->setQuestionText("_____ can help restore gut balance, particularly after illness or antibiotic use.");
    ui->answer4->setQuestionText("The _____ is home to your gut microbiome. It also absorbs water and helps process waste.");
    ui->answer5->setQuestionText("_____ has been linked to autoimmune diseases, such as rheumatoid arthritis, and heart disease.");
    ui->answer6->setQuestionText("Certain gut bacteria produce harmful chemicals like _____, which can cause cholesterol to build up.");
    ui->answer7->setQuestionText("Food which lacks fiber, and contains many preservatives and additives are _____.");
    ui->answer8->setQuestionText("Your gut and brain communicate via the _____.");
    ui->answer9->setQuestionText("Your gut is home to trillions of tiny organisms (bacteria, viruses, fungi) called the _____.");
    ui->answer10->setQuestionText("The liver, pancreas, and gallbladder produce important _____ and bile to aid in digestion.");

    connect(ui->answer1, &DropLabel::answerDropped, this, &QuizDragDropWidget::onAnswerDropped);
    connect(ui->answer2, &DropLabel::answerDropped, this, &QuizDragDropWidget::onAnswerDropped);
    connect(ui->answer3, &DropLabel::answerDropped, this, &QuizDragDropWidget::onAnswerDropped);
    connect(ui->answer4, &DropLabel::answerDropped, this, &QuizDragDropWidget::onAnswerDropped);
    connect(ui->answer5, &DropLabel::answerDropped, this, &QuizDragDropWidget::onAnswerDropped);
    connect(ui->answer6, &DropLabel::answerDropped, this, &QuizDragDropWidget::onAnswerDropped);
    connect(ui->answer7, &DropLabel::answerDropped, this, &QuizDragDropWidget::onAnswerDropped);
    connect(ui->answer8, &DropLabel::answerDropped, this, &QuizDragDropWidget::onAnswerDropped);
    connect(ui->answer9, &DropLabel::answerDropped, this, &QuizDragDropWidget::onAnswerDropped);
    connect(ui->answer10, &DropLabel::answerDropped, this, &QuizDragDropWidget::onAnswerDropped);

    quizModel->addDragDropQuestion("Your gut produces important vitamins like _____ and K.", "B12");
    quizModel->addDragDropQuestion("Nutrients are absorbed into your bloodstream in the _____.", "Small Intestine");
    quizModel->addDragDropQuestion("_____ can help restore gut balance, particularly after illness or antibiotic use.", "Probiotics");
    quizModel->addDragDropQuestion("The _____ is home to your gut microbiome. It also absorbs water and helps process waste.", "Large Intestine");
    quizModel->addDragDropQuestion("_____ has been linked to autoimmune diseases, such as rheumatoid arthritis, and heart disease.", "Dysbiosis");
    quizModel->addDragDropQuestion("Certain gut bacteria produce harmful chemicals like _____, which can cause cholesterol to build up.", "TMAO");
    quizModel->addDragDropQuestion("Food which lacks fiber, and contains many preservatives and additives are _____.", "Processed foods");
    quizModel->addDragDropQuestion("Your gut and brain communicate via the _____.", "Gut-brain Axis");
    quizModel->addDragDropQuestion("Your gut is home to trillions of tiny organisms (bacteria, viruses, fungi) called the _____.", "Microbiome");
    quizModel->addDragDropQuestion("The liver, pancreas, and gallbladder produce important _____ and bile to aid in digestion.", "Enzymes");
}

void QuizDragDropWidget::onAnswerDropped(const QString &question, const QString &answer)
{
    userAnswers[question] = answer; // Store the answer locally
}

void QuizDragDropWidget::onSubmitClicked()
{
    quizModel->setDragDropScore(0);

    // Pass each answer to the model
    for (auto it = userAnswers.begin(); it != userAnswers.end(); ++it)
    {
        quizModel->submitDragDropAnswer(it.key(), it.value());
    }

    // Get the score
    int score = quizModel->getDragDropScore();

    // Show the score in a QMessageBox
    QMessageBox::information(this, "Quiz Results", QString("Your score is: %1").arg(score) + "/10");
}

QuizDragDropWidget::~QuizDragDropWidget()
{
    delete ui;
}
