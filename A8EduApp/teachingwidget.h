#ifndef TEACHINGWIDGET_H
#define TEACHINGWIDGET_H

#include <QWidget>
#include <introtoguthealthwidget.h>

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

signals:
    void introToGutButtonClicked();
};

#endif // TEACHINGWIDGET_H
