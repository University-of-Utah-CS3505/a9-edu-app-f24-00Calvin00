#include "startwidget.h"
#include "ui_startwidget.h"

StartWidget::StartWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartWidget)
    , gif(new QMovie(":/gifs/pooedPoo.gif"))
{
    ui->setupUi(this);
    ui->widget->show();
    ui->widget->lower();

    // Set the gif to the label and play it once
    ui->pooedPoo->setMovie(gif);
    gif->start();

    // Connect the start button to emit a signal
    connect(ui->learnButton, &QPushButton::clicked, this, &StartWidget::learnButtonClicked);
    connect(ui->quizButton, &QPushButton::clicked, this, &StartWidget::quizButtonClicked);
    connect(ui->resultsButton, &QPushButton::clicked, this, &StartWidget::resultsButtonClicked);
    connect(ui->replayButton, &QPushButton::clicked, this, [this]() { gif->start(); });
}

StartWidget::~StartWidget()
{
    delete ui;
    delete gif;
}
