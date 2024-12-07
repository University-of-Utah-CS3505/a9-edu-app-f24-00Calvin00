#ifndef QUIZZINGHOMEWIDGET_H
#define QUIZZINGHOMEWIDGET_H

#include <QWidget>
#include "quizmodel.h"

namespace Ui {
class QuizzingHomeWidget;
}

/**
 * @class QuizzingHomeWidget
 * @brief Represents the main widget for the quizzing home screen.
 *
 * The QuizzingHomeWidget class provides a user interface for navigating to different types of quizzes
 * and displaying relevant information, such as scores.
 */
class QuizzingHomeWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the QuizzingHomeWidget class.
     * @param parent The parent QWidget, if any.
     * @param quizModel Pointer to the QuizModel instance used for managing quiz data.
     */
    explicit QuizzingHomeWidget(QWidget *parent = nullptr, QuizModel *quizModel = nullptr);

    /**
     * @brief Destructor for the QuizzingHomeWidget class.
     */
    ~QuizzingHomeWidget();

protected:
    /**
     * @brief Override of the QWidget's show event.
     * Called when the widget is shown. This can be used for additional setup or updates.
     * @param event The show event.
     */
    void showEvent(QShowEvent *event) override;

signals:
    /**
     * @brief Signal emitted when the matching quiz button is clicked.
     */
    void matchingButtonClicked();

    /**
     * @brief Signal emitted when the drag-and-drop quiz button is clicked.
     */
    void dragDropButtonClicked();

    /**
     * @brief Signal emitted when the back to start button is clicked.
     */
    void backToStartButtonClicked();

private:
    Ui::QuizzingHomeWidget *ui; /**< Pointer to the UI components managed by Qt Designer. */
    QuizModel *quizModel; /**< Pointer to the QuizModel used for handling quiz data and scores. */

    /**
     * @brief Updates the score label to reflect the current quiz scores.
     */
    void updateScoreLabel();
};

#endif // QUIZZINGHOMEWIDGET_H
