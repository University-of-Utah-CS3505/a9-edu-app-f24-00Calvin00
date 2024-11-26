#include "whyguthealthwidget.h"
#include "ui_whyguthealthwidget.h"

WhyGutHealthWidget::WhyGutHealthWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WhyGutHealthWidget)
{
    ui->setupUi(this);
}

WhyGutHealthWidget::~WhyGutHealthWidget()
{
    delete ui;
}
