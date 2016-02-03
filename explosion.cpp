#include "explosion.h"


Explosion::Explosion(QPoint point)
{
    _point = point;

}

void Explosion::draw(QPainter &painter)
{
    for (int var = 0; var <= 5; ++var) {
        angle = -7 + (rand() %(int)(7 - (-7) +1 ));
        painter.drawLine(_point,(QPoint(_point.x() + 60 * cos(angle),_point.y() + 60 * sin(angle))));
    }

}
