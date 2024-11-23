#ifndef QUIZZINGHOMEWIDGET_H
#define QUIZZINGHOMEWIDGET_H

#include <QWidget>

namespace Ui {
class QuizzingHomeWidget;
}

class QuizzingHomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuizzingHomeWidget(QWidget *parent = nullptr);
    ~QuizzingHomeWidget();

signals:
    void matchingButtonClicked();
    void dragDropButtonClicked();

private:
    Ui::QuizzingHomeWidget *ui;
};

#endif // QUIZZINGHOMEWIDGET_H
