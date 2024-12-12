#include "howtostayhealthywidget.h"
#include "ui_howtostayhealthywidget.h"

HowToStayHealthyWidget::HowToStayHealthyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HowToStayHealthyWidget)
{
    ui->setupUi(this);

    //Add poop image
    QPixmap happyPoop = QPixmap::fromImage(QImage(":/sprites/happyPoo.png"));
    ui->happyPoo->setPixmap(happyPoop.scaled(ui->happyPoo->size(), Qt::KeepAspectRatio));
    ui->happyPoo->setFrameShape(QFrame::NoFrame);

    //Add banana image
    QPixmap banana = QPixmap::fromImage(QImage(":/sprites/banana.png"));
    ui->bananaPic->setPixmap(banana.scaled(ui->bananaPic->size(), Qt::KeepAspectRatio));
    ui->bananaPic->setFrameShape(QFrame::NoFrame);

    // Set the background color
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor(238, 223, 242));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    //coonection for the back button
    connect(ui->backToTeachingWidgetButton, &QPushButton::clicked, this, &HowToStayHealthyWidget::backToTeachingWidgetButtonClicked);
}

HowToStayHealthyWidget::~HowToStayHealthyWidget()
{
    delete ui;
}
