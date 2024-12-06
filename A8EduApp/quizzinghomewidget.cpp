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
    palette.setColor(QPalette::Window, QColor(238, 223, 242)); // Use your RGB color
    this->setPalette(palette);
    this->setAutoFillBackground(true); // Ensures the background is filled with the color

    connect(ui->matchingButton, &QPushButton::clicked, this, &QuizzingHomeWidget::matchingButtonClicked);
    connect(ui->dragDropButton, &QPushButton::clicked, this, &QuizzingHomeWidget::dragDropButtonClicked);
    connect(ui->backToStartButton, &QPushButton::clicked, this, &QuizzingHomeWidget::backToStartButtonClicked);
}

QuizzingHomeWidget::~QuizzingHomeWidget()
{
    delete ui;
}
