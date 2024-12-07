#ifndef QUIZMODEL_H
#define QUIZMODEL_H

#include <QObject>
#include <QString>
#include <QMap>

class QuizModel : public QObject
{
    Q_OBJECT

public:
    explicit QuizModel(QObject *parent = nullptr);

    void addMatchingQuestion(const QString &question, const int correctAnswer);
    void addDragDropQuestion(const QString &question, const QString &correctAnswer);

    void submitMatchingAnswer(const QString &question, const int userAnswer);
    void submitDragDropAnswer(const QString &question, const QString &userAnswer);

    int getMatchingScore() const;
    int getDragDropScore() const;

    bool isMatchingAnswerCorrect(const QString &question) const;
    bool isDragDropAnswerCorrect(const QString &question) const;

    int getTotalMatchingQuestions() const;
    int getTotalDragDropQuestions() const;

    void setDragDropScore(int score);
    void setMatchingScore(int score);

private:
    // Maps for matching and drag-and-drop questions
    QMap<QString, int> matchingQuestions;  // Questions mapped to correct answers
    QMap<QString, QString> dragDropQuestions;

    // Store user answers
    QMap<QString, int> matchingUserAnswers;
    QMap<QString, QString> dragDropUserAnswers;

    // User scores for each type of question
    int matchingScore;
    int dragDropScore;
};

#endif // QUIZMODEL_H
