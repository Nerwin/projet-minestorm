#include "mainwindow.h"
#include "dummygame.h"
#include "minestorm.h"
#include <QSize>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //DummyGame game(QSize(400,400));
    Minestorm game(QSize(800,800));
    MainWindow w(&game);
    return a.exec();
}
