#include "quizdragdropwidget.h"
#include "ui_quizdragdropwidget.h"

QuizDragDropWidget::QuizDragDropWidget(QWidget *parent, QuizModel *QuizModel)
    : QWidget(parent) ,
    ui(new Ui::QuizDragDropWidget),
    quizModel(QuizModel)
{
    ui->setupUi(this);
    connect(ui->backToQuizHomeButton, &QPushButton::clicked, this, &QuizDragDropWidget::backToQuizHomeButtonClicked);
}

QuizDragDropWidget::~QuizDragDropWidget()
{
    delete ui;
}
