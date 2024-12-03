#include "resultswidget.h"
#include "ui_resultswidget.h"

ResultsWidget::ResultsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ResultsWidget)
{
    ui->setupUi(this);

    // Connect signals
    connect(ui->backToStartButton, &QPushButton::clicked, this, &ResultsWidget::backToStartButtonClicked);
}


ResultsWidget::~ResultsWidget()
{
    delete ui;
}
