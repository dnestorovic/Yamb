#ifndef ENDGAMEWINDOW_H
#define ENDGAMEWINDOW_H

#include <QDialog>

namespace Ui {
class EndGameWindow;
}

enum winnerType { YOU, OPPONENT };

class EndGameWindow : public QDialog {
  Q_OBJECT

 public:
  explicit EndGameWindow(QWidget *parent = nullptr);
  ~EndGameWindow();
  void setWinner(winnerType winner);

 private slots:
  void on_btnExitGame_clicked();

 signals:
  void endGameWindowClosed();

 private:
  Ui::EndGameWindow *ui;
  winnerType winnerOfTheGame = YOU;

};

#endif  // ENDGAMEWINDOW_H
