#ifndef QUIZMATCHINGWIDGET_H
#define QUIZMATCHINGWIDGET_H

#include <QWidget>
#include "quizmodel.h"

namespace Ui {
class QuizMatchingWidget;
}

/**
 * @class QuizMatchingWidget
 * @brief A widget for displaying a matching quiz interface.
 *
 * This widget allows users to interact with a quiz that requires matching pairs of items.
 * It communicates with the QuizModel for data management and scoring.
 */
class QuizMatchingWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the QuizMatchingWidget class.
     * @param parent The parent widget.
     * @param quizModel A pointer to the QuizModel used for managing quiz data.
     */
    explicit QuizMatchingWidget(QWidget *parent = nullptr, QuizModel *quizModel = nullptr);

    /**
     * @brief Destructor for the QuizMatchingWidget class.
     */
    ~QuizMatchingWidget();

signals:
    /**
     * @brief Signal emitted when the "Back to Quiz Home" button is clicked.
     */
    void backToQuizHomeButtonClicked();

private slots:
    void onSubmitClicked();

private:
    Ui::QuizMatchingWidget *ui; // Pointer to the user interface.
    QuizModel *quizModel; // Pointer to the QuizModel for managing quiz data.
};

#endif // QUIZMATCHINGWIDGET_H

