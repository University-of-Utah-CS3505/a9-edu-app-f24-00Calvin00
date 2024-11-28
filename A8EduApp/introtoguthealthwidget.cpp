#include "introtoguthealthwidget.h"
#include "ui_introtoguthealthwidget.h"

IntroToGutHealthWidget::IntroToGutHealthWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IntroToGutHealthWidget)
{
    ui->setupUi(this);
    connect(ui->backToTeachingWidgetButton, &QPushButton::clicked, this, &IntroToGutHealthWidget::backToTeachingWidgetButtonClicked);
}

IntroToGutHealthWidget::~IntroToGutHealthWidget()
{
    delete ui;
}
