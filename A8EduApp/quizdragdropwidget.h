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
    void backToQuizHomeButtonClicked();

private slots:
    void onAnswerDropped(const QString &question, const QString &answer);
    void onSubmitClicked();

private:
    Ui::QuizDragDropWidget *ui;
    QuizModel *quizModel;
    QMap<QString, QString> userAnswers;

};

#endif // QUIZDRAGDROPWIDGET_H
