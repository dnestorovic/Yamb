#include "StartWindow.h"
#include "ui_StartWindow.h"

using Communication::msg_header_t;

const std::string host = "127.0.0.1";
const std::string port = "5000";

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow),
    m_sound_choose(this),
    m_sound_start(this),
    m_sound_error(this),
    msgBox(this)
{
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

    //setup for label image
    diceImageSetup();

    //setups for sound effects
    chooseSoundSetup();
    starSoundSetup();
    errorSoundSetup();


    msgBox.setText("Connection error");

    connect(this,&StartWindow::errorOccured,this,&StartWindow::errorShow);

}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_btnCreate_clicked()
{
    if(!ui->btnSingle->isHidden()){
        ui->btnSingle->hide();
        ui->btnLocal->hide();
        ui->btnMulti->hide();
    }
    else{
        ui->btnSingle->show();
        ui->btnLocal->show();
        ui->btnMulti->show();
    }

    ui->label->hide();
    ui->leID->hide();
    ui->btnJoin->hide();
}

void StartWindow::on_btnJoinG_clicked()
{
    if(!ui->label->isHidden()){
        ui->label->hide();
        ui->leID->hide();
        ui->btnJoin->hide();
    }

    else{
        ui->label->show();
        ui->leID->show();
        ui->btnJoin->show();
    }

    ui->btnSingle->hide();
    ui->btnLocal->hide();
    ui->btnMulti->hide();

}

void StartWindow::messageParser(Message& msg)
{
    msg_header_t msg_type = msg.get_header().get_msg_id();
    std::cerr << msg << std::endl;

    if (msg_type == msg_header_t::SERVER_OK)
    {
        // TODO: problem with qt (threads)
//        initializeGame();
    }
    else if (msg_type == msg_header_t::SERVER_ERROR)
    {
        m_sound_error.play();
        //QMessageBox::warning(this, "Connection error", "Wrong game ID");
        emit errorOccured();
        client.reset();
    }
}

void StartWindow::on_btnJoin_clicked()
{
    if (ui->leID->text().size() == 0) {
        m_sound_error.play();
        //QMessageBox::warning(this, "Connection error", "Wrong game ID");
        emit errorOccured();
    }
    else {
        // TODO: check for possible exceptions
        std::stringstream ss(ui->leID->text().toStdString());
        game_t gameId;
        ss >> gameId;
        client = std::make_shared<ConnectionClient>(host, port, [this](Message& msg){ messageParser(msg); }, gameId);
        // TODO: replace these sleeps
        sleep(2);
        initializeGame();
    }
}

void StartWindow::on_btnSingle_clicked()
{
    client = std::make_shared<ConnectionClient>(host, port, [this](Message& msg){ messageParser(msg); }, 0);
    sleep(2);
    initializeGame();
}

void StartWindow::on_btnLocal_clicked()
{
    client = std::make_shared<ConnectionClient>(host, port, [this](Message& msg){ messageParser(msg); }, 0);
}

void StartWindow::on_btnMulti_clicked()
{
    client = std::make_shared<ConnectionClient>(host, port, [this](Message& msg){ messageParser(msg); }, 0);
}

void StartWindow::errorShow()
{
    msgBox.exec();
}

void StartWindow::initializeGame()
{
    w = new Widget();
    w->establishConnection(client);
    w->show();
    this->hide();
}

//rotating original image 45 degrees and setting it as background for label
void StartWindow::diceImageSetup()
{

    QPixmap p1(":/img/img-dice5");
    QPixmap p2 = p1.transformed(QTransform().rotate(45));

    ui->label_2->setPixmap(p2);
    ui->label_2->setSizeIncrement(p2.size());

}

void StartWindow::chooseSoundSetup()
{
    m_sound_choose.setSource(QUrl::fromLocalFile(":/sounds/sound-choose"));
    m_sound_choose.setVolume(0.9f);

    connect(ui->btnCreate,&QPushButton::clicked,&m_sound_choose,&QSoundEffect::play);
    connect(ui->btnJoinG,&QPushButton::clicked,&m_sound_choose,&QSoundEffect::play);
}

void StartWindow::starSoundSetup()
{
    m_sound_start.setSource(QUrl::fromLocalFile(":/sounds/sound-roll"));
    m_sound_start.setVolume(0.5f);

    connect(ui->btnSingle,&QPushButton::clicked,&m_sound_start,&QSoundEffect::play);
    connect(ui->btnLocal,&QPushButton::clicked,&m_sound_start,&QSoundEffect::play);
    connect(ui->btnMulti,&QPushButton::clicked,&m_sound_start,&QSoundEffect::play);
}

void StartWindow::errorSoundSetup()
{
    m_sound_error.setSource(QUrl::fromLocalFile(":/sounds/sound-error"));
    m_sound_error.setVolume(0.5f);
}




