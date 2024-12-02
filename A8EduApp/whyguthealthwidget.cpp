#include "whyguthealthwidget.h"
#include "ui_whyguthealthwidget.h"

WhyGutHealthWidget::WhyGutHealthWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WhyGutHealthWidget)
{
    ui->setupUi(this);
    connect(ui->backToTeachingWidgetButton, &QPushButton::clicked, this,&WhyGutHealthWidget::backToTeachingWidgetButtonClicked);
}


WhyGutHealthWidget::~WhyGutHealthWidget()
{
    delete ui;
}
