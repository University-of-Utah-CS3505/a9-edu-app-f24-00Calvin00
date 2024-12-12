#include "Physics.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

Physics::Physics(QWidget *parent) : QWidget(parent),
    world(b2Vec2(0.0f, 10.0f)),
    timer(this),
    image(":/sprites/normalPoo.png")
    // C:\Users\al3xt\CS3505\QT\a9-edu-app-f24-00Calvin00\A8EduApp\sadPoo.png
    // C:\Users\al3xt\CS3505\QT\a9-edu-app-f24-00Calvin00\A8EduApp\normalPoo.png
{
    // **Define the boundaries of the simulation based on widget size**
    // We'll define a virtual Box2D world that matches the widget's size

    // **Create boundary walls based on widget size in Box2D units**
    // For simplicity, let's assume 1 Box2D unit = 10 pixels
    wallWidth = 5.0f;  // Fixed width for the walls
    printf("%d\n", width());
    printf("%d\n", height());
    halfWorldHeight = 300.0f;
    halfWorldWidth = 400.0f;

    // **Create the boundary walls**

    // Bottom Wall
    b2BodyDef bottomWallDef;
    bottomWallDef.position.Set(0.0f, -5.0f); // Centered horizontally at y = 0
    bottomWallBody = world.CreateBody(&bottomWallDef);
    b2PolygonShape bottomWallBox;
    bottomWallBox.SetAsBox(halfWorldWidth * 2.0, wallWidth); // Thin wall
    bottomWallBody->CreateFixture(&bottomWallBox, 0.0f);

    // Top Wall
    b2BodyDef topWallDef;
    topWallDef.position.Set(0.0f, halfWorldHeight * 2.0 + 5.0);
    topWallBody = world.CreateBody(&topWallDef);
    b2PolygonShape topWallBox;
    topWallBox.SetAsBox(halfWorldWidth * 2.0, wallWidth);
    topWallBody->CreateFixture(&topWallBox, 0.0f);

    // Left Wall
    b2BodyDef leftWallDef;
    leftWallDef.position.Set(-5.0f, 0.0f);
    leftWallBody = world.CreateBody(&leftWallDef);
    b2PolygonShape leftWallBox;
    leftWallBox.SetAsBox(wallWidth, halfWorldHeight * 2.0);
    leftWallBody->CreateFixture(&leftWallBox, 0.0f);

    // Right Wall
    b2BodyDef rightWallDef;
    rightWallDef.position.Set(halfWorldWidth * 2.0 + 5.0, 0.0f);
    rightWallBody = world.CreateBody(&rightWallDef);
    b2PolygonShape rightWallBox;
    rightWallBox.SetAsBox(wallWidth, halfWorldHeight * 2.0);
    rightWallBody->CreateFixture(&rightWallBox, 0.0f);

    // **Define the dynamic body (the bouncing box)**
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(50, 350);

    body = world.CreateBody(&bodyDef);

    // Define a box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(15.0f, 45.0f); // Half-widths so actual box is 30x90

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.5f;
    fixtureDef.restitution = 0.9f;

    body->SetLinearVelocity(b2Vec2(200000000.0f, 100.0f)); // Adjust values as desired

    body->CreateFixture(&fixtureDef);

    printf("Init world\n");
    printf("Done Printing\n");

    connect(&timer, &QTimer::timeout, this, &Physics::updateWorld);
    timer.start(16); // Approximately 60 FPS
}

void Physics::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    b2Vec2 position = body->GetPosition();

    // Scale Box2D position to pixels
    int x = static_cast<int>(position.x);
    int y = static_cast<int>(position.y); // Flip y-axis

    // Draw the image
    painter.drawImage(x-15, y-45, image);
    painter.end();
}

void Physics::updateWorld() {
    // **Step the physics simulation**
    world.Step(1.0f / 60.0f, 6, 2);
    // **Trigger a repaint**
    update();
}

void Physics::addPoop(int x, int y) {
    if (halfWorldWidth * 2 - 30 < x) {
        x = halfWorldWidth * 2 - 30;
    }
    if (y < 90) {
        y = 90;
    }
    // **Define the dynamic body (the bouncing box)**
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);

    body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(15.0f, 45.0f); // Half-widths so actual box is 30x90

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.5f;
    fixtureDef.restitution = 0.9f;

    body->SetLinearVelocity(b2Vec2(200000000.0f, 100.0f)); // Adjust values as desired

    body->CreateFixture(&fixtureDef);
}

void Physics::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        addPoop(event->pos().x(), event->pos().y());
    }
    QWidget::mousePressEvent(event);
}

