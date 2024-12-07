#include "whyguthealthwidget.h"
#include "ui_whyguthealthwidget.h"

WhyGutHealthWidget::WhyGutHealthWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WhyGutHealthWidget)
{
    ui->setupUi(this);

    // Set the background color
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor(209, 160, 224));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    connect(ui->backToTeachingWidgetButton, &QPushButton::clicked, this,&WhyGutHealthWidget::backToTeachingWidgetButtonClicked);
}


WhyGutHealthWidget::~WhyGutHealthWidget()
{
    delete ui;
}
