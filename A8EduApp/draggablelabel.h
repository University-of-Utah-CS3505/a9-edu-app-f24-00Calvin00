#ifndef DRAGGABLELABEL_H
#define DRAGGABLELABEL_H

#include <QLabel>
#include <QMouseEvent>

class DraggableLabel : public QLabel {
    Q_OBJECT

public:
    explicit DraggableLabel(QWidget *parent = nullptr);  // Make sure this constructor exists

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPoint offset;  // The offset for dragging
};

#endif // DRAGGABLELABEL_H
