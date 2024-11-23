#include "quizzinghomewidget.h"
#include "ui_quizzinghomewidget.h"

QuizzingHomeWidget::QuizzingHomeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QuizzingHomeWidget)
{
    ui->setupUi(this);
    connect(ui->matchingButton, &QPushButton::clicked, this, &QuizzingHomeWidget::matchingButtonClicked);
    connect(ui->dragDropButton, &QPushButton::clicked, this, &QuizzingHomeWidget::dragDropButtonClicked);
}

QuizzingHomeWidget::~QuizzingHomeWidget()
{
    delete ui;
}
