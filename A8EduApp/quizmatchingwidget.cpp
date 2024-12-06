#include "quizmatchingwidget.h"
#include "ui_quizmatchingwidget.h"

QuizMatchingWidget::QuizMatchingWidget(QWidget *parent, QuizModel *QuizModel)
    : QWidget(parent),
    ui(new Ui::QuizMatchingWidget),
    quizModel(QuizModel)
{
    ui->setupUi(this);

    // Set the background color
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, QColor(238, 223, 242));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    connect(ui->backToQuizHomeButton, &QPushButton::clicked, this, &QuizMatchingWidget::backToQuizHomeButtonClicked);
}

QuizMatchingWidget::~QuizMatchingWidget()
{
    delete ui;
}
