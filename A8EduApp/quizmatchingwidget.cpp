#include "quizmatchingwidget.h"
#include "ui_quizmatchingwidget.h"

QuizMatchingWidget::QuizMatchingWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QuizMatchingWidget)
{
    ui->setupUi(this);
}

QuizMatchingWidget::~QuizMatchingWidget()
{
    delete ui;
}
