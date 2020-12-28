#include "EndGameWindow.h"
#include "ui_EndGameWindow.h"

EndGameWindow::EndGameWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::EndGameWindow), winnerOfTheGame(WinnerType::YOU) {
  ui->setupUi(this);

  //setStyleSheet("background:transparent");
  //setAttribute(Qt::WA_TranslucentBackground);
  //setWindowFlags(Qt::FramelessWindowHint);

  //setModal(true);
}

EndGameWindow::~EndGameWindow() { delete ui; }

void EndGameWindow::setWinner(WinnerType winner) {
    winnerOfTheGame = winner;
    if(winnerOfTheGame == WinnerType::OPPONENT)
        ui->labelWinner->setText("Opponent");
    else
        ui->labelWinner->setText("You");
}

void EndGameWindow::on_btnExitGame_clicked() {
    emit endGameWindowClosed();

    this->close();
}
