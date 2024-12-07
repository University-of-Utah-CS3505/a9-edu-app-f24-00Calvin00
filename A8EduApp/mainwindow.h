#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "startwidget.h"
#include "teachingwidget.h"
#include "quizdragdropwidget.h"
#include "quizmatchingwidget.h"
#include "quizzinghomewidget.h"
#include "resultswidget.h"
#include "introtoguthealthwidget.h"
#include "whyguthealthwidget.h"
#include "howtostayhealthywidget.h"
#include "quizmodel.h"

/**
 * @class MainWindow
 * @brief The main window of the application that manages and displays different widgets for learning, quizzes, and results.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief Constructs a MainWindow instance.
     * @param parent The parent widget, default is nullptr.
     * @param quizModel A pointer to a QuizModel instance for managing quiz data, default is nullptr.
     */
    explicit MainWindow(QWidget *parent = nullptr, QuizModel *quizModel = nullptr);
    ~MainWindow();

private:
    QStackedWidget *stackedWidget; // A stacked widget to manage different pages.
    StartWidget *startWidget; // Widget for the start screen.
    TeachingWidget *teachingWidget; // Widget for teaching content.
    QuizzingHomeWidget *quizzingHomeWidget; // Widget for the quiz home screen.
    QuizDragDropWidget *quizDragDropWidget; // Widget for the drag-and-drop quiz.
    QuizMatchingWidget *quizMatchingWidget; // Widget for the matching quiz.
    ResultsWidget *resultsWidget; // Widget for displaying quiz results.
    IntroToGutHealthWidget *introToGutHealthWidget; // Widget for introductory gut health information.
    WhyGutHealthWidget *whyGutHealthWidget; // Widget explaining the importance of gut health.
    HowToStayHealthyWidget *howToStayHealthyWidget; // Widget on maintaining health.
    QuizModel *quizModel; // The model used to manage quiz data, questions, and scores.

private slots:
    /**
     * @brief Slot to show the start widget.
     */
    void showStartWidget();

    /**
     * @brief Slot to show the teaching widget.
     */
    void showTeachingWidget();

    /**
     * @brief Slot to show the quiz home widget.
     */
    void showQuizzingWidget();

    /**
     * @brief Slot to show the quiz matching widget.
     */
    void showMatchingWidget();

    /**
     * @brief Slot to show the quiz drag-and-drop widget.
     */
    void showDragDropWidget();

    /**
     * @brief Slot to show the results widget.
     */
    void showResultsWidget();

    /**
     * @brief Slot to show the 'Intro To Gut Health' widget.
     */
    void showIntroToGutHealthWidget();

    /**
     * @brief Slot to show the 'Why Gut Health' widget.
     */
    void showWhyGutHealthWidget();

    /**
     * @brief Slot to show the 'How to Stay Healthy' widget.
     */
    void showHowToStayHealthyWidget();
};

#endif // MAINWINDOW_H
