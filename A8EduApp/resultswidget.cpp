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
    updatePooState(":/sprites/normalPoo.png");

    // Set the pixart and information box
    QPixmap png = QPixmap::fromImage(QImage(":/sprites/mouth.png"));
    ui->mouth->setPixmap(png.scaled(ui->mouth->size(), Qt::KeepAspectRatio));
    ui->mouth->setStyleSheet("background-color: transparent ;");
    ui->mouth->setFrameShape(QFrame::NoFrame);
    ui->information->setHidden(true);
    setFoodImage(ui->banana, ":/sprites/banana.png");
    setFoodImage(ui->meat, ":/sprites/meat.png");
    setFoodImage(ui->pickle, ":/sprites/pickle.png");
    setFoodImage(ui->nut, ":/sprites/nut.png");
    setFoodImage(ui->hotdog, ":/sprites/hotdog.png");
    setFoodImage(ui->icecream, ":/sprites/icecream.png");

    // Set the background color
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor(238, 223, 242));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    // Connect signals
    connect(ui->backToStartButton, &QPushButton::clicked, this, &ResultsWidget::backToStartButtonClicked);
    connect(ui->simulationButton, &QPushButton::clicked, this, &ResultsWidget::toggleSimulation);
    connect(ui->mouth, &DropLabel::foodDropped, this, &ResultsWidget::onFoodDropped);
    connect(ui->banana, &DraggableLabel::mousePressed, this, &ResultsWidget::calculateMouthValue);
    connect(ui->meat, &DraggableLabel::mousePressed, this, &ResultsWidget::calculateMouthValue);
    connect(ui->pickle, &DraggableLabel::mousePressed, this, &ResultsWidget::calculateMouthValue);
    connect(ui->nut, &DraggableLabel::mousePressed, this, &ResultsWidget::calculateMouthValue);
    connect(ui->hotdog, &DraggableLabel::mousePressed, this, &ResultsWidget::calculateMouthValue);
    connect(ui->icecream, &DraggableLabel::mousePressed, this, &ResultsWidget::calculateMouthValue);
}

ResultsWidget::~ResultsWidget()
{
    delete ui;
    delete quizModel;
    delete gif;
}

void ResultsWidget::setFoodImage(QLabel* label, const QString& imagePath)
{
    QPixmap png = QPixmap::fromImage(QImage(imagePath));
    label->setPixmap(png.scaled(label->size(), Qt::KeepAspectRatio));
    label->setFrameShape(QFrame::NoFrame);
}

void ResultsWidget::setInformationText(const QString& text)
{
    ui->information->setFontPointSize(10);
    ui->information->setText(text);
    ui->information->setAlignment(Qt::AlignCenter);
}

void ResultsWidget::toggleSimulation()
{
    if (ui->conclusion->isHidden()) {
        ui->simulationButton->setText("Simulation");
        ui->conclusion->setHidden(false);
        ui->information->setHidden(true);
    } else {
        ui->simulationButton->setText("Summary");
        ui->conclusion->setHidden(true);
        ui->information->setHidden(false);
    }
}

void ResultsWidget::calculateMouthValue(const QString &food)
{
    if (food == "banana") {
        mouthValue += 15;
    } else if (food == "meat") {
        mouthValue -= 20;
    } else if (food == "pickle") {
        mouthValue += 10;
    } else if (food == "nut"){
        mouthValue -= 5;
    } else if (food == "hotdog"){
        mouthValue -= 35;
    } else if (food == "icecream"){
        mouthValue += 30;
    }
}

void ResultsWidget::onFoodDropped()
{
    if (mouthValue > -25 && mouthValue <= 25) {
        updatePooState(":/sprites/hardPoo.png");
        setInformationText("Uh oh... constipation. Try eating more fiber or dairy.");
    } else if (mouthValue > 25 && mouthValue <= 50) {
        updatePooState(":/sprites/normalPoo.png");
        setInformationText("Not bad... but could be better. Try eating more acid.");
    } else if (mouthValue > 50 && mouthValue <= 75) {
        updatePooState(":/sprites/happyPoo.png");
        setInformationText("Nice job, it's the perfect consistency! Now's the time to experiment.");
    } else if (mouthValue > 75 && mouthValue <= 125) {
        updatePooState(":/sprites/liquidPoo.png", Qt::AlignBottom, false);
        setInformationText("Uh oh... diarrhea! Try eating more carbs or fat.");
    } else {
        // Make the poo explode
        ui->poo->clear();
        gif->start();
        setInformationText("Oh no, you've burst! Now's the time to experiment.");
    }
}

void ResultsWidget::updatePooState(QString imagePath, Qt::Alignment alignment, bool scale)
{
    QPixmap pooPixmap = QPixmap::fromImage(QImage(imagePath));

    // Apply scaling only if requested
    if (scale) {
        pooPixmap = pooPixmap.scaled(ui->poo->size(), Qt::KeepAspectRatio);
    }

    ui->poo->setPixmap(pooPixmap);
    ui->poo->setAlignment(alignment);
}
