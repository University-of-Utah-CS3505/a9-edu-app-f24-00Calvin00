#include "quizzinghomewidget.h"
#include "ui_quizzinghomewidget.h"

QuizzingHomeWidget::QuizzingHomeWidget(QWidget *parent, QuizModel *QuizModel)
    : QWidget(parent)
    , ui(new Ui::QuizzingHomeWidget),
    quizModel(QuizModel)
{
    ui->setupUi(this);
    connect(ui->matchingButton, &QPushButton::clicked, this, &QuizzingHomeWidget::matchingButtonClicked);
    connect(ui->dragDropButton, &QPushButton::clicked, this, &QuizzingHomeWidget::dragDropButtonClicked);
    connect(ui->backToStartButton, &QPushButton::clicked, this, &QuizzingHomeWidget::backToStartButtonClicked);
}

QuizzingHomeWidget::~QuizzingHomeWidget()
{
    delete ui;
}
