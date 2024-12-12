#ifndef RESULTSWIDGET_H
#define RESULTSWIDGET_H

#include <QWidget>
#include <QMovie>
#include "quizmodel.h"
#include "draggablelabel.h"
#include "droplabel.h"

namespace Ui {
/**
 * @brief Forward declaration for the UI class.
 */
class ResultsWidget;
}

/**
 * @brief The ResultsWidget class provides the functionality for displaying the summary and simulation as well as handles interactions in the UI.
 */
class ResultsWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a ResultsWidget instance
     * @param the parent widget, default is nullptr
     * @param the quizModel used, default is nullptr
     */
    explicit ResultsWidget(QWidget *parent = nullptr, QuizModel *quizModel = nullptr);
    ~ResultsWidget();

    /**
     * @brief Sets the food labels with their respective images
     * @param the label being set
     * @param the image path
     */
    void setFoodImage(QLabel* label, const QString& imagePath);

    /**
     * @brief Sets the text, font, and alignment of the information text browser
     * @param the text to be set
     */
    void setInformationText(const QString &text);

    /**
     * @brief Toggles the summary/simulation button text and hides/shows the appropriate text browsers
     */
    void toggleSimulation();

    /**
     * @brief Calculates the current mouth value based on the food dropped and that food's value
     * @param the food dropped
     */
    void calculateMouthValue(const QString &food);

    /**
     * @brief Updates the poo image and information text based on the current state (mouth value)
     */
    void onFoodDropped();

    /**
     * @brief Updates the poo image to reflect the state
     * @param the image path
     * @param the image alignment within the label
     * @param denotes whether to scale the image or not
     */
    void updatePooState(QString imagePath, Qt::Alignment alignment = Qt::AlignRight, bool scale = true);

private:
    Ui::ResultsWidget *ui;
    QuizModel *quizModel;
    QMovie *gif;
    int mouthValue;

signals:
    void backToStartButtonClicked();
};

#endif // RESULTSWIDGET_H
