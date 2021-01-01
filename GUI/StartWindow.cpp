#include "StartWindow.h"

#include "ui_StartWindow.h"

using Communication::msg_header_t;

const std::string host = "127.0.0.1";
const std::string port = "5000";

StartWindow::StartWindow(QWidget* parent)
    : QDialog(parent),
      ui(new Ui::StartWindow),
      w(new Widget()),
      m_sound_choose(this),
      m_sound_start(this),
      m_sound_error(this),
      msgBox(this),
      client(nullptr) {
  ui->setupUi(this);
  w->hide();

  setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  move(QGuiApplication::screens().at(0)->geometry().center() -
       frameGeometry().center());

  /*
   * we want everything, except Create game
   * and Join game buttons to be hidden at first
   */
  ui->btnSingle->hide();
  ui->btnMulti->hide();

  ui->label->hide();
  ui->leID->hide();
  ui->btnJoin->hide();

  // setups for sound effects
  chooseSoundSetup();
  startSoundSetup();
  errorSoundSetup();

  msgBox.setText("Invalid ID or game is full!");
  msgBox.setWindowTitle("Login error");
  msgBox.setIcon(QMessageBox::Warning);

  connect(this, &StartWindow::errorOccured, this, &StartWindow::errorShow);
  connect(this, &StartWindow::showMainWindow, this,
          &StartWindow::initializeGame);
}

StartWindow::~StartWindow() { delete ui; }

void StartWindow::initializeGame() {
  w->establishConnection(std::move(client));

  if (getGameMode() == CREATE) {
    this->hide();
    emit w->gameCreated();
  } else {
    w->show();
  }
  this->hide();
}

void StartWindow::on_btnCreate_clicked() {
  if (!ui->btnSingle->isHidden()) {
    ui->btnSingle->hide();
    ui->btnMulti->hide();
  } else {
    ui->btnSingle->show();
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
  ui->btnMulti->hide();
}

void StartWindow::parseMessage(Message& msg) {
  msg_header_t msg_type = msg.get_header().get_msg_id();
  std::cerr << msg << std::endl;

  if (msg_type == msg_header_t::SERVER_OK) {
    emit showMainWindow();
  } else if (msg_type == msg_header_t::SERVER_ERROR) {
    m_sound_error.play();
    emit errorOccured();

    client->close("[StartWindow::parseMessage]");
  }
}

void StartWindow::on_btnJoin_clicked() {
  setGameMode(JOIN);

  std::string idText = ui->leID->text().toStdString();
  if (idText.length() > 0 &&
      std::all_of(idText.begin(), idText.end(), ::isdigit)) {
    std::stringstream ss(idText);
    game_t gameId;
    ss >> gameId;

    // In case connection that previously failed exists.
    if (client != nullptr) {
      client.reset();
    }

    client = std::unique_ptr<Connection>(new Connection(
        host, port, [this](Message& msg) { parseMessage(msg); }, gameId));
  } else {
    m_sound_error.play();
    emit errorShow();
  }
}

void StartWindow::on_btnSingle_clicked() {
  setGameMode(CREATE);
  client = std::unique_ptr<Connection>(new Connection(
      host, port, [this](Message& msg) { parseMessage(msg); },
      WAITING_ROOM_ID));
}

void StartWindow::on_btnMulti_clicked() {
  setGameMode(CREATE);
  client = std::unique_ptr<Connection>(new Connection(
      host, port, [this](Message& msg) { parseMessage(msg); },
      WAITING_ROOM_ID));
}

void StartWindow::errorShow() { msgBox.show(); }

void StartWindow::chooseSoundSetup() {
  m_sound_choose.setSource(QUrl::fromLocalFile(":/sounds/sound-choose"));
  m_sound_choose.setVolume(0.9f);

  connect(ui->btnCreate, &QPushButton::clicked, &m_sound_choose,
          &QSoundEffect::play);
  connect(ui->btnJoinG, &QPushButton::clicked, &m_sound_choose,
          &QSoundEffect::play);
}

void StartWindow::startSoundSetup() {
  m_sound_start.setSource(QUrl::fromLocalFile(":/sounds/sound-roll"));
  m_sound_start.setVolume(0.5f);

  connect(ui->btnSingle, &QPushButton::clicked, &m_sound_start,
          &QSoundEffect::play);
  connect(ui->btnMulti, &QPushButton::clicked, &m_sound_start,
          &QSoundEffect::play);
}

void StartWindow::errorSoundSetup() {
  m_sound_error.setSource(QUrl::fromLocalFile(":/sounds/sound-error"));
  m_sound_error.setVolume(0.5f);
}

void StartWindow::setGameMode(GameMode mode) { gameMode = mode; }

GameMode StartWindow::getGameMode() { return gameMode; }

void StartWindow::on_btnExit_clicked() { this->close(); }
