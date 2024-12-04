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

    // Connect buttons to their respective slots
    connect(ui->introToGutButton, &QPushButton::clicked, this, &TeachingWidget::introToGutButtonClicked);
    connect(ui->whyGutHealthButton, &QPushButton::clicked, this, &TeachingWidget::whyGutHealthButtonClicked);
    connect(ui->howToStayHealthyButton, &QPushButton::clicked, this, &TeachingWidget::howToStayHealthyButtonClicked);
    connect(ui->backToStartButton, &QPushButton::clicked, this, &TeachingWidget::backToStartButtonClicked);

    // Add the logic to load and display an image
    setupImageView();
}

// TeachingWidget Destructor
TeachingWidget::~TeachingWidget()
{
    delete ui;
}

// Method to setup the image in QGraphicsView
void TeachingWidget::setupImageView()
{
    // Check if the QGraphicsView exists
    if (!ui->graphicsView) {
        qWarning("QGraphicsView 'imageView' not found in the UI file.");
        return;
    }

    // Create a new QGraphicsScene
    QGraphicsScene* scene = new QGraphicsScene(ui->graphicsView);

    // Load the image into a QPixmap
    QPixmap pixmap(":/../gutPic1.jpeg"); // Replace with the correct resource path or file path
    if (pixmap.isNull()) {
        qWarning("Failed to load image!");
        return;
    }

    // Add the pixmap as a QGraphicsPixmapItem to the scene
    QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(pixmap);
    scene->addItem(pixmapItem);

    // Set the scene to the QGraphicsView
    ui->graphicsView->setScene(scene);

    // Fit the image to the view while maintaining the aspect ratio
    ui->graphicsView->fitInView(pixmapItem, Qt::KeepAspectRatio);

    // Optional: Enable high-quality rendering
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}
