#ifndef SHIP_H
#define SHIP_H
#define _USE_MATH_DEFINES
#include <math.h>
#include <QPoint>
#include <QBrush>
#include <vector>
#include <QPainter>
#include <QRect>
#include <QColor>
#include <iostream>
#include <QDebug>
#include "box.h"
#include "bullet.h"
#include "mine.h"
#include <QString>
#include "explosion.h"

class Ship
{
public:

    Ship();

    QLine getShipLine() const;
    void setShipLine(const QLine &value);

    int getLife() const;
    void setLife(int value);

    double getCurrentSpeed() const;
    void setCurrentSpeed(double value);

    int getLastEcart_dx() const;
    void setLastEcart_dx(int value);

    int getLastEcart_dy() const;
    void setLastEcart_dy(int value);

    float getAngle() const;
    void setAngle(float value);

    float getRadiant() const;
    void setRadiant(float value);

    void rotateLeft();
    void rotateRight();

    Box box() const;
    void setBox(const Box &box);

    vector<Bullet> getShipFire() const;
    void setShipFire(const vector<Bullet> &value);

    void fire();
    void acceleration();
    void hited();
    void move(QSize size);
    bool checkCollision(QPolygon poly);
    void draw(QPainter &painter);
    void drawBullet(QPainter &painter, QSize size, vector<Mine> &_mines, vector<Explosion> &_explosions);

    double getScoreFrame() const;
    void setScoreFrame(double value);

private:

    int life = 3;
    float radiant = 0;
    float angle = 20;
    int size = 30;
    int lastEcart_dx = 0;
    int lastEcart_dy = 0;
    int rotation = 0;
    double currentSpeed = 0;
    double scoreFrame = 0;

    QString path = "/home/epsi/minestorm/Assets/ship.png";



    QLine shipLine;
    QColor color = Qt::GlobalColor::yellow;
    Qt::BrushStyle pattern = Qt::SolidPattern;
    QPixmap pixmap;
    Box _box;

    void createCollisionBox();
    void updatePositionBox();
    void respawn();

    //Tirs du vaisseau
    vector<Bullet> shipFire;
};

#endif // SHIP_H
