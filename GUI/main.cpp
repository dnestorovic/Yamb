#include "MainWindow.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QApplication>
#include <QObject>
#include <QGraphicsScene>
#include "StartWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow s;
    s.show();
    return a.exec();
}
