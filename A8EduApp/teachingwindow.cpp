#include "TeachingWindow.h"
#include "ui_TeachingWindow.h"

TeachingWindow::TeachingWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TeachingWindow)
{
    ui->setupUi(this);
}

TeachingWindow::~TeachingWindow()
{
    delete ui;
}
