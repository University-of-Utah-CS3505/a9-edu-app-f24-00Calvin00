#include "QuizModel.h"

QuizModel::QuizModel(QObject *parent)
    : QObject(parent), matchingScore(0), dragDropScore(0)
{

}

void QuizModel::addMatchingQuestion(const QString &question, const QString &correctAnswer)
{
    matchingQuestions.insert(question, correctAnswer);
}

void QuizModel::addDragDropQuestion(const QString &question, const QString &correctAnswer)
{
    dragDropQuestions.insert(question, correctAnswer);
}

void QuizModel::submitMatchingAnswer(const QString &question, const QString &userAnswer)
{
    matchingUserAnswers.insert(question, userAnswer);
    if (isMatchingAnswerCorrect(question))
    {
        matchingScore++;
    }
}

void QuizModel::submitDragDropAnswer(const QString &question, const QString &userAnswer)
{
    dragDropUserAnswers.insert(question, userAnswer);
    if (isDragDropAnswerCorrect(question))
    {
        dragDropScore++;
    }
}

int QuizModel::getMatchingScore() const
{
    return matchingScore;
}

int QuizModel::getDragDropScore() const
{
    return dragDropScore;
}

bool QuizModel::isMatchingAnswerCorrect(const QString &question) const
{
    return matchingUserAnswers.contains(question) &&
           matchingUserAnswers.value(question) == matchingQuestions.value(question);
}

bool QuizModel::isDragDropAnswerCorrect(const QString &question) const
{
    return dragDropUserAnswers.contains(question) &&
           dragDropUserAnswers.value(question) == dragDropQuestions.value(question);
}

int QuizModel::getTotalMatchingQuestions() const
{
    return matchingQuestions.size();
}

int QuizModel::getTotalDragDropQuestions() const
{
    return dragDropQuestions.size();
}

void QuizModel::setDragDropScore(int score) const {
    dragDropScore = score;
}


