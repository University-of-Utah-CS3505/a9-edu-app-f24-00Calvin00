#ifndef QUIZDRAGDROPWIDGET_H
#define QUIZDRAGDROPWIDGET_H

#include <QWidget>

namespace Ui {
class QuizDragDropWidget;
}

class QuizDragDropWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuizDragDropWidget(QWidget *parent = nullptr);
    ~QuizDragDropWidget();

signals:

private:
    Ui::QuizDragDropWidget *ui;
};

#endif // QUIZDRAGDROPWIDGET_H
