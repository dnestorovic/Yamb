#include <QStyle>
#include <QDesktopWidget>
#include <QApplication>
#include <QObject>
#include <QGraphicsScene>

#include "MainWindow.h"
#include "StartWindow.h"
#include "../Classes/Dice.h"

int main(int argc, char *argv[])
{
    std::vector<Dice> dice(6);
    for (int i=0;i<6;i++)
        dice[i]=Dice();

    QApplication a(argc, argv);
    StartWindow s;
    s.show();
    return a.exec();
}
