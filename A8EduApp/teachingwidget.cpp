#include "teachingwidget.h"
#include "ui_teachingwidget.h"

TeachingWidget::TeachingWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::TeachingWidget)
{
    ui->setupUi(this);
}

TeachingWidget::~TeachingWidget()
{
    delete ui;
}
