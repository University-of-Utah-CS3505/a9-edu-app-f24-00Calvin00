#ifndef QUIZZINGHOMEWIDGET_H
#define QUIZZINGHOMEWIDGET_H

#include <QWidget>
#include "quizmodel.h"

namespace Ui {
class QuizzingHomeWidget;
}

class QuizzingHomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuizzingHomeWidget(QWidget *parent = nullptr, QuizModel *quizModel = nullptr);
    ~QuizzingHomeWidget();

signals:
    void matchingButtonClicked();
    void dragDropButtonClicked();
    void backToStartButtonClicked();

private:
    Ui::QuizzingHomeWidget *ui;
    QuizModel *quizModel;
};

#endif // QUIZZINGHOMEWIDGET_H
