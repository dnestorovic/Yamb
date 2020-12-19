#include "StartWindow.h"

#include "ui_StartWindow.h"

using Communication::msg_header_t;

const std::string host = "127.0.0.1";
const std::string port = "5000";

void StartWindow::initializeGame() {
  w->establishConnection(client);
  w->show();
  this->hide();
}

StartWindow::StartWindow(QWidget* parent)
    : QDialog(parent),
      ui(new Ui::StartWindow),
      w(new Widget()),
      m_sound_choose(this),
      m_sound_start(this),
      m_sound_error(this),
      msgBox(this) {
  w->hide();
  ui->setupUi(this);

  /*
   * we want everything, except Create game
   * and Join game buttons to be hidden at first
   */
  ui->btnSingle->hide();
  ui->btnLocal->hide();
  ui->btnMulti->hide();

  ui->label->hide();
  ui->leID->hide();
  ui->btnJoin->hide();

  // setup for label image
  diceImageSetup();

  // setups for sound effects
  chooseSoundSetup();
  starSoundSetup();
  errorSoundSetup();

  msgBox.setText("Invalid ID or game is full");

  connect(this, &StartWindow::errorOccured, this, &StartWindow::errorShow);
  connect(this, &StartWindow::showWindow, this, &StartWindow::initializeGame);
}

StartWindow::~StartWindow() { delete ui; }

void StartWindow::on_btnCreate_clicked() {
  if (!ui->btnSingle->isHidden()) {
    ui->btnSingle->hide();
    ui->btnLocal->hide();
    ui->btnMulti->hide();
  } else {
    ui->btnSingle->show();
    ui->btnLocal->show();
    ui->btnMulti->show();
  }

  ui->label->hide();
  ui->leID->hide();
  ui->btnJoin->hide();
}

void StartWindow::on_btnJoinG_clicked() {
  if (!ui->label->isHidden()) {
    ui->label->hide();
    ui->leID->hide();
    ui->btnJoin->hide();
  }

  else {
    ui->label->show();
    ui->leID->show();
    ui->btnJoin->show();
  }

  ui->btnSingle->hide();
  ui->btnLocal->hide();
  ui->btnMulti->hide();
}

void StartWindow::parseMessage(Message& msg) {
  msg_header_t msg_type = msg.get_header().get_msg_id();
  std::cerr << msg << std::endl;

  if (msg_type == msg_header_t::SERVER_OK) {
    emit showWindow();
  } else if (msg_type == msg_header_t::SERVER_ERROR) {
    m_sound_error.play();
    emit errorOccured();
    client = nullptr;
  }
}

void StartWindow::on_btnJoin_clicked() {
  if (ui->leID->text().size() == 0) {
    m_sound_error.play();
    emit errorOccured();
  } else {
    // TODO: check for possible exceptions
    std::stringstream ss(ui->leID->text().toStdString());
    game_t gameId;
    ss >> gameId;
    client = new ConnectionClient(
        host, port, [this](Message& msg) { parseMessage(msg); }, gameId);
  }
}

void StartWindow::on_btnSingle_clicked() {
  client = new ConnectionClient(
      host, port, [this](Message& msg) { parseMessage(msg); }, 0);
  emit showWindow();
}

void StartWindow::on_btnLocal_clicked() {
  client = new ConnectionClient(
      host, port, [this](Message& msg) { parseMessage(msg); }, 0);
  emit showWindow();
}

void StartWindow::on_btnMulti_clicked() {
  client = new ConnectionClient(
      host, port, [this](Message& msg) { parseMessage(msg); }, 0);
  emit showWindow();
}

void StartWindow::errorShow() { msgBox.exec(); }

// rotating original image 45 degrees and setting it as background for label
void StartWindow::diceImageSetup() {
  QPixmap p1(":/img/img-dice5");
  QPixmap p2 = p1.transformed(QTransform().rotate(45));

  ui->label_2->setPixmap(p2);
  ui->label_2->setSizeIncrement(p2.size());
}

void StartWindow::chooseSoundSetup() {
  m_sound_choose.setSource(QUrl::fromLocalFile(":/sounds/sound-choose"));
  m_sound_choose.setVolume(0.9f);

  connect(ui->btnCreate, &QPushButton::clicked, &m_sound_choose,
          &QSoundEffect::play);
  connect(ui->btnJoinG, &QPushButton::clicked, &m_sound_choose,
          &QSoundEffect::play);
}

void StartWindow::starSoundSetup() {
  m_sound_start.setSource(QUrl::fromLocalFile(":/sounds/sound-roll"));
  m_sound_start.setVolume(0.5f);

  connect(ui->btnSingle, &QPushButton::clicked, &m_sound_start,
          &QSoundEffect::play);
  connect(ui->btnLocal, &QPushButton::clicked, &m_sound_start,
          &QSoundEffect::play);
  connect(ui->btnMulti, &QPushButton::clicked, &m_sound_start,
          &QSoundEffect::play);
}

void StartWindow::errorSoundSetup() {
  m_sound_error.setSource(QUrl::fromLocalFile(":/sounds/sound-error"));
  m_sound_error.setVolume(0.5f);
}
