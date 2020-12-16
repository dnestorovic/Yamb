#include <iostream>
#include <QDebug>
#include "Dice.h"
#include "ui_MainWindow.h"
#include "MainWindow.h"

using Communication::msg_header_t;

const std::string host = "127.0.0.1";
const std::string port = "5000";

int rollCountdown=3;
Dice dice1_value=Dice();
Dice dice2_value=Dice();
Dice dice3_value=Dice();
Dice dice4_value=Dice();
Dice dice5_value=Dice();
Dice dice6_value=Dice();
bool dice1_checked=false,dice2_checked=false,dice3_checked=false,dice4_checked=false,dice5_checked=false,dice6_checked=false;

bool Widget::getIsConnected() const {
    return isConnected;
}

void Widget::setIsConnected(bool flag) {
    isConnected = flag;
}

void Widget::messageParser(Message& msg) {
    msg_header_t msg_type = msg.get_header().get_msg_id();
    std::cerr << msg << std::endl;

    if (!getIsConnected()) {
        if (msg_type == msg_header_t::SERVER_OK) {
            setIsConnected(true);
        }
        else if (msg_type == msg_header_t::SERVER_ERROR) {
            connection.close("can't establish the connection");
            exit(1);
        }
        else {
            // TODO
            // ignore message for now
        }
    }
    else if (msg_type == msg_header_t::SERVER_CHAT) {
        updateChat(msg);
    }
    else if (msg_type == msg_header_t::CLIENT_CHAT) {
        updateChat(msg);
    }
    else if (msg_type == msg_header_t::SERVER_END_GAME) {
        // TODO: does owner_id won or lost the game? for now lost

        if (connection.get_owner_id() == msg.get_header().get_owner_id()) {
            std::cout << "You lost" << std::endl;
        }
        else {
            std::cout << "You won" << std::endl;
        }

        exit(1);
    }
}

Widget::Widget(GameType gameT, game_t gameI,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_click_sound(this)
    , connection(host, port, [this](Message& msg){ messageParser(msg); })
    , gameType(gameT)
    , gameId(gameI)
{
    ui->setupUi(this);

    //setup for both tables
    tableSetup(ui->tableL,"rgb(114, 159, 207)");
    tableSetup(ui->tableR,"rgb(239, 41, 41)");

    //we hide text edit with help so it could be seen only when ask button is clicked
    ui->plainTextEdit->hide();
    connect(ui->btnAsk,&QPushButton::clicked,this,&Widget::hideText);

    clickSoundSetup();
    surrenderSoundSetup();

    connect(this,&Widget::volumeIntesityChanged,this,&Widget::btnMuteChangeIcon);

    //setup for chat buttons
    ui->btnSend->setFixedWidth(45);
    ui->btnSmiley->setFixedWidth(45);

    //innitialy scroll area with emojis should be hidden
    ui->scrollArea->hide();

    //rolling dice
    connect(ui->btnThrow,&QPushButton::clicked,this,&Widget::diceRoll);

    if(rollCountdown==3){
        ui->dice1->setEnabled(false);
        ui->dice2->setEnabled(false);
        ui->dice3->setEnabled(false);
        ui->dice4->setEnabled(false);
        ui->dice5->setEnabled(false);
        ui->dice6->setEnabled(false);
    }


    //when dice# is checked its value cant be changed
    connect(ui->dice1,&QPushButton::clicked,this,&Widget::dice1Clicked);
    connect(ui->dice2,&QPushButton::clicked,this,&Widget::dice2Clicked);
    connect(ui->dice3,&QPushButton::clicked,this,&Widget::dice3Clicked);
    connect(ui->dice4,&QPushButton::clicked,this,&Widget::dice4Clicked);
    connect(ui->dice5,&QPushButton::clicked,this,&Widget::dice5Clicked);
    connect(ui->dice6,&QPushButton::clicked,this,&Widget::dice6Clicked);


    //std::cout << static_cast<u_int64_t>(gameType) << std::endl;
    //std::cout << gameId << std::endl;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::setDiceValue(bool dice_check,Dice* dice_value,QPushButton* dice){
    if(!dice_check){
        dice_value->set_value(dice_value->roll());
        dice->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice_value->get_value())+");}");
    }
}

void Widget::diceRoll(){
    rollCountdown--;
    ui->dice1->setEnabled(true);
    ui->dice2->setEnabled(true);
    ui->dice3->setEnabled(true);
    ui->dice4->setEnabled(true);
    ui->dice5->setEnabled(true);
    ui->dice6->setEnabled(true);
    if(rollCountdown>=0){
        if(rollCountdown==0)
            ui->btnThrow->setEnabled(false);
        setDiceValue(dice1_checked,&dice1_value,ui->dice1);
        setDiceValue(dice2_checked,&dice2_value,ui->dice2);
        setDiceValue(dice3_checked,&dice3_value,ui->dice3);
        setDiceValue(dice4_checked,&dice4_value,ui->dice4);
        setDiceValue(dice5_checked,&dice5_value,ui->dice5);
        setDiceValue(dice6_checked,&dice6_value,ui->dice6);
    }
    else
        ui->btnThrow->setEnabled(false);
}

//checks if dice was clicked or unclicked
void Widget::setDiceChecked(bool& dice_check,Dice& dice_value,QPushButton* dice){
    //if we rolled dice atleast once we can check it
    if(rollCountdown<3 && rollCountdown>=0){
        dice_check=!dice_check;
        dice->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice_value.get_value())+");"+
                                 (((dice_check))?" border:2px solid blue;}":"}"));
    }
    else
        dice->setStyleSheet(("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice_value.get_value())+");"+"}"));
}

void Widget::dice1Clicked(){setDiceChecked(dice1_checked,dice1_value,ui->dice1);}
void Widget::dice2Clicked(){setDiceChecked(dice2_checked,dice2_value,ui->dice2);}
void Widget::dice3Clicked(){setDiceChecked(dice3_checked,dice3_value,ui->dice3);}
void Widget::dice4Clicked(){setDiceChecked(dice4_checked,dice4_value,ui->dice4);}
void Widget::dice5Clicked(){setDiceChecked(dice5_checked,dice5_value,ui->dice5);}
void Widget::dice6Clicked(){setDiceChecked(dice6_checked,dice6_value,ui->dice6);}

void Widget::hideText(){

    (!(ui->plainTextEdit->isHidden())) ? ui->plainTextEdit->hide(): ui->plainTextEdit->show();

}

void Widget::setVolumeIntensity(const volume_intensity intensity){

    switch (intensity) {

        case full:  m_click_sound.setVolume(0.5f); break;
        case mid:   m_click_sound.setVolume(0.25f); break;
        case low:   m_click_sound.setVolume(0.15f); break;
        case mute:  m_click_sound.setVolume(0.0f); break;

        default: break;
    }

    m_volume_intensity = intensity;
    emit volumeIntesityChanged();

}

volume_intensity Widget::getVolumeIntensity() const
{
    return m_volume_intensity;
}

void Widget::decreaseVolume()
{
    switch(getVolumeIntensity()){

        case full:  setVolumeIntensity(mid); break;
        case mid:   setVolumeIntensity(low); break;
        case low:   setVolumeIntensity(mute); break;
        case mute:  setVolumeIntensity(full); break;

        default: break;
    }
}

void Widget::on_btnMute_clicked()
{
    decreaseVolume();
}

void Widget::updateChat(Message& msg)
{
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
    if (msg.get_header().get_owner_id() == connection.get_owner_id()) {
        content = "You: " + content;
    }
    else {
        content = "Opponent: " + content;
    }

    int last_item_index = ui->lChat->count();
    ui->lChat->addItem(QString::fromUtf8(content.c_str()));
    ui->lChat->item(last_item_index)->setTextAlignment(Qt::AlignLeft);
    ui->leMessage->setText("");
}

//sends message written in leChat
void Widget::on_btnSend_clicked()
{
    if(ui->leMessage->text().size() > 0){
        Header header(Communication::msg_header_t::CLIENT_CHAT, connection.get_owner_id(), connection.get_game_id());
        Message message(header);
        std::string content = ui->leMessage->text().toUtf8().constData();
        for (char c : content)
            message << c;
        connection.write(message);
    }
}


//sets width for columns of the table
void Widget::setWidthForTable(QTableWidget *table, int width)
{
    for(short i=0;i < table->columnCount()-1;i++)
        table->setColumnWidth(i, width);

    //the last column is slightly wider
    table->setColumnWidth(table->columnCount()-1, width + 20);
}

void Widget::tableSetup(QTableWidget *table, QString border_color)
{
    setWidthForTable(table,m_column_width);
    table->setStyleSheet(("QTableWidget {border : 5px solid " + border_color  + " ;}"));

    //merging cells of first six rows in the last column
    table->setSpan(0,10,6,1);
}

//opens scrollarea which contains emojis
void Widget::on_btnSmiley_clicked(){

    (ui->scrollArea->isHidden()) ? ui->scrollArea->show() : ui->scrollArea->hide();

}

//adds emoji from button(forwarded as argument) to the text inside of leChat
void Widget::addSmileyToText(QPushButton *button) const {

    ui->leMessage->setText(ui->leMessage->text() + button->text());

}

void Widget::clickSoundSetup()
{

    //setting-up click sound
    m_click_sound.setSource(QUrl::fromLocalFile(":/sounds/sound-click"));

    //playing sound when button is clicked
    connect(ui->btnAsk, &QPushButton::clicked, &m_click_sound, &QSoundEffect::play);
    connect(ui->btnSend, &QPushButton::clicked, &m_click_sound, &QSoundEffect::play);
    connect(ui->btnThrow, &QPushButton::clicked, &m_click_sound, &QSoundEffect::play);
    connect(ui->btnMute, &QPushButton::clicked, &m_click_sound, &QSoundEffect::play);
    connect(ui->btnSmiley, &QPushButton::clicked, &m_click_sound, &QSoundEffect::play);

}

void Widget::surrenderSoundSetup()
{
    m_surrender_sound.setSource(QUrl::fromLocalFile(":/sounds/sound-error"));
}

void Widget::btnMuteChangeIcon()
{
    switch (getVolumeIntensity()) {

    case full:  ui->btnMute->setIcon(QIcon(":/img/img-speaker_f")); break;
    case mid:   ui->btnMute->setIcon(QIcon(":/img/img-speaker_m")); break;
    case low:   ui->btnMute->setIcon(QIcon(":/img/img-speaker_l")); break;
    case mute:  ui->btnMute->setIcon(QIcon(":/img/img-speaker_mute")); break;

    default: break;

    }
}

void Widget::on_btnSmiley1_clicked() {addSmileyToText(ui->btnSmiley1);}
void Widget::on_btnSmiley2_clicked() {addSmileyToText(ui->btnSmiley2);}
void Widget::on_btnSmiley3_clicked() {addSmileyToText(ui->btnSmiley3);}
void Widget::on_btnSmiley4_clicked() {addSmileyToText(ui->btnSmiley4);}
void Widget::on_btnSmiley5_clicked() {addSmileyToText(ui->btnSmiley5);}
void Widget::on_btnSmiley6_clicked() {addSmileyToText(ui->btnSmiley6);}
void Widget::on_btnSmiley7_clicked() {addSmileyToText(ui->btnSmiley7);}
void Widget::on_btnSmiley8_clicked() {addSmileyToText(ui->btnSmiley8);}
void Widget::on_btnSmiley9_clicked() {addSmileyToText(ui->btnSmiley9);}


void Widget::on_btnSurrender_clicked()
{

    m_surrender_sound.play();

    auto btn = QMessageBox::question(this,"Surrender","Are you sure?");

    if(btn == QMessageBox::Yes)
        this->close();
}
