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

protected:
    void showEvent(QShowEvent *event) override; // Declare showEvent here

signals:
    void matchingButtonClicked();
    void dragDropButtonClicked();
    void backToStartButtonClicked();

private:
    Ui::QuizzingHomeWidget *ui;
    QuizModel *quizModel;

    void updateScoreLabel();
};

#endif // QUIZZINGHOMEWIDGET_H
