#include "teachingwidget.h"
#include "ui_teachingwidget.h"

TeachingWidget::TeachingWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::TeachingWidget)
{
    ui->setupUi(this);

    connect(ui->introToGutButton, &QPushButton::clicked, this, &TeachingWidget::introToGutButtonClicked);
}

TeachingWidget::~TeachingWidget()
{
    delete ui;
}


