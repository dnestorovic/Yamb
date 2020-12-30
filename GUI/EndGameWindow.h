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
  void setPoints(int you, int opponent);
  QPair<int, int> getPoints();

 private slots:
  void on_btnExitGame_clicked();

 signals:
  void endGameWindowClosed();

 private:
  Ui::EndGameWindow *ui;
  WinnerType winnerOfTheGame = WinnerType::YOU;
  QPair<int, int> points{0, 0};
};

#endif  // ENDGAMEWINDOW_H
