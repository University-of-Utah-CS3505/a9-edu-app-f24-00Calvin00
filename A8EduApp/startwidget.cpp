#include "startwidget.h"
#include "ui_startwidget.h"

StartWidget::StartWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::StartWidget)
{
    ui->setupUi(this);

    // Connect the start button to emit a signal
    connect(ui->learnButton, &QPushButton::clicked, this, &StartWidget::startButtonClicked);
}

StartWidget::~StartWidget()
{
    delete ui;
}
