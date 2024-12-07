#ifndef DRAGGABLELABEL_H
#define DRAGGABLELABEL_H

#include <QLabel>
#include <QMouseEvent>

/**
 * @class DraggableLabel
 * @brief A QLabel that can be dragged and dropped within a QWidget onto a drop label that receives it's text.
 *
 * This class extends QLabel and adds functionality to support drag-and-drop operations.
 * The label can be dragged by pressing and holding the left mouse button and moving around.
 * Releasing the mouse drops the label.
 */
class DraggableLabel : public QLabel {
    Q_OBJECT

public:
    /**
     * @brief Constructs a DraggableLabel object.
     * @param parent The parent widget for this label, defaults to nullptr.
     */
    explicit DraggableLabel(QWidget *parent = nullptr);

protected:
    /**
     * @brief Handles mouse press events for the label.
     *
     * This method is overridden to initiate a drag operation when the left mouse button is pressed.
     * The cursor changes to a closed hand to indicate a dragging action.
     *
     * @param event The mouse event details.
     */
    void mousePressEvent(QMouseEvent *event) override;

    /**
     * @brief Handles mouse release events for the label.
     *
     * This method is overridden to reset the cursor to the default arrow when dragging ends.
     *
     * @param event The mouse event details.
     */
    void mouseReleaseEvent(QMouseEvent *event) override;

    /**
     * @brief Handles mouse move events for the label.
     *
     * This method allows the label to be moved according to the global mouse position while the left
     * mouse button is pressed.
     *
     * @param event The mouse event details.
     */
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPoint offset;  // The offset for dragging, used to calculate the position relative to the mouse.

signals:
    /**
     * @brief Signal emitted when the label is pressed.
     *
     * This signal passes the object name of the label to any connected slot.
     *
     * @param objectName The name of the label object.
     */
    void mousePressed(const QString &objectName);
};

#endif // DRAGGABLELABEL_H
