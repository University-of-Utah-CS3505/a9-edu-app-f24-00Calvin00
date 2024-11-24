#include "DraggableLabel.h"
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>

DraggableLabel::DraggableLabel(QWidget *parent)
    : QLabel(parent)
{
    setAlignment(Qt::AlignCenter);  // Center align text for better appearance
    setFrameStyle(QFrame::Box);     // Add a box frame for visual clarity
}

void DraggableLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // Set a custom cursor during dragging
        setCursor(Qt::ClosedHandCursor);

        // Create the QMimeData and QDrag objects as before
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(this->text());

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(this->grab());

        // Start the drag operation
        drag->exec(Qt::MoveAction);
    }

    QLabel::mousePressEvent(event);
}

void DraggableLabel::mouseReleaseEvent(QMouseEvent *event)
{
    // Reset the cursor to the normal state when dragging ends
    setCursor(Qt::ArrowCursor);
    QLabel::mouseReleaseEvent(event);
}


void DraggableLabel::mouseMoveEvent(QMouseEvent *event)
{
    // Only move if the left mouse button is held down
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - offset);  // Move the widget while dragging
    }
    event->accept();  // Accept the event
}
