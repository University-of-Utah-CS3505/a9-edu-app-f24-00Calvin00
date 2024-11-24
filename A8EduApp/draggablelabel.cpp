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
        // Record the offset of the mouse position within the label
        offset = event->pos();

        // Create a QMimeData object to hold the data being dragged
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(this->text());  // Use the label's text as data

        // Create a QDrag object to manage the drag operation
        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);

        // Optionally, set a pixmap for the drag cursor (use the label's appearance)
        drag->setPixmap(this->grab());

        // Start the drag operation
        drag->exec(Qt::MoveAction);  // Allow moving the object
    }

    QLabel::mousePressEvent(event);  // Call the base class's implementation
}

void DraggableLabel::mouseMoveEvent(QMouseEvent *event)
{
    // Only move if the left mouse button is held down
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - offset);  // Move the widget while dragging
    }
    event->accept();  // Accept the event
}
