#ifndef INTROTOGUTHEALTHWIDGET_H
#define INTROTOGUTHEALTHWIDGET_H

#include <QWidget>

namespace Ui {
class IntroToGutHealthWidget;
}

class IntroToGutHealthWidget : public QWidget
{
    Q_OBJECT

public:
    explicit IntroToGutHealthWidget(QWidget *parent = nullptr);
    ~IntroToGutHealthWidget();

private:
    Ui::IntroToGutHealthWidget *ui;
};

#endif // INTROTOGUTHEALTHWIDGET_H
