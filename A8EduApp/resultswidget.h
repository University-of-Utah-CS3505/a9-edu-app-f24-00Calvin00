#ifndef RESULTSWIDGET_H
#define RESULTSWIDGET_H

#include <QWidget>
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
    QPixmap *pooPixmap;
    int mouthValue;
    void updatePooState(QString imagePath);
    void onFoodDropped();

signals:
    void backToStartButtonClicked();
};

#endif // RESULTSWIDGET_H
