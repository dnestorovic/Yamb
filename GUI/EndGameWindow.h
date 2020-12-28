#ifndef ENDGAMEWINDOW_H
#define ENDGAMEWINDOW_H

#include <QDialog>

namespace Ui {
class EndGameWindow;
}

enum class WinnerType { YOU, OPPONENT };

class EndGameWindow : public QDialog {
  Q_OBJECT

 public:
  explicit EndGameWindow(QWidget *parent = nullptr);
  ~EndGameWindow();
  void setWinner(WinnerType winner);

 private slots:
  void on_btnExitGame_clicked();

 signals:
  void endGameWindowClosed();

 private:
  Ui::EndGameWindow *ui;
  WinnerType winnerOfTheGame = WinnerType::YOU;

};

#endif  // ENDGAMEWINDOW_H
