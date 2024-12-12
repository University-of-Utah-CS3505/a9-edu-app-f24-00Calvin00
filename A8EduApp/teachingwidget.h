#ifndef TEACHINGWIDGET_H
#define TEACHINGWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <introtoguthealthwidget.h>
#include <whyguthealthwidget.h>
#include <howtostayhealthywidget.h>

namespace Ui {
class TeachingWidget;
}

class TeachingWidget : public QWidget {
    Q_OBJECT

public:
    explicit TeachingWidget(QWidget *parent = nullptr);
    ~TeachingWidget();

private:
    Ui::TeachingWidget *ui;
    IntroToGutHealthWidget *introToGutHealthWidget;
    WhyGutHealthWidget *whyGutHealthWidget;
    HowToStayHealthyWidget *howToStayHealthyWidget;

signals:
    void introToGutButtonClicked();
    void whyGutHealthButtonClicked();
    void howToStayHealthyButtonClicked();
    void backToStartButtonClicked();
};

#endif // TEACHINGWIDGET_H
