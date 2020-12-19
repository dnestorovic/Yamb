#include "EndGameWindow.h"

#include "ui_EndGameWindow.h"

EndGameWindow::EndGameWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::EndGameWindow) {
  ui->setupUi(this);
}

EndGameWindow::~EndGameWindow() { delete ui; }

void EndGameWindow::on_btnExitGame_clicked() { this->close(); }
