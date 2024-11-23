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

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QStackedWidget *stackedWidget;
    StartWidget *startWidget;
    TeachingWidget *teachingWidget;
    QuizzingHomeWidget *quizzingHomeWidget;
    QuizDragDropWidget *quizDragDropWidget;
    QuizMatchingWidget *quizMatchingWidget;
    ResultsWidget *resultsWidget;


private slots:
    void showTeachingWidget();
    void showQuizzingWidget();
    void showResultsWidget();
    void showMatchingWidget();
    void showDragDropWidget();
};

#endif // MAINWINDOW_H
