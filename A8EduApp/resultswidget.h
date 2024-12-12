#ifndef RESULTSWIDGET_H
#define RESULTSWIDGET_H

#include <QWidget>
#include <QMovie>
#include "quizmodel.h"
#include "draggablelabel.h"
#include "droplabel.h"

namespace Ui {
class ResultsWidget;
}

class ResultsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ResultsWidget(QWidget *parent = nullptr, QuizModel *quizModel = nullptr);
    ~ResultsWidget();

private:
    Ui::ResultsWidget *ui;
    QuizModel *quizModel;
    QMovie *gif;
    int mouthValue;
    void setFoodImage(QLabel* label, const QString& imagePath);
    void toggleSimulation();
    void calculateMouthValue(const QString &food);
    void onFoodDropped();
    void updatePooState(QString imagePath, Qt::Alignment alignment = Qt::AlignRight, bool scale = true);

signals:
    void backToStartButtonClicked();
};

#endif // RESULTSWIDGET_H
