#ifndef DRAGGABLELABEL_H
#define DRAGGABLELABEL_H

#include <QLabel>
#include <QDrag>

class DraggableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit DraggableLabel(const QString &text, QWidget *parent = nullptr);

protected:
    // Handles the drag start event
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // DRAGGABLELABEL_H
