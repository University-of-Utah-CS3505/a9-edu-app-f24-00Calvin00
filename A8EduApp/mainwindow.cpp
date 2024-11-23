#include "mainwindow.h"
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    // Set window size half the screen size
    this->resize(screenGeometry.width() / 2, screenGeometry.height() / 2);

    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget); // StackedWidget as central widget

    // Create StartWidget and add it to the QStackedWidget
    startWidget = new StartWidget(this);
    stackedWidget->addWidget(startWidget);

    // Create TeachingWidget and add it to the QStackedWidget
    teachingWidget = new TeachingWidget(this);
    stackedWidget->addWidget(teachingWidget);

    // Connect the StartWidget's startButtonClicked signal to switch to TeachingWidget
    connect(startWidget, &StartWidget::startButtonClicked, this, &MainWindow::showTeachingWidget);

    // Set start widget as first page
    stackedWidget->setCurrentWidget(startWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::showTeachingWidget()
{
    stackedWidget->setCurrentWidget(teachingWidget);
}

