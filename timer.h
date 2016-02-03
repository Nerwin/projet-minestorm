#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QDebug>

class QTimer;

class Timer : public QObject
{
    Q_OBJECT
public:
    explicit Timer(QObject *parent = 0);

public:
    QTimer *_timer;


signals:

public slots:
    void onTimeOut();

};

#endif // TIMER_H
