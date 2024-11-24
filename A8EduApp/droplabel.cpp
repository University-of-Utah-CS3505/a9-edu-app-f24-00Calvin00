#include "DropLabel.h"
#include <QMimeData>

DropLabel::DropLabel(QWidget *parent)
    : QLabel(parent)
{
    // Enable the label to accept drops
    setAcceptDrops(true);
    setAlignment(Qt::AlignCenter);
    setFrameStyle(QFrame::Box);
}

void DropLabel::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasText()) {
        // Change the background color to indicate a valid drop target
        setStyleSheet("background-color: rgb(207, 213, 255);");
        event->acceptProposedAction();
    }
}

void DropLabel::dragLeaveEvent(QDragLeaveEvent *event)
{
    // Reset the background when the drag leaves the drop area
    setStyleSheet("background-color: transparent;");
}

void DropLabel::dropEvent(QDropEvent *event)
{
    QString droppedText = event->mimeData()->text();
    setText(droppedText);

    // Reset the background and show the final text after drop
    setStyleSheet("background-color: transparent;");
    event->acceptProposedAction();
}
