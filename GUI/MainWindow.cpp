#include "MainWindow.h"

#include <QDebug>
#include <iostream>
#include <vector>

#include "../Classes/Dice.h"
#include "../NetworkCommon/RandomGenerator.h"
#include "ui_MainWindow.h"
#include "../NetworkCommon/common.h"

using Communication::msg_header_t;

const std::string host = "127.0.0.1";
const std::string port = "5000";

void Widget::messageParser(Message& msg) {
  msg_header_t msg_type = msg.get_header().get_msg_id();
  std::cerr << msg << std::endl;

  if (msg_type == msg_header_t::SERVER_CHAT) {
    updateChat(msg);
  } else if (msg_type == msg_header_t::CLIENT_CHAT) {
    updateChat(msg);
  } else if (msg_type == msg_header_t::SERVER_END_GAME) {
    // TODO: does owner_id won or lost the game? for now lost

    if (client->get_owner_id() == msg.get_header().get_owner_id()) {
      std::cout << "You lost" << std::endl;
    } else {
      std::cout << "You won" << std::endl;
    }

    exit(1);
  } else if(msg_type == msg_header_t::SERVER_INTERMEDIATE_MOVE)
  {

    std::vector<int8_t> dice_values(NUM_OF_DICE);
      for(int8_t& x : dice_values)
      {
          msg >> x;
      }
      std::reverse(std::begin(dice_values), std::end(dice_values));

      for(int i = 0; i < NUM_OF_DICE ; i++) {

          if(dice_values[i] < 0) {
              dice[i].set_selected(true);
              dice[i].set_value(-dice_values[i]);
          }
          else {
              dice[i].set_value(dice_values[i]);
          }
      }

      emit diceChanged();

      // Server notified participant for the new opponents roll
      // TODO: Show opponents dice on GUI ;
      //       argument: 6 values type int8_t;
      //       Negativ number is for selected dice
  } else if(msg_type == msg_header_t::SERVER_FINISH_MOVE)
  {
      // Check owner_id = my_id
      // Server notified participant that opponent has ended a move
      // TODO: Update opponents ticket on GUI ;
      //       arguments: row(uint8_t), col(uint8_t), value(int)
  }
}

void Widget::establishConnection(ConnectionClient* other) {
  client = std::shared_ptr<ConnectionClient>(other);

  // It's very important to change callback from StartWindow to MainWindow!
  client->set_read_callback([this](Message& msg) { messageParser(msg); });
}

Widget::Widget(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::Widget),
      m_click_sound(this),
      client(nullptr),
      dice(std::vector<Dice>(NUM_OF_DICE)),
      rollCountdown(ROLLS_PER_MOVE) {
  ui->setupUi(this);

  // setup for both tables
  tableSetup(ui->tableL, "rgb(114, 159, 207)");
  tableSetup(ui->tableR, "rgb(239, 41, 41)");

  // We hide text edit with help so it could be seen only when ask button is
  // clicked
  ui->plainTextEdit->hide();
  connect(ui->btnAsk, &QPushButton::clicked, this, &Widget::hideText);

  // Setup for sounds.
  clickSoundSetup();
  surrenderSoundSetup();

  // Connecting volume changer with MainWindow.
  connect(this, &Widget::volumeIntesityChanged, this,
          &Widget::btnMuteChangeIcon);

  // Setup for chat buttons.
  ui->btnSend->setFixedWidth(45);
  ui->btnSmiley->setFixedWidth(45);
  // Initially scroll area with emojis should be hidden.
  ui->scrollArea->hide();

  // Connecting btnThrow and MainWindow.
  connect(ui->btnThrow, &QPushButton::clicked, this, &Widget::diceRoll);

  // Connecting btnDice and MainWindow.
  // Disables dice buttons so they can't be clicked.
  ui->dice1->setEnabled(false);
  connect(ui->dice1, &QPushButton::clicked, this, &Widget::dice1Clicked);
  ui->dice2->setEnabled(false);
  connect(ui->dice2, &QPushButton::clicked, this, &Widget::dice2Clicked);
  ui->dice3->setEnabled(false);
  connect(ui->dice3, &QPushButton::clicked, this, &Widget::dice3Clicked);
  ui->dice4->setEnabled(false);
  connect(ui->dice4, &QPushButton::clicked, this, &Widget::dice4Clicked);
  ui->dice5->setEnabled(false);
  connect(ui->dice5, &QPushButton::clicked, this, &Widget::dice5Clicked);
  ui->dice6->setEnabled(false);
  connect(ui->dice6, &QPushButton::clicked, this, &Widget::dice6Clicked); 

  diceButtons = {ui->dice1,ui->dice2,ui->dice3,ui->dice4,ui->dice5,ui->dice6};

  connect(this,&Widget::diceChanged,this,&Widget::changeDice);
  connect(this,&Widget::gameFinished,this,&Widget::finishGame);
}

Widget::~Widget() { delete ui; }

void Widget::setDiceValue(Dice& d, QPushButton* diceb) {
  if (!d.get_selected()) {
    diceb->setStyleSheet("QPushButton {background-image: url(:/img/img-dice" +
                         QString::number(d.get_value()) + ");}");
  }
}

void Widget::diceRoll() {
  rollCountdown--;

  for (Dice& d : dice) {
    if (!d.get_selected())
      d.roll();
  }

  // Prepareing new message for server about dice values.
  std::vector<int8_t> currentDiceValues;
  for(int i = 0; i < NUM_OF_DICE; i++)
  {
    int8_t tmpValue = dice[i].get_value();

    // Negative value means selected dice
    if(dice[i].get_selected())
        tmpValue *= (-1);

    currentDiceValues.push_back(tmpValue);
  }

  // Participant sent dice values on server [6 x uint8_t value].
  Header header(Communication::msg_header_t::CLIENT_INTERMEDIATE_MOVE,
                  client->get_owner_id(), client->get_game_id());
  Message message(header);

  for (int8_t v : currentDiceValues) message << v;
  client->write(message);

  // Dice are available for selecting again.
  ui->dice1->setEnabled(true);
  ui->dice2->setEnabled(true);
  ui->dice3->setEnabled(true);
  ui->dice4->setEnabled(true);
  ui->dice5->setEnabled(true);
  ui->dice6->setEnabled(true);

  if (rollCountdown >= 0) {
    if (rollCountdown == 0) {
      ui->btnThrow->setEnabled(false);
    }

    setDiceValue(dice[0], ui->dice1);
    setDiceValue(dice[1], ui->dice2);
    setDiceValue(dice[2], ui->dice3);
    setDiceValue(dice[3], ui->dice4);
    setDiceValue(dice[4], ui->dice5);
    setDiceValue(dice[5], ui->dice6);
  } else {
    ui->btnThrow->setEnabled(false);
  }
}

// checks if dice was clicked or unclicked
void Widget::setDiceChecked(Dice& d, QPushButton* diceBtn) {
  // if we rolled dice atleast once we can check it
  if (rollCountdown < 3 && rollCountdown >= 0) {
    d.set_selected(!d.get_selected());
    diceBtn->setStyleSheet(
        "QPushButton {background-image: url(:/img/img-dice" +
        QString::number(d.get_value()) + ");" +
        (((d.get_selected())) ? " border:2px solid blue;}" : "}"));
  } else {
    diceBtn->setStyleSheet(
        ("QPushButton {background-image: url(:/img/img-dice" +
         QString::number(d.get_value()) + ");" + "}"));
  }
}

void Widget::dice1Clicked() { setDiceChecked(dice[0], ui->dice1); }
void Widget::dice2Clicked() { setDiceChecked(dice[1], ui->dice2); }
void Widget::dice3Clicked() { setDiceChecked(dice[2], ui->dice3); }
void Widget::dice4Clicked() { setDiceChecked(dice[3], ui->dice4); }
void Widget::dice5Clicked() { setDiceChecked(dice[4], ui->dice5); }
void Widget::dice6Clicked() { setDiceChecked(dice[5], ui->dice6); }

void Widget::hideText() {
  (!(ui->plainTextEdit->isHidden())) ? ui->plainTextEdit->hide()
                                     : ui->plainTextEdit->show();
}

void Widget::setVolumeIntensity(const volume_intensity intensity) {
  switch (intensity) {
    case FULL:
      m_click_sound.setVolume(0.5f);
      break;
    case MID:
      m_click_sound.setVolume(0.25f);
      break;
    case LOW:
      m_click_sound.setVolume(0.15f);
      break;
    case MUTE:
      m_click_sound.setVolume(0.0f);
      break;

    default:
      break;
  }

  m_volume_intensity = intensity;
  emit volumeIntesityChanged();
}

volume_intensity Widget::getVolumeIntensity() const {
  return m_volume_intensity;
}

void Widget::decreaseVolume() {
  switch (getVolumeIntensity()) {
    case FULL:
      setVolumeIntensity(MID);
      break;
    case MID:
      setVolumeIntensity(LOW);
      break;
    case LOW:
      setVolumeIntensity(MUTE);
      break;
    case MUTE:
      setVolumeIntensity(FULL);
      break;

    default:
      break;
  }
}

void Widget::on_btnMute_clicked() { decreaseVolume(); }

void Widget::updateChat(Message& msg) {
  uint32_t size = msg.get_header().get_size();
  std::string content;
  for (uint32_t i = 0; i < size; i++) {
    char c;
    msg >> c;
    content += c;
  }
  // message's content is kept in a stack maneer
  std::reverse(content.begin(), content.end());

  // distinguishing who has sent the message
  if (msg.get_header().get_owner_id() == client->get_owner_id()) {
    content = "You: " + content;
  } else {
    content = "Opponent: " + content;
  }

  int last_item_index = ui->lChat->count();
  ui->lChat->addItem(QString::fromUtf8(content.c_str()));
  ui->lChat->item(last_item_index)->setTextAlignment(Qt::AlignLeft);
  ui->leMessage->setText("");
}

// sends message written in leChat
void Widget::on_btnSend_clicked() {
  if (ui->leMessage->text().size() > 0) {
    Header header(Communication::msg_header_t::CLIENT_CHAT,
                  client->get_owner_id(), client->get_game_id());
    Message message(header);
    std::string content = ui->leMessage->text().toUtf8().constData();
    for (char c : content) message << c;
    client->write(message);
  }
}

// sets width for columns of the table
void Widget::setWidthForTable(QTableWidget* table, int width) {
  for (short i = 0; i < table->columnCount() - 1; i++)
    table->setColumnWidth(i, width);

  // the last column is slightly wider
  table->setColumnWidth(table->columnCount() - 1, width + 20);
}

void Widget::tableSetup(QTableWidget* table, QString border_color) {
  setWidthForTable(table, m_column_width);
  table->setStyleSheet(
      ("QTableWidget {border : 5px solid " + border_color + " ;}"));

  //Only one cell shoud be selected.
  table->setSelectionBehavior( QAbstractItemView::SelectItems );
  table->setSelectionMode( QAbstractItemView::SingleSelection );

  // merging cells of first six rows in the last column
  table->setSpan(0, 10, 6, 1);
}

void Widget::changeDice()
{

    for(int i = 0; i < NUM_OF_DICE; i++){

        setDiceButtonPicture(diceButtons[i],i);
    }

}

void Widget::setDiceButtonPicture(QPushButton *diceBtn, int index) {

    if (dice[index].get_selected()) {
      diceBtn->setStyleSheet(
          "QPushButton {background-image: url(:/img/img-dice" +
          QString::number(dice[index].get_value()) + ");" +
          (((dice[index].get_selected())) ? " border:2px solid blue;}" : "}"));
    } else {
      diceBtn->setStyleSheet(
          ("QPushButton {background-image: url(:/img/img-dice" +
           QString::number(dice[index].get_value()) + ");" + "}"));
    }
}

// opens scrollarea which contains emojis
void Widget::on_btnSmiley_clicked() {
  (ui->scrollArea->isHidden()) ? ui->scrollArea->show()
                               : ui->scrollArea->hide();
}

// adds emoji from button(forwarded as argument) to the text inside of leChat
void Widget::addSmileyToText(QPushButton* button) const {
  ui->leMessage->setText(ui->leMessage->text() + button->text());
}

void Widget::clickSoundSetup() {
  // setting-up click sound
  m_click_sound.setSource(QUrl::fromLocalFile(":/sounds/sound-click"));

  // playing sound when button is clicked
  connect(ui->btnAsk, &QPushButton::clicked, &m_click_sound,
          &QSoundEffect::play);
  connect(ui->btnSend, &QPushButton::clicked, &m_click_sound,
          &QSoundEffect::play);
  connect(ui->btnThrow, &QPushButton::clicked, &m_click_sound,
          &QSoundEffect::play);
  connect(ui->btnMute, &QPushButton::clicked, &m_click_sound,
          &QSoundEffect::play);
  connect(ui->btnSmiley, &QPushButton::clicked, &m_click_sound,
          &QSoundEffect::play);
}

void Widget::surrenderSoundSetup() {
  m_surrender_sound.setSource(QUrl::fromLocalFile(":/sounds/sound-error"));
}

void Widget::btnMuteChangeIcon() {
  switch (getVolumeIntensity()) {
    case FULL:
      ui->btnMute->setIcon(QIcon(":/img/img-speaker_f"));
      break;
    case MID:
      ui->btnMute->setIcon(QIcon(":/img/img-speaker_m"));
      break;
    case LOW:
      ui->btnMute->setIcon(QIcon(":/img/img-speaker_l"));
      break;
    case MUTE:
      ui->btnMute->setIcon(QIcon(":/img/img-speaker_mute"));
      break;
    default:
      break;
  }
}

void Widget::on_btnSmiley1_clicked() { addSmileyToText(ui->btnSmiley1); }
void Widget::on_btnSmiley2_clicked() { addSmileyToText(ui->btnSmiley2); }
void Widget::on_btnSmiley3_clicked() { addSmileyToText(ui->btnSmiley3); }
void Widget::on_btnSmiley4_clicked() { addSmileyToText(ui->btnSmiley4); }
void Widget::on_btnSmiley5_clicked() { addSmileyToText(ui->btnSmiley5); }
void Widget::on_btnSmiley6_clicked() { addSmileyToText(ui->btnSmiley6); }
void Widget::on_btnSmiley7_clicked() { addSmileyToText(ui->btnSmiley7); }
void Widget::on_btnSmiley8_clicked() { addSmileyToText(ui->btnSmiley8); }
void Widget::on_btnSmiley9_clicked() { addSmileyToText(ui->btnSmiley9); }

void Widget::on_btnSurrender_clicked() {
  m_surrender_sound.play();

  auto btn = QMessageBox::question(this, "Surrender", "Are you sure?");

  if (btn == QMessageBox::Yes) {
    emit gameFinished();
  }
}

void Widget::on_btnFinishMove_clicked() {
    // Preparing message to server that client finished the move
    // Sending dice values and ticket field [body: row(uint8_t), col(uint8_t), 6 x (uint8_t)]
    Header header(Communication::msg_header_t::CLIENT_FINISH_MOVE,
                  client->get_owner_id(), client->get_game_id());
    Message message(header);

    std::vector<int8_t> currentDiceValues;
    for(int i = 0; i < NUM_OF_DICE; i++)
    {
      int8_t tmpValue = dice[i].get_value();

      // Negative value means selected dice
      if(dice[i].get_selected())
          tmpValue *= (-1);

      currentDiceValues.push_back(tmpValue);
    }

    // TODO: get changed field coordinates (row, col)
    uint8_t row = 1;
    uint8_t col = 1;

    message << row;
    message << col;
    for (int8_t v : currentDiceValues) message << v;

    client->write(message);

}

void Widget::finishGame()
{   
    e = new EndGameWindow(this);
    e->show();
}
