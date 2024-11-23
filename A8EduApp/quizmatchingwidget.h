#ifndef QUIZMATCHINGWIDGET_H
#define QUIZMATCHINGWIDGET_H

#include <QWidget>

namespace Ui {
class QuizMatchingWidget;
}

class QuizMatchingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuizMatchingWidget(QWidget *parent = nullptr);
    ~QuizMatchingWidget();

signals:

private:
    Ui::QuizMatchingWidget *ui;
};

#endif // QUIZMATCHINGWIDGET_H
