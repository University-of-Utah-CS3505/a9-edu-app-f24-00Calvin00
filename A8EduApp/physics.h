#ifndef PHYSICS_H
#define PHYSICS_H

#include <QWidget>
#include <QTimer>
#include <QImage>
#include <Box2D/Box2D.h>

class Physics : public QWidget
{
    Q_OBJECT

public:
    explicit Physics(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

public slots:
    void updateWorld();
    void addPoop(int x, int y);

private:
    b2World world;       // The Box2D world
    QTimer timer;        // Timer for updating the physics simulation
    QImage image;        // Image representing the bouncing box
    b2Body* body;        // Pointer to the dynamic body (the bouncing box)
    // Add these member variables
    b2Body* bottomWallBody;
    b2Body* topWallBody;
    b2Body* leftWallBody;
    b2Body* rightWallBody;

    float halfWorldWidth;   // World height in Box2D units
    float halfWorldHeight;
    float wallWidth;    // World width in Box2D units
};

#endif // PHYSICS_H
