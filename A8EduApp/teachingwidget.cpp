#include "teachingwidget.h"
#include "ui_teachingwidget.h"

//Test
TeachingWidget::TeachingWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::TeachingWidget)
{
    ui->setupUi(this);

    connect(ui->introToGutButton, &QPushButton::clicked, this, &TeachingWidget::introToGutButtonClicked);
    connect(ui->whyGutHealthButton, &QPushButton::clicked, this, &TeachingWidget::whyGutHealthButtonClicked);
    connect(ui->howToStayHealthyButton, &QPushButton::clicked, this, &TeachingWidget::howToStayHealthyButtonClicked);
}

TeachingWidget::~TeachingWidget()
{
    delete ui;
}


