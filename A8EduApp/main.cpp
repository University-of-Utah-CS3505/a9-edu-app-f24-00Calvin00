#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QuizModel quizModel;
    MainWindow w(nullptr, &quizModel);

    w.show();
    return a.exec();
}
