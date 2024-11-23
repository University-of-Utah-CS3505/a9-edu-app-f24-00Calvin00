#include "quizdragdropwidget.h"
#include "ui_quizdragdropwidget.h"

QuizDragDropWidget::QuizDragDropWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QuizDragDropWidget)
{
    ui->setupUi(this);
}

QuizDragDropWidget::~QuizDragDropWidget()
{
    delete ui;
}
