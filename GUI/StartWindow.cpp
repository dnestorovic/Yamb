#include "StartWindow.h"
#include "ui_StartWindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow),
    m_sound_choose(this),
    m_sound_start(this),
    m_sound_error(this)
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

void StartWindow::on_btnJoin_clicked()
{
    if(ui->leID->text().size()==0){
        m_sound_error.play();
        QMessageBox::warning(this,"Connection error","Wrong game ID");
    }
}

void StartWindow::on_btnSingle_clicked()
{
    w=new Widget();
    w->show();
    this->hide();
}

void StartWindow::on_btnLocal_clicked()
{
    w=new Widget();
    w->show();
    this->hide();
}

void StartWindow::on_btnMulti_clicked()
{
    w=new Widget();
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


