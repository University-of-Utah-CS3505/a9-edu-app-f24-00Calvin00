#include "quizdragdropwidget.h"
#include "ui_quizdragdropwidget.h"

QuizDragDropWidget::QuizDragDropWidget(QWidget *parent, QuizModel *QuizModel)
    : QWidget(parent) ,
    ui(new Ui::QuizDragDropWidget),
    quizModel(QuizModel)
{
    ui->setupUi(this);
}

QuizDragDropWidget::~QuizDragDropWidget()
{
    delete ui;
}
