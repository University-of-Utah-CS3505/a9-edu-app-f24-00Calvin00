#ifndef DRAGGABLELABEL_H
#define DRAGGABLELABEL_H

#include <QLabel>
#include <QMouseEvent>

class DraggableLabel : public QLabel {
    Q_OBJECT

public:
    explicit DraggableLabel(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPoint offset;  // The offset for dragging

signals:
    void mousePressed(const QString &objectName);
};

#endif // DRAGGABLELABEL_H
