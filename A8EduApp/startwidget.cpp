#include "startwidget.h"
#include "ui_startwidget.h"

#include <QVBoxLayout>

StartWidget::StartWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::StartWidget)
{
    ui->setupUi(this);
    ui->widget->show();

    // Connect the start button to emit a signal
    connect(ui->learnButton, &QPushButton::clicked, this, &StartWidget::learnButtonClicked);
    connect(ui->quizButton, &QPushButton::clicked, this, &StartWidget::quizButtonClicked);
    connect(ui->resultsButton, &QPushButton::clicked, this, &StartWidget::resultsButtonClicked);
}

StartWidget::~StartWidget()
{
    delete ui;
}
