#ifndef TEACHINGWIDGET_H
#define TEACHINGWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
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

protected:
    void paintEvent(QPaintEvent *event) override; // Add paintEvent for custom rendering

private:
    Ui::TeachingWidget *ui;
    IntroToGutHealthWidget *introToGutHealthWidget;
    WhyGutHealthWidget *whyGutHealthWidget;
    HowToStayHealthyWidget *howToStayHealthyWidget;

    QImage image;  // Image to be displayed

    void setupImage(); // Method to load the image

signals:
    void introToGutButtonClicked();
    void whyGutHealthButtonClicked();
    void howToStayHealthyButtonClicked();
    void backToStartButtonClicked();
};

#endif // TEACHINGWIDGET_H
