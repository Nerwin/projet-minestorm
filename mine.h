#ifndef MINE_H
#define MINE_H
#include <QPoint>
#include <QBrush>
#include <vector>
#include <QPainter>
#include <QRect>
#include <QColor>
#include <iostream>
#include <QDebug>
#include "box.h"
#include <QObject>
#include <QTimer>
#include <QSharedPointer>
#include "timer.h"

using namespace std;
class Mine : public QObject
{

    Q_OBJECT

public:

    Mine(QPoint point, double size);

    QPoint point() const;
    void setPoint(const QPoint &point);

    Box box() const;
    void setBox(const Box &box);

    double size() const;
    void setSize(double size);

    QLine getDirectionLine() const;
    void setDirectionLine(const QLine &value);

    QPoint newPoint() const;
    void setNewPoint(const QPoint &newPoint);

    void draw(QPainter &painter);
    void move(QSize size);

    void updatePositionBox();
    void updateMinePosition();
    bool checkCollision(QPoint bulletPoint);

    QPixmap getPixmap() const;
    void setPixmap(const QPixmap &value);

private slots:
    void eclosion();

private:
    void createCollisionBox();

    // Variables mine
    int angle;
    double _size;
    QImage _image;
    QSharedPointer<QTimer> _timer;

    // Collision
    Box _box;
    QPoint _point;
    QPoint _newPoint;
    QLine directionLine;
    QString path = "/home/epsi/minestorm/Assets/point-minestorm.png";
    QPixmap pixmap;

};

#endif // MINE_H