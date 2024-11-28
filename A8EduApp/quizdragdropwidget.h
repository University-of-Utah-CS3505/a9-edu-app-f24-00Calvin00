#ifndef QUIZDRAGDROPWIDGET_H
#define QUIZDRAGDROPWIDGET_H

#include <QWidget>
#include "quizmodel.h"

namespace Ui {
class QuizDragDropWidget;
}

class QuizDragDropWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuizDragDropWidget(QWidget *parent = nullptr, QuizModel *quizModel = nullptr);
    ~QuizDragDropWidget();

signals:
    void showQuizzingHomeWidget();

private:
    Ui::QuizDragDropWidget *ui;
    QuizModel *quizModel;

};

#endif // QUIZDRAGDROPWIDGET_H
