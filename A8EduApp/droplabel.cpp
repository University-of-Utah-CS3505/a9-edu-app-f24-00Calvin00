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
    // Only accept the event if the data being dragged is text
    if (event->mimeData()->hasText()) {
        event->acceptProposedAction();  // Accept the drag
    }
}

void DropLabel::dropEvent(QDropEvent *event)
{
    // Get the dropped text (from the DraggableLabel)
    QString droppedText = event->mimeData()->text();

    // Set the text of this label to the dropped text
    setText(droppedText);

    event->acceptProposedAction();  // Accept the drop
}
