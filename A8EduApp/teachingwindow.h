#ifndef TEACHINGWINDOW_H
#define TEACHINGWINDOW_H

#include <QMainWindow>

namespace Ui {
class TeachingWindow;
}

class TeachingWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit TeachingWindow(QWidget *parent = nullptr);
    ~TeachingWindow();

private:
    Ui::TeachingWindow *ui;

    // Add private methods or member variables specific to TeachingWindow
};

#endif // TEACHINGWINDOW_H
