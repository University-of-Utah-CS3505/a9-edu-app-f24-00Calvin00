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

    quizzingHomeWidget = new QuizzingHomeWidget(this);
    stackedWidget->addWidget(quizzingHomeWidget);

    quizMatchingWidget = new QuizMatchingWidget(this);
    stackedWidget->addWidget(quizMatchingWidget);

    quizDragDropWidget = new QuizDragDropWidget(this);
    stackedWidget->addWidget(quizDragDropWidget);

    resultsWidget = new ResultsWidget(this);
    stackedWidget->addWidget(resultsWidget);

    // Connect the StartWidget's learnButtonClicked signal to switch to TeachingWidget
    connect(startWidget, &StartWidget::learnButtonClicked, this, &MainWindow::showTeachingWidget);

    // Connect the StartWidget's startButtonClicked signal to switch to TeachingWidget
    connect(startWidget, &StartWidget::quizButtonClicked, this, &MainWindow::showQuizzingWidget);

    // Connect the StartWidget's resultsButtonClicked signal to switch to TeachingWidget
    connect(startWidget, &StartWidget::resultsButtonClicked, this, &MainWindow::showResultsWidget);

    connect(quizzingHomeWidget, &QuizzingHomeWidget::matchingButtonClicked, this, &MainWindow::showMatchingWidget);

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

void MainWindow::showQuizzingWidget()
{
    stackedWidget->setCurrentWidget(quizzingHomeWidget);
}

void MainWindow::showMatchingWidget()
{
    stackedWidget->setCurrentWidget(quizMatchingWidget);
}

void MainWindow::showDragDropWidget()
{
    stackedWidget->setCurrentWidget(quizDragDropWidget);
}

void MainWindow::showResultsWidget()
{
    stackedWidget->setCurrentWidget(resultsWidget);
}

