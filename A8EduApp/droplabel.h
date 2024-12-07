#ifndef DROPLABEL_H
#define DROPLABEL_H

#include <QLabel>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

/**
 * @class DropLabel
 * @brief A QLabel that acts as a drop target for dragging and dropping text-based data from DraggableLabels.
 */
class DropLabel : public QLabel {
    Q_OBJECT

public:
    /**
     * @brief Constructs a DropLabel instance.
     * @param parent The parent widget, default is nullptr.
     */
    explicit DropLabel(QWidget *parent = nullptr);

protected:
    /**
     * @brief Handles the drag enter event to determine if a drop is valid.
     * @param event The drag enter event.
     */
    void dragEnterEvent(QDragEnterEvent *event) override;

    /**
     * @brief Handles the drag leave event when dragging leaves the widget.
     * @param event The drag leave event.
     */
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    /**
     * @brief Handles the drop event when data is dropped onto the widget.
     * @param event The drop event.
     */
    void dropEvent(QDropEvent *event) override;

public:
    /**
     * @brief Sets the question text for this drop label.
     * @param text The text to be set as the question.
     */
    void setQuestionText(const QString &text);

signals:
    /**
     * @brief Signal emitted when an answer is dropped on the label.
     * @param question The question text.
     * @param answer The dropped answer.
     */
    void answerDropped(const QString &question, const QString &answer);

    /**
     * @brief Signal emitted when food (answer) is dropped on the label.
     * @param food The dropped food item.
     */
    void foodDropped(const QString &food);

private:
    QString questionText; // The question text associated with this drop label.
};

#endif // DROPLABEL_H
