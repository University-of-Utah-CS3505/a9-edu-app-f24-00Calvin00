#include "teachingwidget.h"
#include "ui_teachingwidget.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDebug>

// TeachingWidget Constructor
TeachingWidget::TeachingWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::TeachingWidget)
{
    ui->setupUi(this);

    //Add Gut Image
    QPixmap gutJPEG = QPixmap::fromImage(QImage(":/sprites/gutPic1.jpeg"));
    ui->gut->setPixmap(gutJPEG.scaled(ui->gut->size(), Qt::KeepAspectRatio));

    // Set the background color
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor(238, 223, 242));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    // Connect buttons to their respective slots
    connect(ui->introToGutButton, &QPushButton::clicked, this, &TeachingWidget::introToGutButtonClicked);
    connect(ui->whyGutHealthButton, &QPushButton::clicked, this, &TeachingWidget::whyGutHealthButtonClicked);
    connect(ui->howToStayHealthyButton, &QPushButton::clicked, this, &TeachingWidget::howToStayHealthyButtonClicked);
    connect(ui->backToStartButton, &QPushButton::clicked, this, &TeachingWidget::backToStartButtonClicked);
}

// TeachingWidget Destructor
TeachingWidget::~TeachingWidget()
{
    delete ui;
}
