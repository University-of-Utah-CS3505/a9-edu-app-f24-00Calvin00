#ifndef TEACHINGWIDGET_H
#define TEACHINGWIDGET_H

#include <QWidget>

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
};

#endif // TEACHINGWIDGET_H
