#ifndef WHYGUTHEALTHWIDGET_H
#define WHYGUTHEALTHWIDGET_H

#include <QWidget>

namespace Ui {
class WhyGutHealthWidget;
}

class WhyGutHealthWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WhyGutHealthWidget(QWidget *parent = nullptr);
    ~WhyGutHealthWidget();

signals:
    void backToTeachingWidgetButtonClicked();

private:
    Ui::WhyGutHealthWidget *ui;
};

#endif // WHYGUTHEALTHWIDGET_H
