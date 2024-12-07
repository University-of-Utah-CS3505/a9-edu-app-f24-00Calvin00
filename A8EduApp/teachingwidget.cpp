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

    // Add the logic to load and display an image
    setupImage();
    // // Add the logic to load and display an image
    // setupImageView();
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
// // Method to setup the image in QGraphicsView
// void TeachingWidget::setupImageView()
// {
//     // Check if the QGraphicsView exists
//     if (!ui->graphicsView) {
//         qWarning("QGraphicsView 'imageView' not found in the UI file.");
//         return;
//     }

//     // Create a new QGraphicsScene
//     QGraphicsScene* scene = new QGraphicsScene(ui->graphicsView);

//     // Load the image into a QPixmap
//     QPixmap pixmap(":/../gutPic1.jpeg"); // Replace with the correct resource path or file path
//     if (pixmap.isNull()) {
//         qWarning("Failed to load image!");
//         return;
//     }

//     // Add the pixmap as a QGraphicsPixmapItem to the scene
//     QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(pixmap);
//     scene->addItem(pixmapItem);

//     // Set the scene to the QGraphicsView
//     ui->graphicsView->setScene(scene);

//     // Fit the image to the view while maintaining the aspect ratio
//     ui->graphicsView->fitInView(pixmapItem, Qt::KeepAspectRatio);

//     // Optional: Enable high-quality rendering
//     ui->graphicsView->setRenderHint(QPainter::Antialiasing);
// }
