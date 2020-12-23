#ifndef ENDGAMEWINDOW_H
#define ENDGAMEWINDOW_H

#include <QDialog>

namespace Ui {
class EndGameWindow;
}

class EndGameWindow : public QDialog {
  Q_OBJECT

 public:
  explicit EndGameWindow(QWidget *parent = nullptr);
  ~EndGameWindow();

 private slots:
  void on_btnExitGame_clicked();

 private:
  Ui::EndGameWindow *ui;
};

#endif  // ENDGAMEWINDOW_H
