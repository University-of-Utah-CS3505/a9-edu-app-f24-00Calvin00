#include "TeachingWindow.h"
#include "ui_TeachingWindow.h"

TeachingWindow::TeachingWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TeachingWindow)
{
    ui->setupUi(this);

    // Set up the teaching content here, e.g., animations or pop-ups
}

TeachingWindow::~TeachingWindow()
{
    delete ui;
}
