#ifndef DROPLABEL_H
#define DROPLABEL_H

#include <QLabel>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

class DropLabel : public QLabel {
    Q_OBJECT

public:
    explicit DropLabel(QWidget *parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

};

#endif // DROPLABEL_H
