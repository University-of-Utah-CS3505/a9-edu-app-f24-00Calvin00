#ifndef RESULTSWIDGET_H
#define RESULTSWIDGET_H

#include <QWidget>
#include <QMovie>
#include <quizmodel.h>
#include <draggablelabel.h>
#include <droplabel.h>

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
    void simulationToggle();
    void calculateMouthValue(const QString &food);
    void onFoodDropped();
    void updatePooState(QString imagePath);

signals:
    void backToStartButtonClicked();
};

#endif // RESULTSWIDGET_H
