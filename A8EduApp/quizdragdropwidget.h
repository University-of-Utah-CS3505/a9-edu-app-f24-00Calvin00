#ifndef QUIZDRAGDROPWIDGET_H
#define QUIZDRAGDROPWIDGET_H

#include <QWidget>
#include "quizmodel.h"

namespace Ui {
class QuizDragDropWidget;
}

/**
 * @class QuizDragDropWidget
 * @brief A widget for a drag-and-drop quiz interface.
 *
 * This widget provides an interactive quiz interface where users can drag and drop
 * answers into the corresponding questions. It interacts with a QuizModel to handle
 * data and scoring.
 */
class QuizDragDropWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for QuizDragDropWidget.
     * @param parent The parent widget.
     * @param quizModel A pointer to the QuizModel used for managing quiz data.
     */
    explicit QuizDragDropWidget(QWidget *parent = nullptr, QuizModel *quizModel = nullptr);

    /**
     * @brief Destructor for QuizDragDropWidget.
     */
    ~QuizDragDropWidget();

signals:
    /**
     * @brief Signal emitted when the "Back to Quiz Home" button is clicked.
     */
    void backToQuizHomeButtonClicked();

private slots:
    /**
     * @brief Slot triggered when an answer is dropped.
     * @param question The question text.
     * @param answer The answer text.
     */
    void onAnswerDropped(const QString &question, const QString &answer);

    /**
     * @brief Slot triggered when the "Submit" button is clicked.
     */
    void onSubmitClicked();

private:
    Ui::QuizDragDropWidget *ui; // Pointer to the user interface.
    QuizModel *quizModel; // Pointer to the QuizModel for managing quiz data.
    QMap<QString, QString> userAnswers; // Map to store user answers.
};

#endif // QUIZDRAGDROPWIDGET_H

