#include "howtostayhealthywidget.h"
#include "ui_howtostayhealthywidget.h"

HowToStayHealthyWidget::HowToStayHealthyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HowToStayHealthyWidget)
{
    ui->setupUi(this);
}

HowToStayHealthyWidget::~HowToStayHealthyWidget()
{
    delete ui;
}
