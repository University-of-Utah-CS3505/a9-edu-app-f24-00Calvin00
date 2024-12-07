#ifndef COLLAPSIBLESECTION_H
#define COLLAPSIBLESECTION_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include <QResizeEvent>
#include <QLabel>
#include <QHBoxLayout>

class CollapsibleSection : public QWidget
{
    Q_OBJECT
public:
    explicit CollapsibleSection(QWidget *parent = nullptr);

    void setSectionTitle(const QString &title);
    void setContentWidget(QWidget *widget);
    void setInitialHeight(int height);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QPushButton *toggleButton;
    QWidget *contentWidget;
    QVBoxLayout *mainLayout;
    QPropertyAnimation *animation;
    QLabel *titleLabel;
    int sectionHeight;

    bool isExpanded;

private slots:
    void toggleSection();
};

#endif // COLLAPSIBLESECTION_H
