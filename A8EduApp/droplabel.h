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

public:
    void setQuestionText(const QString &text);

signals:
    void answerDropped(const QString &question, const QString &answer);
    void foodDropped();

private:
    QString questionText;
};

#endif // DROPLABEL_H
