#include "introtoguthealthwidget.h"
#include "ui_introtoguthealthwidget.h"

IntroToGutHealthWidget::IntroToGutHealthWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IntroToGutHealthWidget)
{
    ui->setupUi(this);

    // Set the background color
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor(209, 160, 224));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    connect(ui->backToTeachingWidgetButton, &QPushButton::clicked, this, &IntroToGutHealthWidget::backToTeachingWidgetButtonClicked);
}

IntroToGutHealthWidget::~IntroToGutHealthWidget()
{
    delete ui;
}
