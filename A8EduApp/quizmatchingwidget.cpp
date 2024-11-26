#include "quizmatchingwidget.h"
#include "ui_quizmatchingwidget.h"

QuizMatchingWidget::QuizMatchingWidget(QWidget *parent, QuizModel *QuizModel)
    : QWidget(parent),
    ui(new Ui::QuizMatchingWidget),
    quizModel(QuizModel)
{
    ui->setupUi(this);
}

QuizMatchingWidget::~QuizMatchingWidget()
{
    delete ui;
}
