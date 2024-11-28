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


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, QuizModel *quizModel = nullptr);
    ~MainWindow();

private:
    QStackedWidget *stackedWidget;
    StartWidget *startWidget;
    TeachingWidget *teachingWidget;
    QuizzingHomeWidget *quizzingHomeWidget;
    QuizDragDropWidget *quizDragDropWidget;
    QuizMatchingWidget *quizMatchingWidget;
    ResultsWidget *resultsWidget;
    IntroToGutHealthWidget *introToGutHealthWidget;
    WhyGutHealthWidget *whyGutHealthWidget;
    HowToStayHealthyWidget *howToStayHealthyWidget;
    QuizModel *quizModel;  // Quiz model to manage questions and scores


private slots:
    void showStartWidget();
    void showTeachingWidget();
    void showQuizzingWidget();
    void showResultsWidget();
    void showMatchingWidget();
    void showDragDropWidget();
    void showIntroToGutHealthWidget();
    void showWhyGutHealthWidget();
    void showHowToStayHealthyWidget();
};

#endif // MAINWINDOW_H
