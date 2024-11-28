#ifndef HOWTOSTAYHEALTHYWIDGET_H
#define HOWTOSTAYHEALTHYWIDGET_H

#include <QWidget>

namespace Ui {
class HowToStayHealthyWidget;
}

class HowToStayHealthyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HowToStayHealthyWidget(QWidget *parent = nullptr);
    ~HowToStayHealthyWidget();

signals:
    void backToTeachingWidgetButtonClicked();

private:
    Ui::HowToStayHealthyWidget *ui;
};

#endif // HOWTOSTAYHEALTHYWIDGET_H
