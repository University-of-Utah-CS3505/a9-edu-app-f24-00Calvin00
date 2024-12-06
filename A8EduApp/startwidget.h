#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>
#include <QMovie>

namespace Ui {
class StartWidget;
}

class StartWidget : public QWidget {
    Q_OBJECT

public:
    explicit StartWidget(QWidget *parent = nullptr);
    ~StartWidget();


signals:
    void learnButtonClicked();
    void quizButtonClicked();
    void resultsButtonClicked();

private:
    Ui::StartWidget *ui;
    QMovie *gif;
};

#endif // STARTWIDGET_H
