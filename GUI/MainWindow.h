#ifndef WIDGET_H
#define WIDGET_H

#include <QGraphicsScene>
#include <QMessageBox>
#include <QPushButton>
#include <QSoundEffect>
#include <QWidget>
#include <vector>
#include <QPropertyAnimation>

#include "../NetworkClient/ClientConnection.h"
#include "../NetworkCommon/RandomGenerator.h"
#include "../NetworkCommon/common.h"
#include "../Classes/Dice.h"
#include "EndGameWindow.h"
#include "WaitingWindow.h"

class QTableWidget;
enum volume_intensity { MUTE, LOW, MID, FULL };

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
  Q_OBJECT

 public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

  void establishConnection(ConnectionClient *client);
  void setVolumeIntensity(const volume_intensity intensity);
  volume_intensity getVolumeIntensity() const;
  void decreaseVolume();
  void sendMessage();
  void setDiceValue(Dice &, QPushButton *);
  void setDiceChecked(Dice &, QPushButton *);
  void setIsChatMuted(bool flag);
  bool getIsChatMuted() const;
  QPair<int,int> getSelectedTableCell();

 public slots:
  void diceRoll();
  void dice1Clicked();
  void dice2Clicked();
  void dice3Clicked();
  void dice4Clicked();
  void dice5Clicked();
  void dice6Clicked();

 private slots:
  void on_btnSmiley_clicked();
  void on_btnSmiley1_clicked();
  void on_btnSmiley2_clicked();
  void on_btnSmiley3_clicked();
  void on_btnSmiley4_clicked();
  void on_btnSmiley5_clicked();
  void on_btnSmiley6_clicked();
  void on_btnSmiley7_clicked();
  void on_btnSmiley8_clicked();
  void on_btnSmiley9_clicked();
  void on_btnSend_clicked();
  void on_btnMute_clicked();
  void on_btnSurrender_clicked();
  void on_btnFinishMove_clicked();

  void clearDice();
  void showAnimations();
  void finishGame();

  void updateLTable(int, int, int, int, int, int);
  void resetLTable();
  void updateRTable(int, int, int, int, int, int);

  void on_btnMuteChatSound_clicked();

  void on_btnMuteChat_clicked();

signals:
  void volumeIntesityChanged();
  void diceChanged();
  void gameFinished();
  void moveFinished();
  void animationsStarted();
  void messageReceived();
  void lTableUpdated(int, int, int, int, int, int);
  void lTableReset();
  void rTableUpdated(int, int, int, int, int, int);
  void opponentJoined();
  void gameCreated();

 private:
  void clickSoundSetup();
  void surrenderSoundSetup();
  void messageSoundSetup();
  void btnMuteChangeIcon();
  void updateChat(Message &msg);
  void messageParser(Message &msg);
  void addSmileyToText(QPushButton *button) const;
  void setWidthForTable(QTableWidget *table, int width);
  void tableSetup(QTableWidget *table, QString border_color);
  void updateDice();
  void setDiceButtonPicture(QPushButton *diceBtn, int index);
  void setSelectedTableCell();
  void openEndGameWindow();
  void scrollAreaHide();
  void showWaitingWindow();

 private:
  const int m_column_width = 30;

  Ui::Widget *ui;
  QSoundEffect m_click_sound;
  QSoundEffect m_surrender_sound;
  QSoundEffect m_message_sound;
  volume_intensity m_volume_intensity = FULL;
  std::shared_ptr<ConnectionClient> client;
  EndGameWindow* endGameWindow;
  WaitingWindow* waitingWindow;
  std::vector<Dice> dice;
  uint8_t rollCountdown;
  bool isChatMuted;
  std::vector<uint8_t> random_values;
  QVector<QPushButton*> diceButtons;
  QPropertyAnimation* animationL1,*animationL2,*animationL3,*animationL4,*animationL5,*animationL6;
  QPropertyAnimation* animationR1,*animationR2,*animationR3,*animationR4,*animationR5,*animationR6;

  QPair<int,int> selectedTableCell{-1, -1};
};
#endif  // WIDGET_H
