#include "mainwindow.h"
#include <QScreen>

MainWindow::MainWindow(QWidget *parent, QuizModel *QuizModel)
    : QMainWindow(parent), quizModel(QuizModel)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    // Set window size 3/4ths the screen size
    this->resize(screenGeometry.width() / 1.75, screenGeometry.height() / 1.75);

    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget); // StackedWidget as central widget

    // Create StartWidget and add it to the QStackedWidget
    startWidget = new StartWidget(this);
    stackedWidget->addWidget(startWidget);

    //Create quiz widgets/windows
    quizzingHomeWidget = new QuizzingHomeWidget(this, quizModel);
    stackedWidget->addWidget(quizzingHomeWidget);

    quizMatchingWidget = new QuizMatchingWidget(this, quizModel);
    stackedWidget->addWidget(quizMatchingWidget);

    quizDragDropWidget = new QuizDragDropWidget(this, quizModel);
    stackedWidget->addWidget(quizDragDropWidget);

    //Create result widgets/windows
    resultsWidget = new ResultsWidget(this);
    stackedWidget->addWidget(resultsWidget);


    // Create all teaching widget/windows
    teachingWidget = new TeachingWidget(this);
    stackedWidget->addWidget(teachingWidget);

    introToGutHealthWidget = new IntroToGutHealthWidget(this);
    stackedWidget->addWidget(introToGutHealthWidget);

    whyGutHealthWidget = new WhyGutHealthWidget(this);
    stackedWidget->addWidget(whyGutHealthWidget);

    howToStayHealthyWidget = new HowToStayHealthyWidget(this);
    stackedWidget->addWidget(howToStayHealthyWidget);


    // Connections for Learning modules
    connect(startWidget, &StartWidget::learnButtonClicked, this, &MainWindow::showTeachingWidget);\
    connect(teachingWidget, &TeachingWidget::introToGutButtonClicked, this, &MainWindow::showIntroToGutHealthWidget);
    connect(teachingWidget, &TeachingWidget::whyGutHealthButtonClicked, this, &MainWindow::showWhyGutHealthWidget);
    connect(teachingWidget, &TeachingWidget::howToStayHealthyButtonClicked, this, &MainWindow::showHowToStayHealthyWidget);
    connect(teachingWidget, &TeachingWidget::backToStartButtonClicked, this, &MainWindow::showStartWidget);
    connect(introToGutHealthWidget, &IntroToGutHealthWidget::backToTeachingWidgetButtonClicked, this, &MainWindow::showTeachingWidget);
    connect(whyGutHealthWidget, &WhyGutHealthWidget::backToTeachingWidgetButtonClicked, this, &MainWindow::showTeachingWidget);
    connect(howToStayHealthyWidget, &HowToStayHealthyWidget::backToTeachingWidgetButtonClicked, this, &MainWindow::showTeachingWidget);

    // Connections for the quiz tab
    connect(startWidget, &StartWidget::quizButtonClicked, this, &MainWindow::showQuizzingWidget);
    connect(quizzingHomeWidget, &QuizzingHomeWidget::matchingButtonClicked, this, &MainWindow::showMatchingWidget);
    connect(quizzingHomeWidget, &QuizzingHomeWidget::dragDropButtonClicked, this, &MainWindow::showDragDropWidget);
    connect(quizzingHomeWidget, &QuizzingHomeWidget::backToStartButtonClicked, this, &MainWindow::showStartWidget);

    // Connections for the result tab
    connect(startWidget, &StartWidget::resultsButtonClicked, this, &MainWindow::showResultsWidget);
    connect(resultsWidget, &ResultsWidget::backToStartButtonClicked, this, &MainWindow::showStartWidget);

    // Set start widget as first page
    stackedWidget->setCurrentWidget(startWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::showStartWidget()
{
    stackedWidget->setCurrentWidget(startWidget);
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

void MainWindow::showIntroToGutHealthWidget()
{
    stackedWidget->setCurrentWidget(introToGutHealthWidget);
}

void MainWindow::showWhyGutHealthWidget()
{
    stackedWidget->setCurrentWidget(whyGutHealthWidget);
}

void MainWindow::showHowToStayHealthyWidget()
{
    stackedWidget->setCurrentWidget(howToStayHealthyWidget);
}

