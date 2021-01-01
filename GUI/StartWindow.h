#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QSoundEffect>

#include "../NetworkCommon/Message.h"
#include "../NetworkCommon/RandomGenerator.h"
#include "../NetworkClient/Connection.h"
#include "MainWindow.h"

enum GameMode { CREATE, JOIN };

namespace Ui {
class StartWindow;
}

class StartWindow : public QDialog {
  Q_OBJECT

 public:
  explicit StartWindow(QWidget *parent = nullptr);
  ~StartWindow();

 private slots:
  void initializeGame();
  void errorShow();
  void on_btnCreate_clicked();
  void on_btnJoinG_clicked();
  void on_btnJoin_clicked();
  void on_btnSingle_clicked();
  void on_btnMulti_clicked();

  void on_btnExit_clicked();

 private:
  void parseMessage(Message &msg);
  void chooseSoundSetup();
  void startSoundSetup();
  void errorSoundSetup();
  void setGameMode(GameMode mode);
  GameMode getGameMode();

 signals:
  void showMainWindow();
  void errorOccured();

 private:
  Ui::StartWindow *ui;
  Widget *w;
  QSoundEffect m_sound_choose;
  QSoundEffect m_sound_start;
  QSoundEffect m_sound_error;
  QMessageBox msgBox;
  std::unique_ptr<Connection> client;
  GameMode gameMode = JOIN;
};

#endif  // STARTWINDOW_H
