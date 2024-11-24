#include "DraggableLabel.h"
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>

DraggableLabel::DraggableLabel(const QString &text, QWidget *parent)
    : QLabel(parent)
{
    setText(text);                // Set the label's text
    setAlignment(Qt::AlignCenter); // Center align text for better appearance
    setFrameStyle(QFrame::Box);    // Add a box frame for visual clarity
}

void DraggableLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) // Check for left mouse button
    {
        // Create a QMimeData object to hold the data being dragged
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(this->text()); // Use the label's text as data

        // Create a QDrag object to manage the drag operation
        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);

        // Optionally, set a pixmap for the drag cursor (use the label's appearance)
        drag->setPixmap(this->grab());

        // Start the drag operation
        drag->exec(Qt::MoveAction); // Allow moving the object
    }

    // Call the base class's implementation to ensure proper behavior
    QLabel::mousePressEvent(event);
}
