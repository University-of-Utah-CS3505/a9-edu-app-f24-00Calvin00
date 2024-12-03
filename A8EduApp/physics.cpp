#include "Physics.h"
#include <QPainter>
#include <QDebug>

Physics::Physics(QWidget *parent) : QWidget(parent),
    world(b2Vec2(0.0f, -10.0f)),
    timer(this),
    image(":/sprites/happyPoo.png")
{
    // **Define the boundaries of the simulation based on widget size**
    // We'll define a virtual Box2D world that matches the widget's size

    // **Create boundary walls based on widget size in Box2D units**
    // For simplicity, let's assume 1 Box2D unit = 10 pixels
    wallWidth = 5.0f;  // Fixed width for the walls

    halfWorldHeight = 300.0f;
    halfWorldWidth = 400.0f;
    // **Create the boundary walls**

    // Bottom Wall
    b2BodyDef bottomWallDef;
    bottomWallDef.position.Set(halfWorldWidth, 0.0f); // Centered horizontally at y = 0
    bottomWallBody = world.CreateBody(&bottomWallDef);
    b2PolygonShape bottomWallBox;
    bottomWallBox.SetAsBox(halfWorldWidth * 2.0, wallWidth); // Thin wall
    bottomWallBody->CreateFixture(&bottomWallBox, 0.0f);

    // Top Wall
    b2BodyDef topWallDef;
    topWallDef.position.Set(halfWorldWidth, halfWorldHeight * 2.0);
    topWallBody = world.CreateBody(&topWallDef);
    b2PolygonShape topWallBox;
    topWallBox.SetAsBox(halfWorldWidth * 2.0, wallWidth);
    topWallBody->CreateFixture(&topWallBox, 0.0f);

    // Left Wall
    b2BodyDef leftWallDef;
    leftWallDef.position.Set(0.0f, halfWorldHeight);
    leftWallBody = world.CreateBody(&leftWallDef);
    b2PolygonShape leftWallBox;
    leftWallBox.SetAsBox(wallWidth, halfWorldHeight * 2.0);
    leftWallBody->CreateFixture(&leftWallBox, 0.0f);

    // Right Wall
    b2BodyDef rightWallDef;
    rightWallDef.position.Set(halfWorldWidth * 2.0 , halfWorldHeight);
    rightWallBody = world.CreateBody(&rightWallDef);
    b2PolygonShape rightWallBox;
    rightWallBox.SetAsBox(wallWidth, halfWorldHeight * 2.0);
    rightWallBody->CreateFixture(&rightWallBox, 0.0f);

    // **Define the dynamic body (the bouncing box)**
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(halfWorldWidth, halfWorldHeight); // Start in the center

    body = world.CreateBody(&bodyDef);

    // Define a box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(15.0f, 45.0f); // Half-widths so actual box is 30x90

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 2.0f;
    fixtureDef.restitution = 1.0f;

    body->SetLinearVelocity(b2Vec2(-2.0f, -3.0f)); // Adjust values as desired

    body->CreateFixture(&fixtureDef);

    printf("Init world\n");
    printf("Done Printing");

    connect(&timer, &QTimer::timeout, this, &Physics::updateWorld);
    timer.start(16); // Approximately 60 FPS
}

void Physics::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    b2Vec2 position = body->GetPosition();

    // Scale Box2D position to pixels
    int x = static_cast<int>(position.x);
    int y = static_cast<int>(position.y); // Flip y-axis

    printf("x: %d\n", x);
    printf("y: %d\n", y);

    // Draw the image
    painter.drawImage(x, y, image);

    b2Vec2 bottomWallPosition = bottomWallBody->GetPosition();
    QRect platformRect(
        bottomWallPosition.x,
        bottomWallPosition.y,
        halfWorldWidth * 2,
        wallWidth
        );
    painter.fillRect(platformRect, Qt::red);
    painter.end();
}

void Physics::updateWorld() {
    // **Step the physics simulation**
    world.Step(1.0f / 60.0f, 6, 2);

    // **Trigger a repaint**
    update();
}
