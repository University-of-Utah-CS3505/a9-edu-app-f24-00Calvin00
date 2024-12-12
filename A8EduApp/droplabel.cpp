#include "DropLabel.h"
#include <QMimeData>

DropLabel::DropLabel(QWidget *parent)
    : QLabel(parent)
{
    // Enable the label to accept drops
    setAcceptDrops(true);
    setAlignment(Qt::AlignCenter);
    setFrameStyle(QFrame::Box);
    questionText ="";
}

void DropLabel::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasText()) {
        // Change background color to show valid drop target
        setStyleSheet("background-color: rgb(207, 213, 255);");
        event->acceptProposedAction();
    }
}

void DropLabel::dragLeaveEvent(QDragLeaveEvent *)
{
    setStyleSheet("color: black; background-color:  rgb(209, 160, 224);");
}

void DropLabel::dropEvent(QDropEvent *event)
{
    // Get stored data from the dropped label
    QString droppedText = event->mimeData()->text();
    setText(droppedText);

    // Emit the drop signal, reset the background, and show the final text after drop
    if (droppedText == "") {
        emit foodDropped(droppedText);
        setStyleSheet("background-color: transparent ;");
    } else {
        emit answerDropped(questionText, droppedText);
        setStyleSheet("color: black; background-color:  rgb(209, 160, 224);");
    }
    event->acceptProposedAction();
}

void DropLabel::setQuestionText(const QString &text)
{
    questionText = text;
}
