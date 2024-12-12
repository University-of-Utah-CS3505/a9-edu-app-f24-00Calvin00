#include "whyguthealthwidget.h"
#include "ui_whyguthealthwidget.h"

WhyGutHealthWidget::WhyGutHealthWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WhyGutHealthWidget)
{
    ui->setupUi(this);

    //Add poooing image
    QPixmap pooing = QPixmap::fromImage(QImage(":/sprites/pooing.png"));
    ui->pooingPic->setPixmap(pooing.scaled(ui->pooingPic->size(), Qt::KeepAspectRatio));
    ui->pooingPic->setFrameShape(QFrame::NoFrame);

    //Add sad poo image
    QPixmap sadPoo = QPixmap::fromImage(QImage(":/sprites/hardPoo.png"));
    ui->sadPooPic->setPixmap(sadPoo.scaled(ui->sadPooPic->size(), Qt::KeepAspectRatio));
    ui->sadPooPic->setFrameShape(QFrame::NoFrame);

    // Set the background color
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor(238, 223, 242));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    //coonection for the back button
    connect(ui->backToTeachingWidgetButton, &QPushButton::clicked, this,&WhyGutHealthWidget::backToTeachingWidgetButtonClicked);
}


WhyGutHealthWidget::~WhyGutHealthWidget()
{
    delete ui;
}
