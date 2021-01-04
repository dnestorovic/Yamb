#include "EndGameWindow.h"

#include "ui_EndGameWindow.h"

EndGameWindow::EndGameWindow(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::EndGameWindow),
      winnerOfTheGame(WinnerType::YOU) {
  ui->setupUi(this);

  setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

  // setModal(true);
}

EndGameWindow::~EndGameWindow() { delete ui; }

void EndGameWindow::setWinner(WinnerType winner) {
  winnerOfTheGame = winner;
  if (winnerOfTheGame == WinnerType::OPPONENT)
    ui->labelWinner->setText("YOU LOSE");
  else
    ui->labelWinner->setText("YOU WIN");

}

void EndGameWindow::on_btnExitGame_clicked() {
  emit endGameWindowClosed();
  this->close();
}
