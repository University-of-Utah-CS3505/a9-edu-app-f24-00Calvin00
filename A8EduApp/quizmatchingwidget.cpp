#include "quizmatchingwidget.h"
#include "ui_quizmatchingwidget.h"

#include <QMessageBox>

QuizMatchingWidget::QuizMatchingWidget(QWidget *parent, QuizModel *QuizModel)
    : QWidget(parent),
    ui(new Ui::QuizMatchingWidget),
    quizModel(QuizModel)
{
    ui->setupUi(this);

    // Set the background color
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor(238, 223, 242));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    connect(ui->backToQuizHomeButton, &QPushButton::clicked, this, &QuizMatchingWidget::backToQuizHomeButtonClicked);
    connect(ui->submitButton, &QPushButton::clicked, this, &QuizMatchingWidget::onSubmitClicked);

    quizModel->addMatchingQuestion("Vocab1", 3);
    quizModel->addMatchingQuestion("Vocab2", 4);
    quizModel->addMatchingQuestion("Vocab3", 7);
    quizModel->addMatchingQuestion("Vocab4", 5);
    quizModel->addMatchingQuestion("Vocab5", 1);
    quizModel->addMatchingQuestion("Vocab6", 2);
    quizModel->addMatchingQuestion("Vocab7", 6);
    quizModel->addMatchingQuestion("Vocab8", 10);
    quizModel->addMatchingQuestion("Vocab9", 9);
    quizModel->addMatchingQuestion("Vocab10", 8);
}

void QuizMatchingWidget::onSubmitClicked() {
    quizModel->setMatchingScore(0);

    // Pass each answer to the model
    quizModel->submitMatchingAnswer("Vocab1", ui->spinBox->value());
    quizModel->submitMatchingAnswer("Vocab2", ui->spinBox_6->value());
    quizModel->submitMatchingAnswer("Vocab3", ui->spinBox_2->value());
    quizModel->submitMatchingAnswer("Vocab4", ui->spinBox_3->value());
    quizModel->submitMatchingAnswer("Vocab5", ui->spinBox_4->value());
    quizModel->submitMatchingAnswer("Vocab6", ui->spinBox_5->value());
    quizModel->submitMatchingAnswer("Vocab7", ui->spinBox_7->value());
    quizModel->submitMatchingAnswer("Vocab8", ui->spinBox_8->value());
    quizModel->submitMatchingAnswer("Vocab9", ui->spinBox_9->value());
    quizModel->submitMatchingAnswer("Vocab10", ui->spinBox_10->value());

    // Get the score
    int score = quizModel->getMatchingScore();

    // Show the score in a QMessageBox
    QMessageBox::information(this, "Quiz Results", QString("Your score is: %1").arg(score));
}

QuizMatchingWidget::~QuizMatchingWidget()
{
    delete ui;
}
