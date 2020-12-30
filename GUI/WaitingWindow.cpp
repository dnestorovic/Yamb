#include "WaitingWindow.h"

#include "ui_WaitingWindow.h"

WaitingWindow::WaitingWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::WaitingWindow) {
  ui->setupUi(this);

  ui->labelGameId->setTextInteractionFlags(Qt::TextSelectableByMouse);

  QMovie *movie = new QMovie(":/img/gif-dice");
  ui->labelGif->setMovie(movie);
  ui->labelGif->show();
  movie->start();

  setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  move(QGuiApplication::screens().at(0)->geometry().center() -
       frameGeometry().center());
}

WaitingWindow::~WaitingWindow() { delete ui; }

void WaitingWindow::setId(QString id) { ui->labelGameId->setText(id); }

void WaitingWindow::on_pushButton_clicked() {
  emit gameExitedWhileWaiting();
  this->close();
}
