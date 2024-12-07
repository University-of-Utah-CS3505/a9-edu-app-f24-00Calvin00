#include "mainwindow.h"
#include <QScreen>

MainWindow::MainWindow(QWidget *parent, QuizModel *QuizModel)
    : QMainWindow(parent), quizModel(QuizModel)
{
    // Set window size
    this->resize(800, 600);

    // Create and set up the stacked widget
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    // Create and add widgets for different sections
    startWidget = new StartWidget(this);
    stackedWidget->addWidget(startWidget);

    quizzingHomeWidget = new QuizzingHomeWidget(this, quizModel);
    stackedWidget->addWidget(quizzingHomeWidget);

    quizMatchingWidget = new QuizMatchingWidget(this, quizModel);
    stackedWidget->addWidget(quizMatchingWidget);

    quizDragDropWidget = new QuizDragDropWidget(this, quizModel);
    stackedWidget->addWidget(quizDragDropWidget);

    resultsWidget = new ResultsWidget(this);
    stackedWidget->addWidget(resultsWidget);

    teachingWidget = new TeachingWidget(this);
    stackedWidget->addWidget(teachingWidget);

    introToGutHealthWidget = new IntroToGutHealthWidget(this);
    stackedWidget->addWidget(introToGutHealthWidget);

    whyGutHealthWidget = new WhyGutHealthWidget(this);
    stackedWidget->addWidget(whyGutHealthWidget);

    howToStayHealthyWidget = new HowToStayHealthyWidget(this);
    stackedWidget->addWidget(howToStayHealthyWidget);

    // Set up signal-slot connections for navigation
    connect(startWidget, &StartWidget::learnButtonClicked, this, &MainWindow::showTeachingWidget);
    connect(teachingWidget, &TeachingWidget::introToGutButtonClicked, this, &MainWindow::showIntroToGutHealthWidget);
    connect(teachingWidget, &TeachingWidget::whyGutHealthButtonClicked, this, &MainWindow::showWhyGutHealthWidget);
    connect(teachingWidget, &TeachingWidget::howToStayHealthyButtonClicked, this, &MainWindow::showHowToStayHealthyWidget);
    connect(teachingWidget, &TeachingWidget::backToStartButtonClicked, this, &MainWindow::showStartWidget);
    connect(introToGutHealthWidget, &IntroToGutHealthWidget::backToTeachingWidgetButtonClicked, this, &MainWindow::showTeachingWidget);
    connect(whyGutHealthWidget, &WhyGutHealthWidget::backToTeachingWidgetButtonClicked, this, &MainWindow::showTeachingWidget);
    connect(howToStayHealthyWidget, &HowToStayHealthyWidget::backToTeachingWidgetButtonClicked, this, &MainWindow::showTeachingWidget);

    connect(startWidget, &StartWidget::quizButtonClicked, this, &MainWindow::showQuizzingWidget);
    connect(quizzingHomeWidget, &QuizzingHomeWidget::matchingButtonClicked, this, &MainWindow::showMatchingWidget);
    connect(quizzingHomeWidget, &QuizzingHomeWidget::dragDropButtonClicked, this, &MainWindow::showDragDropWidget);
    connect(quizzingHomeWidget, &QuizzingHomeWidget::backToStartButtonClicked, this, &MainWindow::showStartWidget);
    connect(quizMatchingWidget, &QuizMatchingWidget::backToQuizHomeButtonClicked, this, &MainWindow::showQuizzingWidget);
    connect(quizDragDropWidget, &QuizDragDropWidget::backToQuizHomeButtonClicked, this, &MainWindow::showQuizzingWidget);

    connect(startWidget, &StartWidget::resultsButtonClicked, this, &MainWindow::showResultsWidget);
    connect(resultsWidget, &ResultsWidget::backToStartButtonClicked, this, &MainWindow::showStartWidget);

    // Set initial widget to show as the starting point
    stackedWidget->setCurrentWidget(startWidget);
}

MainWindow::~MainWindow()
{
}

/** Slots to switch between different widgets */
void MainWindow::showStartWidget() {
    stackedWidget->setCurrentWidget(startWidget);
}

void MainWindow::showTeachingWidget() {
    stackedWidget->setCurrentWidget(teachingWidget);
}

void MainWindow::showQuizzingWidget() {
    stackedWidget->setCurrentWidget(quizzingHomeWidget);
}

void MainWindow::showMatchingWidget() {
    stackedWidget->setCurrentWidget(quizMatchingWidget);
}

void MainWindow::showDragDropWidget() {
    stackedWidget->setCurrentWidget(quizDragDropWidget);
}

void MainWindow::showResultsWidget() {
    stackedWidget->setCurrentWidget(resultsWidget);
}

void MainWindow::showIntroToGutHealthWidget() {
    stackedWidget->setCurrentWidget(introToGutHealthWidget);
}

void MainWindow::showWhyGutHealthWidget() {
    stackedWidget->setCurrentWidget(whyGutHealthWidget);
}

void MainWindow::showHowToStayHealthyWidget() {
    stackedWidget->setCurrentWidget(howToStayHealthyWidget);
}

