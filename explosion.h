#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QPoint>
#include <iostream>
#include <QDebug>
#include <vector>
#include <QPainter>

class Explosion
{
public:
    Explosion(QPoint point);

    void draw(QPainter &painter);

private:

    QPoint _point;
    int angle;
};

#endif // EXPLOSION_H
