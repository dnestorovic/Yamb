#include "MainWindow.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QApplication>
#include <QObject>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
