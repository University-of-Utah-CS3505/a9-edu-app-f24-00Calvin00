#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>

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
};

#endif // STARTWIDGET_H
