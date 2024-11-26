#include "DraggableLabel.h"
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>

DraggableLabel::DraggableLabel(QWidget *parent)
    : QLabel(parent)
{
    setAlignment(Qt::AlignCenter);
    setFrameStyle(QFrame::Box);
}

void DraggableLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // Set a closed hand cursor to show dragging
        setCursor(Qt::ClosedHandCursor);

        // Store data to transfer to dropped area
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
    if (event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - offset);  // Move the widget while dragging
    }
    event->accept();
}
