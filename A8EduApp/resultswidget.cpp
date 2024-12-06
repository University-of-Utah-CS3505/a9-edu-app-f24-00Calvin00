#include "resultswidget.h"
#include "ui_resultswidget.h"

ResultsWidget::ResultsWidget(QWidget *parent, QuizModel *quizModel)
    : QWidget(parent)
    , ui(new Ui::ResultsWidget)
    , quizModel(quizModel)
    , gif(new QMovie(":/gifs/explosion.gif"))
    , mouthValue(37)
{
    ui->setupUi(this);
    ui->explosion->setMovie(gif);

    QPixmap png = QPixmap::fromImage(QImage(":/sprites/mouth.png"));
    ui->mouth->setPixmap(png.scaled(ui->mouth->size(), Qt::KeepAspectRatio));
    ui->mouth->setFrameShape(QFrame::NoFrame);

    png = QPixmap::fromImage(QImage(":/sprites/banana.png"));
    ui->banana->setPixmap(png.scaled(ui->banana->size(), Qt::KeepAspectRatio));
    ui->banana->setFrameShape(QFrame::NoFrame);

    updatePooState(":/sprites/normalPoo.png");

    // Connect signals
    connect(ui->backToStartButton, &QPushButton::clicked, this, &ResultsWidget::backToStartButtonClicked);
    connect(ui->simulationButton, &QPushButton::clicked, this, &ResultsWidget::simulationToggle);
    connect(ui->mouth, &DropLabel::foodDropped, this, &ResultsWidget::onFoodDropped);
    connect(ui->banana, &DraggableLabel::mousePressed, this, &ResultsWidget::calculateMouthValue);
}

ResultsWidget::~ResultsWidget()
{
    delete ui;
    delete quizModel;
    delete gif;
}

void ResultsWidget::simulationToggle()
{
    if (ui->textBrowser->isHidden()) {
        ui->simulationButton->setText("Simulation");
        ui->textBrowser->setHidden(false);
    } else {
        ui->simulationButton->setText("Summary");
        ui->textBrowser->setHidden(true);
    }
}

void ResultsWidget::calculateMouthValue(const QString &food)
{
    if (food == "banana") {
        mouthValue += 7;
    } else if (food == "meat") {
        mouthValue -= 15;
    } else if (food == "pickle") {
        mouthValue += 10;
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
