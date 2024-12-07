#include "quizzinghomewidget.h"
#include "ui_quizzinghomewidget.h"

QuizzingHomeWidget::QuizzingHomeWidget(QWidget *parent, QuizModel *QuizModel)
    : QWidget(parent)
    , ui(new Ui::QuizzingHomeWidget),
    quizModel(QuizModel)
{
    ui->setupUi(this);

    // Set the background color
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor(238, 223, 242));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    updateScoreLabel();

    connect(ui->matchingButton, &QPushButton::clicked, this, &QuizzingHomeWidget::matchingButtonClicked);
    connect(ui->dragDropButton, &QPushButton::clicked, this, &QuizzingHomeWidget::dragDropButtonClicked);
    connect(ui->backToStartButton, &QPushButton::clicked, this, &QuizzingHomeWidget::backToStartButtonClicked);
}

void QuizzingHomeWidget::updateScoreLabel()
{
    int score = quizModel->getTotalScore();
    int totalQuestions = (quizModel->getTotalDragDropQuestions()) + quizModel->getTotalMatchingQuestions(); // Replace with the correct method name

    // Display score to user
    QString scoreText = QString("%1/%2").arg(score).arg(totalQuestions);
    ui->scoreNumber->setText(scoreText);
}

// Override showEvent to update the label whenever the widget is shown
void QuizzingHomeWidget::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    updateScoreLabel();
}

QuizzingHomeWidget::~QuizzingHomeWidget()
{
    delete ui;
}
