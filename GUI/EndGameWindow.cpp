#include "EndGameWindow.h"
#include "ui_EndGameWindow.h"

EndGameWindow::EndGameWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::EndGameWindow) {
  ui->setupUi(this);

  //setStyleSheet("background:transparent");
  //setAttribute(Qt::WA_TranslucentBackground);
  //setWindowFlags(Qt::FramelessWindowHint);

  //setModal(true);

  parent->setDisabled(true);
  setEnabled(true);
}

EndGameWindow::~EndGameWindow() { delete ui; }

void EndGameWindow::on_btnExitGame_clicked() { this->close(); }
