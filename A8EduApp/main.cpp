#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "Available styles:" << QStyleFactory::keys();

    // Set the application style to Windows
    //a.setStyle(QStyleFactory::create("Windows"));
    //a.setFont(QFont("MS Sans Serif", 10));

    QuizModel quizModel;
    MainWindow w(nullptr, &quizModel);

    w.show();
    return a.exec();
}
