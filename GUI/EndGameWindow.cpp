#include "EndGameWindow.h"
#include "ui_EndGameWindow.h"

EndGameWindow::EndGameWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::EndGameWindow) {
  ui->setupUi(this);

  //setStyleSheet("background:transparent");
  //setAttribute(Qt::WA_TranslucentBackground);
  //setWindowFlags(Qt::FramelessWindowHint);

  //setModal(true);
}

EndGameWindow::~EndGameWindow() { delete ui; }

void EndGameWindow::setWinner(winnerType winner)
{
    winnerOfTheGame = winner;
    if(winnerOfTheGame == OPPONENT)
        ui->labelWinner->setText("Opponent");
    else
        ui->labelWinner->setText("You");
}

void EndGameWindow::on_btnExitGame_clicked() {

    emit endGameWindowClosed();
    this->close();

}
