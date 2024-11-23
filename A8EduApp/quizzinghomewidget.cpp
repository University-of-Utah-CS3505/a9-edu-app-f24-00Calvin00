#include "quizzinghomewidget.h"
#include "ui_quizzinghomewidget.h"

QuizzingHomeWidget::QuizzingHomeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QuizzingHomeWidget)
{
    ui->setupUi(this);
}

QuizzingHomeWidget::~QuizzingHomeWidget()
{
    delete ui;
}
