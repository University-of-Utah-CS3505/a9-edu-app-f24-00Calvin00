#include "resultswidget.h"
#include "ui_resultswidget.h"

ResultsWidget::ResultsWidget(QWidget *parent, QuizModel *quizModel)
    : QWidget(parent)
    , ui(new Ui::ResultsWidget)
    , quizModel(quizModel)
    , mouthValue(0)
{
    ui->setupUi(this);

    QPixmap bananaPNG = QPixmap::fromImage(QImage(":/sprites/normalPoo.png"));
    ui->banana->setPixmap(bananaPNG.scaled(ui->banana->size(), Qt::KeepAspectRatio));
    QPixmap mouthPNG = QPixmap::fromImage(QImage(":/sprites/toilet.png"));
    ui->mouth->setPixmap(mouthPNG.scaled(ui->mouth->size(), Qt::KeepAspectRatio));

    QPixmap pooPixmap = QPixmap::fromImage(QImage(":/sprites/normalPoo.png"));
    ui->poo->setPixmap(pooPixmap.scaled(ui->poo->size(), Qt::KeepAspectRatio));

    // Connect signals
    connect(ui->backToStartButton, &QPushButton::clicked, this, &ResultsWidget::backToStartButtonClicked);

    connect(ui->mouth, &DropLabel::foodDropped, this, [this]() { mouthValue += 5; });
    connect(ui->mouth, &DropLabel::foodDropped, this, &ResultsWidget::onFoodDropped);
    // connect(ui->banana, &DropLabel::foodDropped, this, [this]() { mouthValue += 5; });
    // connect(ui->banana, &DropLabel::foodDropped, this, &ResultsWidget::onFoodDropped);
    // connect(ui->banana, &DropLabel::foodDropped, this, [this]() { mouthValue += 5; });
    // connect(ui->banana, &DropLabel::foodDropped, this, &ResultsWidget::onFoodDropped);
}

ResultsWidget::~ResultsWidget()
{
    delete ui;
    delete quizModel;
    delete pooPixmap;
}

void ResultsWidget::updatePooState(QString imagePath)
{
    QPixmap pooPixmap = QPixmap::fromImage(QImage(imagePath));
    ui->poo->setPixmap(pooPixmap.scaled(ui->poo->size(), Qt::KeepAspectRatio));
}

void ResultsWidget::onFoodDropped()
{
    updatePooState(":/sprites/sadPoo.png");
    // if (mouthValue > -25 && mouthValue <= 25) {
    //     ;
    // } else if (mouthValue > 25 && mouthValue <= 50) {
    //     return "normal";
    // } else if (mouthValue > 50 && mouthValue <= 75) {
    //     return "happy";
    // } else if (mouthValue > 75 && mouthValue <= 125) {
    //     return "liquid";
    // }
    // return "explode";

}


