#ifndef QUIZMODEL_H
#define QUIZMODEL_H

#include <QObject>
#include <QString>
#include <QMap>

/**
 * @class QuizModel
 * @brief Manages quiz data and scores for matching and drag-and-drop questions.
 *
 * The QuizModel class provides functionality for adding questions, submitting answers,
 * and calculating scores for different types of quiz questions.
 */
class QuizModel : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the QuizModel class.
     * @param parent The parent QObject, if any.
     */
    explicit QuizModel(QObject *parent = nullptr);

    /**
     * @brief Adds a matching question to the quiz.
     * @param question The question text.
     * @param correctAnswer The correct answer for the question.
     */
    void addMatchingQuestion(const QString &question, const QString &correctAnswer);

    /**
     * @brief Adds a drag-and-drop question to the quiz.
     * @param question The question text.
     * @param correctAnswer The correct answer for the question.
     */
    void addDragDropQuestion(const QString &question, const QString &correctAnswer);

    /**
     * @brief Submits a user's answer for a matching question and updates the score if correct.
     * @param question The question text.
     * @param userAnswer The user's answer.
     */
    void submitMatchingAnswer(const QString &question, const QString &userAnswer);

    /**
     * @brief Submits a user's answer for a drag-and-drop question and updates the score if correct.
     * @param question The question text.
     * @param userAnswer The user's answer.
     */
    void submitDragDropAnswer(const QString &question, const QString &userAnswer);

    /**
     * @brief Returns the current score for matching questions.
     * @return The matching score.
     */
    int getMatchingScore() const;

    /**
     * @brief Returns the current score for drag-and-drop questions.
     * @return The drag-and-drop score.
     */
    int getDragDropScore() const;

    /**
     * @brief Returns the total score across all quiz types.
     * @return The total score.
     */
    int getTotalScore() const;

    /**
     * @brief Checks if a user's answer for a matching question is correct.
     * @param question The question text.
     * @return True if the answer is correct, otherwise false.
     */
    bool isMatchingAnswerCorrect(const QString &question) const;

    /**
     * @brief Checks if a user's answer for a drag-and-drop question is correct.
     * @param question The question text.
     * @return True if the answer is correct, otherwise false.
     */
    bool isDragDropAnswerCorrect(const QString &question) const;

    /**
     * @brief Returns the total number of matching questions.
     * @return The number of matching questions.
     */
    int getTotalMatchingQuestions() const;

    /**
     * @brief Returns the total number of drag-and-drop questions.
     * @return The number of drag-and-drop questions.
     */
    int getTotalDragDropQuestions() const;

    /**
     * @brief Sets the score for drag-and-drop questions manually.
     * @param score The score to set.
     */
    void setDragDropScore(int score);

private:
    QMap<QString, QString> matchingQuestions; // Stores matching questions and their correct answers.
    QMap<QString, QString> dragDropQuestions; // Stores drag-and-drop questions and their correct answers.
    QMap<QString, QString> matchingUserAnswers; // Stores user answers for matching questions.
    QMap<QString, QString> dragDropUserAnswers; // Stores user answers for drag-and-drop questions.

    int matchingScore; // The score for matching questions.
    int dragDropScore; // The score for drag-and-drop questions.
};

#endif // QUIZMODEL_H
