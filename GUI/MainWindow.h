#ifndef WIDGET_H
#define WIDGET_H

#include <QGraphicsScene>
#include <QMessageBox>
#include <QPushButton>
#include <QSoundEffect>
#include <QWidget>
#include <vector>

#include "../NetworkClient/ClientConnection.h"
#include "../NetworkCommon/RandomGenerator.h"
#include "../Classes/Dice.h"
#include "EndGameWindow.h"

class QTableWidget;

enum class GameType { SINGLE, LOCAL, MULTI };

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
  void hideText();
  void setVolumeIntensity(const volume_intensity intensity);
  volume_intensity getVolumeIntensity() const;
  void decreaseVolume();
  void sendMessage();
  void setDiceValue(Dice *, QPushButton *,int );
  void setDiceChecked(Dice &, QPushButton *);

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

 signals:
  void volumeIntesityChanged();

 private:
  void clickSoundSetup();
  void surrenderSoundSetup();
  void btnMuteChangeIcon();
  void updateChat(Message &msg);
  void messageParser(Message &msg);
  void addSmileyToText(QPushButton *button) const;
  void setWidthForTable(QTableWidget *table, int width);
  void tableSetup(QTableWidget *table, QString border_color);

 private:
  const int m_column_width = 30;
  Ui::Widget *ui;
  QSoundEffect m_click_sound;
  QSoundEffect m_surrender_sound;
  volume_intensity m_volume_intensity = FULL;
  std::shared_ptr<ConnectionClient> client;
  QDialog *e;
  std::vector<Dice> dice;
  int rollCountdown;
  std::vector<uint8_t> random_values;
};
#endif  // WIDGET_H
