#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<teachingwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class TeachingWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openTeachingWindow();

private:
    Ui::MainWindow *ui;
    TeachingWindow *teachingWindow;
};
#endif // MAINWINDOW_H
