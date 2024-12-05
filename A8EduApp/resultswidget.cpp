#include "resultswidget.h"
#include "ui_resultswidget.h"

ResultsWidget::ResultsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ResultsWidget)
{
    ui->setupUi(this);

    QPixmap bananaPNG = QPixmap::fromImage(QImage(":/sprites/normalPoo.png"));
    ui->banana->setPixmap(bananaPNG.scaled(ui->banana->size(), Qt::KeepAspectRatio));

    QPixmap mouthPNG = QPixmap::fromImage(QImage(":/sprites/toilet.png"));
    ui->mouth->setPixmap(mouthPNG.scaled(ui->mouth->size(), Qt::KeepAspectRatio));

    QPixmap pooPNG = QPixmap::fromImage(QImage(":/sprites/normalPoo.png"));
    ui->poo->setPixmap(pooPNG.scaled(ui->poo->size(), Qt::KeepAspectRatio));

    // Connect signals
    connect(ui->backToStartButton, &QPushButton::clicked, this, &ResultsWidget::backToStartButtonClicked);
}


ResultsWidget::~ResultsWidget()
{
    delete ui;
}
