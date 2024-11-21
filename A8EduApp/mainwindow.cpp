#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Connects
    connect(ui->learnButton, &QPushButton::clicked, this, &MainWindow::openTeachingWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openTeachingWindow()
{
    if (!teachingWindow)
    {
        teachingWindow = new TeachingWindow();
    }

    this->hide();              // Hide MainWindow
    teachingWindow->show();    // Display TeachingWindow

    // Connecting TeachingWindow's close signal back to MainWindow
    connect(teachingWindow, &TeachingWindow::destroyed, this, [this]()
    {
        this->show();          // Show MainWindow when TeachingWindow is closed
    });
}

