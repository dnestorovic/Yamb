#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsScene>
#include <QObject>
#include <QStyle>

#include "../Classes/Dice.h"
#include "MainWindow.h"
#include "StartWindow.h"

int main(int argc, char *argv[]) {
  std::vector<Dice> dice(6);
  for (int i = 0; i < 6; i++) dice[i] = Dice();

  QApplication a(argc, argv);
  StartWindow s;
  s.show();
  return a.exec();
}
