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

    void addMatchingQuestion(const QString &question, const QString &correctAnswer);
    void addDragDropQuestion(const QString &question, const QString &correctAnswer);
    void addFoodValue(const QString &food, const int &value);

    void submitMatchingAnswer(const QString &question, const QString &userAnswer);
    void submitDragDropAnswer(const QString &question, const QString &userAnswer);

    int getMatchingScore() const;
    int getDragDropScore() const;
    int getCurrentMouthValue() const;

    bool isMatchingAnswerCorrect(const QString &question) const;
    bool isDragDropAnswerCorrect(const QString &question) const;
    QString stateOfPoo(const int &mouthValue) const;

    int getTotalMatchingQuestions() const;
    int getTotalDragDropQuestions() const;

    void setDragDropScore(int score);

private:
    // Maps for matching and drag-and-drop questions
    QMap<QString, QString> matchingQuestions;  // Questions mapped to correct answers
    QMap<QString, QString> dragDropQuestions;
    QMap<QString, int> foodValues;

    // Store user answers
    QMap<QString, QString> matchingUserAnswers;
    QMap<QString, QString> dragDropUserAnswers;

    // User scores for each type of question
    int matchingScore;
    int dragDropScore;
    int mouthValue;
};

#endif // QUIZMODEL_H
