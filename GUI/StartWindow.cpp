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

  // setups for sound effects
  chooseSoundSetup();
  starSoundSetup();
  errorSoundSetup();

  msgBox.setText("Invalid ID or game is full");

  connect(this, &StartWindow::errorOccured, this, &StartWindow::errorShow);
  connect(this, &StartWindow::showMainWindow, this, &StartWindow::initializeGame);
}

StartWindow::~StartWindow() { delete ui; }

void StartWindow::initializeGame() {
  w->establishConnection(client);
  w->show();
  this->hide();
}

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
  std::cerr << "[thread_id]: " << std::this_thread::get_id() << std::endl;

  if (msg_type == msg_header_t::SERVER_OK) {
    emit showMainWindow();
  } else if (msg_type == msg_header_t::SERVER_ERROR) {
    m_sound_error.play();
    emit errorOccured();



    //-------------------------------------------
    // TODO: memory leaking
    client->close("[StartWindow::parseMessage]");
    //client->close_client();

    client = nullptr;
  }
}

void StartWindow::on_btnJoin_clicked() {
  std::string idText = ui->leID->text().toStdString();
  if (idText.length() > 0 && std::all_of(idText.begin(), idText.end(), ::isdigit))
  {
    std::stringstream ss(idText);
    game_t gameId;
    ss >> gameId;

    client = new ConnectionClient(
        host, port, [this](Message& msg) { parseMessage(msg); }, gameId, false);
  } else {
    m_sound_error.play();
    emit errorShow();
  }
}

void StartWindow::on_btnSingle_clicked() {
  client = new ConnectionClient(
      host, port, [this](Message& msg) { parseMessage(msg); }, 0, true);
}

void StartWindow::on_btnLocal_clicked() {
  client = new ConnectionClient(
      host, port, [this](Message& msg) { parseMessage(msg); }, 0, true);
}

void StartWindow::on_btnMulti_clicked() {
  client = new ConnectionClient(
      host, port, [this](Message& msg) { parseMessage(msg); }, 0, true);
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
