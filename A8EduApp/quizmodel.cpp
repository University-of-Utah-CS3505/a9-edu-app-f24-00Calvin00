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

void QuizModel::addFoodValue(const QString &food, const int &value)
{
    foodValues.insert(food, value);
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

int QuizModel::getCurrentMouthValue() const
{
    return mouthValue;
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

QString QuizModel::stateOfPoo(const int &mouthValue) const
{
    if (mouthValue <= 25) {
        return "hard";
    } else if (mouthValue > 25 && mouthValue <= 50) {
        return "normal";
    } else if (mouthValue > 50 && mouthValue <= 75) {
        return "happy";
    } else if (mouthValue > 75 && mouthValue <= 100) {
        return "liquid";
    } else {
        return "explode";
    }
}

int QuizModel::getTotalMatchingQuestions() const
{
    return matchingQuestions.size();
}

int QuizModel::getTotalDragDropQuestions() const
{
    return dragDropQuestions.size();
}

void QuizModel::setDragDropScore(int score) {
    dragDropScore = score;
}


