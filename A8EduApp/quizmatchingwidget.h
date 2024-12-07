#ifndef QUIZMATCHINGWIDGET_H
#define QUIZMATCHINGWIDGET_H

#include <QWidget>
#include "quizmodel.h"

namespace Ui {
class QuizMatchingWidget;
}

class QuizMatchingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuizMatchingWidget(QWidget *parent = nullptr, QuizModel *quizModel = nullptr);
    ~QuizMatchingWidget();

signals:
    void backToQuizHomeButtonClicked();

private slots:
    void onSubmitClicked();

private:
    Ui::QuizMatchingWidget *ui;
    QuizModel *quizModel;
//    QMap<QString, int> userAnswers;
};

#endif // QUIZMATCHINGWIDGET_H
