#include "resultswidget.h"
#include "ui_resultswidget.h"

ResultsWidget::ResultsWidget(QWidget *parent, QuizModel *quizModel)
    : QWidget(parent)
    , ui(new Ui::ResultsWidget)
    , quizModel(quizModel)
    , gif(new QMovie(":/gifs/explosion.gif"))
    , mouthValue(0)
{
    ui->setupUi(this);
    ui->explosion->setMovie(gif);

    QPixmap bananaPNG = QPixmap::fromImage(QImage(":/sprites/banana.png"));
    ui->banana->setPixmap(bananaPNG.scaled(ui->banana->size(), Qt::KeepAspectRatio));
    ui->banana->setFrameShape(QFrame::NoFrame);
    QPixmap mouthPNG = QPixmap::fromImage(QImage(":/sprites/toilet.png"));
    ui->mouth->setPixmap(mouthPNG.scaled(ui->mouth->size(), Qt::KeepAspectRatio));

    updatePooState(":/sprites/normalPoo.png");

    // Connect signals
    connect(ui->backToStartButton, &QPushButton::clicked, this, &ResultsWidget::backToStartButtonClicked);
    connect(ui->mouth, &DropLabel::foodDropped, this, &ResultsWidget::onFoodDropped);
    connect(ui->banana, &DraggableLabel::mousePressed, this, &ResultsWidget::calculateMouthValue);
}

ResultsWidget::~ResultsWidget()
{
    delete ui;
    delete quizModel;
    delete gif;
}

void ResultsWidget::calculateMouthValue(const QString &food)
{
    if (food == "banana") {
        mouthValue += 5;
    } else if (food == "banana") {
        mouthValue += -5;
    } else if (food == "banana") {
        mouthValue += 5;
    // } else if (){

    }
}

void ResultsWidget::onFoodDropped()
{
    if (mouthValue > -25 && mouthValue <= 25) {
        updatePooState(":/sprites/hardPoo.png");
    } else if (mouthValue > 25 && mouthValue <= 50) {
        updatePooState(":/sprites/normalPoo.png");
    } else if (mouthValue > 50 && mouthValue <= 75) {
        updatePooState(":/sprites/happyPoo.png");
    } else if (mouthValue > 75 && mouthValue <= 125) {
        updatePooState(":/sprites/liquidPoo.png");
    } else {
        gif->start();
    }
}

void ResultsWidget::updatePooState(QString imagePath)
{
    QPixmap pooPixmap = QPixmap::fromImage(QImage(imagePath));
    ui->poo->setPixmap(pooPixmap.scaled(ui->poo->size(), Qt::KeepAspectRatio));
    ui->poo->setAlignment(Qt::AlignRight);
}
