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

    connect(ui->answer1, &DropLabel::answerDropped, this, &QuizDragDropWidget::onAnswerDropped);
    connect(ui->answer2, &DropLabel::answerDropped, this, &QuizDragDropWidget::onAnswerDropped);
    connect(ui->answer3, &DropLabel::answerDropped, this, &QuizDragDropWidget::onAnswerDropped);
    connect(ui->answer4, &DropLabel::answerDropped, this, &QuizDragDropWidget::onAnswerDropped);

    quizModel->addDragDropQuestion("Your gut produces important vitamins like _____ and K.", "B12");
    quizModel->addDragDropQuestion("Nutrients are absorbed into your bloodstream in the _____.", "Small Intestine");
    quizModel->addDragDropQuestion("_____ can help restore gut balance, particularly after illness or antibiotic use.", "Probiotics");
    quizModel->addDragDropQuestion("The _____ is home to your gut microbiome. It also absorbs water and helps process waste.", "Large Intestine");
}

void QuizDragDropWidget::onAnswerDropped(const QString &question, const QString &answer) {
    userAnswers[question] = answer; // Store the answer locally
}

void QuizDragDropWidget::onSubmitClicked() {
    if (!quizModel) return;

    // Pass each answer to the model
    for (auto it = userAnswers.begin(); it != userAnswers.end(); ++it)
    {
        quizModel->submitDragDropAnswer(it.key(), it.value());
    }

    // Get the score
    int score = quizModel->getDragDropScore();

    // Show the score in a QMessageBox
    QMessageBox::information(this, "Quiz Results", QString("Your score is: %1").arg(score));
}


QuizDragDropWidget::~QuizDragDropWidget()
{
    delete ui;
}
