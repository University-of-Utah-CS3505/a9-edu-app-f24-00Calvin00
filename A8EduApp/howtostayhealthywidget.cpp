#include "howtostayhealthywidget.h"
#include "ui_howtostayhealthywidget.h"

HowToStayHealthyWidget::HowToStayHealthyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HowToStayHealthyWidget)
{
    ui->setupUi(this);

    // Set the background color
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor(209, 160, 224));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    connect(ui->backToTeachingWidgetButton, &QPushButton::clicked, this, &HowToStayHealthyWidget::backToTeachingWidgetButtonClicked);
}

HowToStayHealthyWidget::~HowToStayHealthyWidget()
{
    delete ui;
}
