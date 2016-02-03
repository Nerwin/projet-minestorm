#include "minestorm.h"

Minestorm::Minestorm(const QSize &size,QObject *parent):Game(size,parent), _currentStyle(Qt::SolidPattern),parentPointer(parent) {

    initMine();



    // Initialisation du score dans un pointeur
    font.setPixelSize(15);
}
void Minestorm::addMines(QPoint point, double size) {

    Mine mine(point,size);
    _mines.push_back(mine);


    // ECLOSION FONCTIONNELLE
    /*timer.setParent(this);
    timer.setSingleShot(true);
    connect(&timer,SIGNAL(timeout()),this,SLOT(mustEclose()));
    timer.start(5000);*/
}



void Minestorm::step() {
    if (myShip.getCurrentSpeed() > 0) {
        myShip.move(size());
    }
}

void Minestorm::draw(QPainter &painter, QRect &rect) {

    //qDebug() << "valeur = " << changeMe;
    // Label for Game component
    painter.fillRect(rect, QColor(0,0,0));
    QString score = QString::number(this->score());
    QString shipVie = QString::number(myShip.getLife());

    auto indexExplo = 0u;
    for (vector<Explosion>::iterator itExplo=_explosions.begin(); itExplo != _explosions.end();){
        _explosions[indexExplo].draw(painter);
        ++itExplo;
        indexExplo++;
    }

    auto index = 0u;
    for (vector<Mine>::iterator itMine=_mines.begin(); itMine != _mines.end();){

        _mines[index].move(size());
        _mines[index].draw(painter);

        // ECLOSION FONCTIONNELLE

        /*if (this->_isEclosion) {
            _mines[index].eclosion();
        }*/

        if (!myShip.checkCollision(_mines[index].box().getPolygon())){
            // On fait exploser la mine après qu'elle est percutée le vaisseau
             Explosion explosionMine(_mines[index].point());
             _explosions.push_back(explosionMine);
            _mines.erase(itMine);

            // le vaisseau explose après qu'il est percuté une mine
            Explosion explosionShip(QPoint(myShip.getShipLine().p2()));
            _explosions.push_back(explosionShip);

            //Vie du vaisseau - 1
            myShip.hited();

            //Fin de partie
            if(myShip.getLife() < 1){
                //Font for isWinning
                font.setPixelSize(60);
                painter.setFont(font);
                painter.drawText(250,400,this->endGame(false));
                painter.drawText(260,450,"Score : " + score);
                this->pause();
            }
        }
        else
            itMine++;
        index++;
    }

    // Set eclosion
    this->setIsEclosion(false);

    //Font gor Game components
    if (myShip.getLife() > 1){
        painter.drawText(750, 790, "Vie : " + shipVie);
        painter.drawText(720, 20, "Score : " + score);
    }

    if (_mines.size() == 0 && myShip.getLife() > 1) {
        //Font for isWinning
        font.setPixelSize(60);
        painter.setFont(font);
        painter.setPen(Qt::GlobalColor::red);
        painter.drawText(250,400,this->endGame(true));
        painter.drawText(260,450,"Score : " + score);
        this->pause();
    }

    //Dessin des balles
    myShip.drawBullet(painter, size(), _mines, _explosions);
    this->setScore(this->score() + myShip.getScoreFrame());

    //Dessin du vaisseaux
    if(myShip.getLife() > 1)
        myShip.draw(painter);
}


void Minestorm::goDown(){
    if (myShip.getCurrentSpeed() > 0) {
       myShip.setCurrentSpeed(myShip.getCurrentSpeed() - 1);
    }
}

void Minestorm::initMine()
{
    // QTimer
    //Timer timer(this);
    //mTimer.init();

    //Ajout de 20 mines moyennes
    for (int var = 0; var <= 1; ++var) {
        //addMines(QPoint(rand() %size().width(), rand() %size().height()), 10);
    }
    //Ajout de 5 mines petites
//    for (int i = 0; i <= 4; ++i) {
//        addMines(QPoint(rand() %size().width(), rand() %size().height()), 5);
//    }
//    //Ajout de 5 mines grandes
//    for (int j = 0; j <= 4; ++j) {
//        addMines(QPoint(rand() %size().width(), rand() %size().height()), 15);
//    }
}

void Minestorm::initialize()
{
    _mines.clear();
    _explosions.clear();
    Ship newShip;
    myShip = newShip;
    initMine();
}
void Minestorm::mousePressed( int x, int y) {
}
void Minestorm::keyPressed( int key ) {
    switch (key) {
    case Qt::Key_Left:myShip.rotateLeft();
        break;
    case Qt::Key_Right:myShip.rotateRight();
        break;
    case Qt::Key_Up:myShip.acceleration();
        break;
    case Qt::Key_Down:goDown();
        break;
    case Qt::Key_Space:myShip.fire();
        break;
    }
}
void Minestorm::keyReleased( int /* key */) {
}
void Minestorm::mouseReleased( int /* x */, int /* y */) {
}
void Minestorm::mouseMoved(int /* x */, int /* y */) {
}
