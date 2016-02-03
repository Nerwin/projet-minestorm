#ifndef MINESTORM_H
#define MINESTORM_H
#include "game.h"
#include "bullet.h"
#include "ship.h"
#include "explosion.h"

#include <QPoint>
#include <QBrush>
#include <vector>
#include <QPainter>
#include <QRect>
#include <QColor>
#include <iostream>
#include <QDebug>
#include <QLabel>
#include <string>



using namespace std;
/**
 * @brief La classe Minestorm correspond au Mini-Projet à rendre pour le 14 Février
 */

class Minestorm : public Game
{
public:
    Minestorm(const QSize &size,QObject *parent = nullptr);
    virtual void draw(QPainter &painter, QRect &rect) override;
    void mousePressed( int x, int y) override;
    void keyPressed( int key ) override;
    void keyReleased( int key ) override;
    void mouseReleased( int x, int y) override;
    void mouseMoved(int x, int y) override;
private:
    virtual void step();
    void initialize();
    void addMines(QPoint point, double size);
    void goDown();
    void initMine();

    int changeMe = 5;

    // Mines
    Qt::BrushStyle _currentStyle;
    vector<Mine> _mines;
    QObject *parentPointer;
    QTimer timer;
    // Explosions
    vector<Explosion> _explosions;

    // Ship
    Ship myShip;

    // Score
    double *_ptrScore;

    // Font
    QFont font;
};

#endif // MINESTORM_H
