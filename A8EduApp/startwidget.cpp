#include "startwidget.h"
#include "ui_startwidget.h"
#include <QMovie>

StartWidget::StartWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::StartWidget)
{
    ui->setupUi(this);
    ui->widget->show();

    QMovie *gif = new QMovie(":/gifs/pooedPoo.gif");
    ui->label->setMovie(gif);
    gif->start();

    // Connect the start button to emit a signal
    connect(ui->learnButton, &QPushButton::clicked, this, &StartWidget::learnButtonClicked);
    connect(ui->quizButton, &QPushButton::clicked, this, &StartWidget::quizButtonClicked);
    connect(ui->resultsButton, &QPushButton::clicked, this, &StartWidget::resultsButtonClicked);
}

StartWidget::~StartWidget()
{
    delete ui;
}
