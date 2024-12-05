#include "teachingwidget.h"
#include "ui_teachingwidget.h"
#include <QPainter>
#include <QImage>
#include <QDebug>

// TeachingWidget Constructor
TeachingWidget::TeachingWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::TeachingWidget)
{
    ui->setupUi(this);

    // Connect buttons to their respective slots
    connect(ui->introToGutButton, &QPushButton::clicked, this, &TeachingWidget::introToGutButtonClicked);
    connect(ui->whyGutHealthButton, &QPushButton::clicked, this, &TeachingWidget::whyGutHealthButtonClicked);
    connect(ui->howToStayHealthyButton, &QPushButton::clicked, this, &TeachingWidget::howToStayHealthyButtonClicked);
    connect(ui->backToStartButton, &QPushButton::clicked, this, &TeachingWidget::backToStartButtonClicked);

    // Add the logic to load and display an image
    setupImage();
}

// TeachingWidget Destructor
TeachingWidget::~TeachingWidget()
{
    delete ui;
}

// Method to load the image
void TeachingWidget::setupImage()
{
    // Load the image into the QImage object
    image = QImage(":/gutPic1.jpeg"); // Make sure to use the correct resource path

    if (image.isNull()) {
        qWarning("Failed to load image!");
    }
}

// Custom paintEvent to draw the image using QPainter
void TeachingWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Check if the image is valid
    if (!image.isNull()) {
        // Draw the image centered in the widget
        QRect targetRect(0, 0, width(), height());
        QRect sourceRect(0, 0, image.width(), image.height());
        painter.drawImage(targetRect, image, sourceRect);
    }

    // Optional: Enable high-quality rendering
    painter.setRenderHint(QPainter::Antialiasing);

    // End the painting
    painter.end();
}
