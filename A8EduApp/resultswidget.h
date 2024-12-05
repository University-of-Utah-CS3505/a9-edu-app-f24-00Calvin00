#ifndef RESULTSWIDGET_H
#define RESULTSWIDGET_H

#include <QWidget>
#include <draggablelabel.h>
#include <droplabel.h>

namespace Ui {
class ResultsWidget;
}

class ResultsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ResultsWidget(QWidget *parent = nullptr);
    ~ResultsWidget();

private:
    Ui::ResultsWidget *ui;

signals:
    void backToStartButtonClicked();
};

#endif // RESULTSWIDGET_H
