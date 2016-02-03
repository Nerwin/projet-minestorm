#include "timer.h"
#include <QDebug>
#include <QTimer>


Timer::Timer(QObject *parent) :
    QObject(parent)
{
    //_timer = new QTimer(this);
    //connect(_timer,SIGNAL(timeout()),this,SLOT(onTimeOut()));
    QTimer* timer = new QTimer(0); //parent must be null
    timer->setInterval(1);

    connect(timer, SIGNAL(timeout()), SLOT(onTimeOut()), Qt::DirectConnection);

    timer->start(1000);
}

void Timer::onTimeOut()
{
    qDebug() << "eclosion";
}
