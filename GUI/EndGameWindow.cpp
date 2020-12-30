#include "EndGameWindow.h"
#include "ui_EndGameWindow.h"

EndGameWindow::EndGameWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::EndGameWindow), winnerOfTheGame(WinnerType::YOU) {
  ui->setupUi(this);

  setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

  //setModal(true);
}

EndGameWindow::~EndGameWindow() { delete ui; }

void EndGameWindow::setWinner(WinnerType winner) {
    winnerOfTheGame = winner;
    if(winnerOfTheGame == WinnerType::OPPONENT)
        ui->labelWinner->setText("YOU LOSE");
    else
        ui->labelWinner->setText("YOU WIN");

    ui->labelPointsYou->setText(QString::number(getPoints().first));
    ui->labelPointsOpponent->setText(QString::number(getPoints().second));
}

void EndGameWindow::setPoints(int you, int opponent)
{
    points.first = you;
    points.second = opponent;
}

QPair<int, int> EndGameWindow::getPoints()
{
    return points;
}

void EndGameWindow::on_btnExitGame_clicked() {

    emit endGameWindowClosed();
    this->close();
}
