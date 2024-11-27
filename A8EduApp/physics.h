#ifndef PHYSICS_H
#define PHYSICS_H

#include <QWidget>
#include <Box2D/Box2D.h>
#include <QTimer>

class Physics : public QWidget
{
    Q_OBJECT
public:
    explicit Physics(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
signals:

public slots:
    void updateWorld();

private:
    b2World world;
    b2Body* body;
    QTimer timer;
    QImage image;
};

#endif // SCENEWIDGET_H
