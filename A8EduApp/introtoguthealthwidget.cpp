#include "introtoguthealthwidget.h"
#include "ui_introtoguthealthwidget.h"

IntroToGutHealthWidget::IntroToGutHealthWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IntroToGutHealthWidget)
{
    ui->setupUi(this);

    //Add mouth images
    QPixmap mouth = QPixmap::fromImage(QImage(":/sprites/mouth.png"));
    ui->mouthPic->setPixmap(mouth.scaled(ui->mouthPic->size(), Qt::KeepAspectRatio));
    ui->mouthPic->setFrameShape(QFrame::NoFrame);
    QPixmap mouth2 = QPixmap::fromImage(QImage(":/sprites/mouth.png"));
    ui->mouthPic_2->setPixmap(mouth2.scaled(ui->mouthPic_2->size(), Qt::KeepAspectRatio));
    ui->mouthPic_2->setFrameShape(QFrame::NoFrame);

    //Add poop images
    QPixmap poop1 = QPixmap::fromImage(QImage(":/sprites/normalPoo.png"));
    ui->poo1->setPixmap(poop1.scaled(ui->poo1->size(), Qt::KeepAspectRatio));
    ui->poo1->setFrameShape(QFrame::NoFrame);
    QPixmap poop2 = QPixmap::fromImage(QImage(":/sprites/normalPoo.png"));
    ui->poo2->setPixmap(poop2.scaled(ui->poo2->size(), Qt::KeepAspectRatio));
    ui->poo2->setFrameShape(QFrame::NoFrame);

    // Set the background color
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor(238, 223, 242));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    //coonection for the back button
    connect(ui->backToTeachingWidgetButton, &QPushButton::clicked, this, &IntroToGutHealthWidget::backToTeachingWidgetButtonClicked);
}

IntroToGutHealthWidget::~IntroToGutHealthWidget()
{
    delete ui;
}
