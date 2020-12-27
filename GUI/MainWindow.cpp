#include "MainWindow.h"

#include <QDebug>
#include <iostream>
#include <vector>

#include "../Classes/Dice.h"
#include "../NetworkCommon/RandomGenerator.h"
#include "../NetworkCommon/common.h"
#include "ui_MainWindow.h"

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
  } else if (msg_type == msg_header_t::SERVER_INTERMEDIATE_MOVE) {
    std::vector<int8_t> dice_values(NUM_OF_DICE);
    for (int8_t& x : dice_values) {
      msg >> x;
    }
    std::reverse(std::begin(dice_values), std::end(dice_values));

    for (int i = 0; i < NUM_OF_DICE; i++) {
      if (dice_values[i] < 0) {
        dice[i].set_selected(true);
        dice[i].set_value(-dice_values[i]);
      } else {
        if (dice[i].get_selected()) dice[i].set_selected(false);

        dice[i].set_value(dice_values[i]);
      }
    }

    emit diceChanged();
    emit animationsStarted();

    // Server notified participant for the new opponents roll
    // TODO: Show opponents dice on GUI ;
    //       argument: 6 values type int8_t;
    //       Negativ number is for selected dice
  } else if (msg_type == msg_header_t::SERVER_FINISH_MOVE) {
    if (client->get_owner_id() != msg.get_header().get_owner_id()) {
      client->set_is_my_turn(true);
      rollCountdown = ROLLS_PER_MOVE;
    }

    emit moveFinished();

    uint8_t row, col, score;
    msg >> score >> col >> row;
    if (client->get_owner_id() == msg.get_header().get_owner_id()) {
        emit lTableUpdated(row, col, score);
    } else {
        emit rTableUpdated(row, col, score);
    }
    // Check owner_id = my_id
    // Server notified participant that opponent has ended a move
    // TODO: Update opponents ticket on GUI ;
    //       arguments: row(uint8_t), col(uint8_t), value(int)
  } else if (msg_type == msg_header_t::SERVER_ERROR) {
    // TODO: notify about ERROR

    // In case move is illegal, player is stil on turn.
    std::cerr << "ILLEGAL MOVE" << std::endl;
    client->set_is_my_turn(true);
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
      m_message_sound(this),
      client(nullptr),
      endGameWindow(new EndGameWindow(this)),
      dice(std::vector<Dice>(NUM_OF_DICE)),
      rollCountdown(ROLLS_PER_MOVE) {
  ui->setupUi(this);

  // Animation for left player.
  animationL1 = new QPropertyAnimation(ui->dice1, "geometry");
  animationL1->setDuration(500);
  animationL1->setStartValue(QRect(0, 630, 101, 101));
  animationL1->setEndValue(ui->dice1->geometry());
  animationL2 = new QPropertyAnimation(ui->dice2, "geometry");
  animationL2->setDuration(500);
  animationL2->setStartValue(QRect(0, 630, 101, 101));
  animationL2->setEndValue(ui->dice2->geometry());
  animationL3 = new QPropertyAnimation(ui->dice3, "geometry");
  animationL3->setDuration(500);
  animationL3->setStartValue(QRect(0, 630, 101, 101));
  animationL3->setEndValue(ui->dice3->geometry());
  animationL4 = new QPropertyAnimation(ui->dice4, "geometry");
  animationL4->setDuration(500);
  animationL4->setStartValue(QRect(0, 630, 101, 101));
  animationL4->setEndValue(ui->dice4->geometry());
  animationL5 = new QPropertyAnimation(ui->dice5, "geometry");
  animationL5->setDuration(500);
  animationL5->setStartValue(QRect(0, 630, 101, 101));
  animationL5->setEndValue(ui->dice5->geometry());
  animationL6 = new QPropertyAnimation(ui->dice6, "geometry");
  animationL6->setDuration(500);
  animationL6->setStartValue(QRect(0, 630, 101, 101));
  animationL6->setEndValue(ui->dice6->geometry());

  // Animation for right player.
  animationR1 = new QPropertyAnimation(ui->dice1, "geometry");
  animationR1->setDuration(500);
  animationR1->setStartValue(QRect(1200, 630, 101, 101));
  animationR1->setEndValue(ui->dice1->geometry());
  animationR2 = new QPropertyAnimation(ui->dice2, "geometry");
  animationR2->setDuration(500);
  animationR2->setStartValue(QRect(1200, 630, 101, 101));
  animationR2->setEndValue(ui->dice2->geometry());
  animationR3 = new QPropertyAnimation(ui->dice3, "geometry");
  animationR3->setDuration(500);
  animationR3->setStartValue(QRect(1200, 630, 101, 101));
  animationR3->setEndValue(ui->dice3->geometry());
  animationR4 = new QPropertyAnimation(ui->dice4, "geometry");
  animationR4->setDuration(500);
  animationR4->setStartValue(QRect(1200, 630, 101, 101));
  animationR4->setEndValue(ui->dice4->geometry());
  animationR5 = new QPropertyAnimation(ui->dice5, "geometry");
  animationR5->setDuration(500);
  animationR5->setStartValue(QRect(1200, 630, 101, 101));
  animationR5->setEndValue(ui->dice5->geometry());
  animationR6 = new QPropertyAnimation(ui->dice6, "geometry");
  animationR6->setDuration(500);
  animationR6->setStartValue(QRect(1200, 630, 101, 101));
  animationR6->setEndValue(ui->dice6->geometry());

  // setup for both tables
  tableSetup(ui->tableL, "rgb(114, 159, 207)");
  connect(this, &Widget::lTableUpdated, this, &Widget::updateLTable);
  tableSetup(ui->tableR, "rgb(239, 41, 41)");
  connect(this, &Widget::rTableUpdated, this, &Widget::updateRTable);

  // We hide text edit with help so it could be seen only when ask button is
  // clicked
  ui->plainTextEdit->hide();
  connect(ui->btnAsk, &QPushButton::clicked, this, &Widget::hideText);

  // Setup for sounds.
  clickSoundSetup();
  surrenderSoundSetup();
  messageSoundSetup();

  // Connecting volume changer with MainWindow.
  connect(this, &Widget::volumeIntesityChanged, this,
          &Widget::btnMuteChangeIcon);

  // Connecting what will happen after move is finished.
  connect(this, &Widget::moveFinished, this, &Widget::clearDice);

  // Conecting animations with dice.
  connect(this, &Widget::animationsStarted, this, &Widget::showAnimations);

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

  ui->tableL->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->tableR->setEditTriggers(QAbstractItemView::NoEditTriggers);

  ui->tableR->setEnabled(false);

  diceButtons = {ui->dice1, ui->dice2, ui->dice3,
                 ui->dice4, ui->dice5, ui->dice6};

  connect(this, &Widget::diceChanged, this, &Widget::updateDice);
  connect(this, &Widget::gameFinished, this, &Widget::openEndGameWindow);
  connect(ui->tableL, &QTableWidget::pressed, this,
          &Widget::setSelectedTableCell);
  connect(ui->tableR, &QTableWidget::pressed, this,
          &Widget::setSelectedTableCell);

  // Initializing dice on the scene.
  ui->dice1->setEnabled(false);
  ui->dice2->setEnabled(false);
  ui->dice3->setEnabled(false);
  ui->dice4->setEnabled(false);
  ui->dice5->setEnabled(false);
  ui->dice6->setEnabled(false);
  clearDice();

  connect(endGameWindow, &EndGameWindow::endGameWindowClosed, this,
          &Widget::finishGame);
}

Widget::~Widget() { delete ui; }

void Widget::updateLTable(int row, int col, int score) {
    ui->tableL->setItem(row, col, new QTableWidgetItem(QString::number(score)));
}

void Widget::updateRTable(int row, int col, int score) {
    ui->tableR->setItem(row, col, new QTableWidgetItem(QString::number(score)));
}

void Widget::setDiceValue(Dice& d, QPushButton* diceb) {
  if (!d.get_selected()) {
    diceb->setStyleSheet("QPushButton {background-image: url(:/img/img-dice" +
                         QString::number(d.get_value()) + ");}");
  }
}

void Widget::clearDice() {
  for (auto& d : dice) {
    d.set_value(0);
    d.set_selected(false);
  }

  emit diceChanged();
}

void Widget::showAnimations() {
  // Animations are different depending on who is on turn.

  if (!client->get_is_my_turn()) {
    if (!dice[0].get_selected()) animationL1->start();
    if (!dice[1].get_selected()) animationL2->start();
    if (!dice[2].get_selected()) animationL3->start();
    if (!dice[3].get_selected()) animationL4->start();
    if (!dice[4].get_selected()) animationL5->start();
    if (!dice[5].get_selected()) animationL6->start();
  } else {
    if (!dice[0].get_selected()) animationR1->start();
    if (!dice[1].get_selected()) animationR2->start();
    if (!dice[2].get_selected()) animationR3->start();
    if (!dice[3].get_selected()) animationR4->start();
    if (!dice[4].get_selected()) animationR5->start();
    if (!dice[5].get_selected()) animationR6->start();
  }
}

void Widget::diceRoll() {
  if (client->get_is_my_turn() && rollCountdown) {
    ui->tableR->setEditTriggers(QAbstractItemView::AllEditTriggers);
    ui->tableL->setEditTriggers(QAbstractItemView::AllEditTriggers);

    std::vector<int8_t> currentDiceValues;
    for (Dice& d : dice) {
      if (!d.get_selected()) d.roll();

      int8_t tmpValue = d.get_value();
      if (d.get_selected()) tmpValue *= (-1);

      currentDiceValues.push_back(tmpValue);
    }

    // Participant sent dice values on server [6 x uint8_t value].
    Header header(Communication::msg_header_t::CLIENT_INTERMEDIATE_MOVE,
                  client->get_owner_id(), client->get_game_id());
    Message message(header);

    for (int8_t v : currentDiceValues) message << v;
    client->write(message);

    // Dice are available for selecting again.
    rollCountdown--;
    ui->dice1->setEnabled(true);
    setDiceValue(dice[0], ui->dice1);
    ui->dice2->setEnabled(true);
    setDiceValue(dice[1], ui->dice2);
    ui->dice3->setEnabled(true);
    setDiceValue(dice[2], ui->dice3);
    ui->dice4->setEnabled(true);
    setDiceValue(dice[3], ui->dice4);
    ui->dice5->setEnabled(true);
    setDiceValue(dice[4], ui->dice5);
    ui->dice6->setEnabled(true);
    setDiceValue(dice[5], ui->dice6);

    emit animationsStarted();
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

QPair<int, int> Widget::getSelectedTableCell() { return selectedTableCell; }

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
      m_message_sound.setVolume(0.5f);
      break;
    case MID:
      m_click_sound.setVolume(0.25f);
      m_message_sound.setVolume(0.25f);
      break;
    case LOW:
      m_click_sound.setVolume(0.15f);
      m_message_sound.setVolume(0.15f);
      break;
    case MUTE:
      m_click_sound.setVolume(0.0f);
      m_message_sound.setVolume(0.0f);
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
    emit messageRecieved();
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

  // Only one cell shoud be selected.
  table->setSelectionBehavior(QAbstractItemView::SelectItems);
  table->setSelectionMode(QAbstractItemView::SingleSelection);

  // Disables resizing rows and columns by user.
  table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
  table->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

  // Merging cells of first six rows in the last column.
  table->setSpan(0, 10, 6, 1);
}

void Widget::updateDice() {
  for (int i = 0; i < NUM_OF_DICE; i++) {
    setDiceButtonPicture(diceButtons[i], i);
  }
}

void Widget::setDiceButtonPicture(QPushButton* diceBtn, int index) {
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

void Widget::setSelectedTableCell() {
  if (client->get_is_my_turn()) {
    selectedTableCell.first = ui->tableL->currentRow();
    selectedTableCell.second = ui->tableL->currentColumn();
  } else {
    selectedTableCell.first = ui->tableR->currentRow();
    selectedTableCell.second = ui->tableR->currentColumn();
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
  m_click_sound.setSource(QUrl::fromLocalFile(":/sounds/sound-click"));

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
  connect(ui->btnFinishMove, &QPushButton::clicked, &m_click_sound,
          &QSoundEffect::play);
}

void Widget::surrenderSoundSetup() {
  m_surrender_sound.setSource(QUrl::fromLocalFile(":/sounds/sound-error"));
}

void Widget::messageSoundSetup() {
  m_message_sound.setSource(QUrl::fromLocalFile(":/sounds/sound-message"));
  connect(this, &Widget::messageRecieved, &m_message_sound,
          &QSoundEffect::play);
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
    // TODO: change this with function call.

    emit gameFinished();
    endGameWindow->setWinner(OPPONENT);
  }
}

void Widget::on_btnFinishMove_clicked() {
  if (client->get_is_my_turn()) {
    // Preparing message to server that client finished the move
    // Sending dice values and ticket field [body: row(uint8_t), col(uint8_t), 6
    // x (uint8_t)]
    Header header(Communication::msg_header_t::CLIENT_FINISH_MOVE,
                  client->get_owner_id(), client->get_game_id());
    Message message(header);

    std::vector<int8_t> currentDiceValues;
    for (int i = 0; i < NUM_OF_DICE; i++) {
      int8_t tmpValue = dice[i].get_value();

      // Negative value means selected dice
      if (dice[i].get_selected()) tmpValue *= (-1);

      currentDiceValues.push_back(tmpValue);
    }

    // TODO: get changed field coordinates (row, col)
    int8_t row = static_cast<uint8_t>(getSelectedTableCell().first);
    message << static_cast<uint8_t>(row);
    int8_t col = static_cast<uint8_t>(getSelectedTableCell().second);
    message << static_cast<uint8_t>(col);

    // How many rolls till end.
    message << rollCountdown;

    // Writing all dice.
    for (int8_t v : currentDiceValues) message << v;

    if (row != -1 && col != -1) {
      client->write(message);
      client->set_is_my_turn(false);
    } else {
      // TODO: don't allow
    }
  }
}

void Widget::openEndGameWindow() {
  this->setDisabled(true);
  endGameWindow->setDisabled(false);
  endGameWindow->show();
}

void Widget::finishGame() {
  // TODO: add closing connection.

  this->close();
}
