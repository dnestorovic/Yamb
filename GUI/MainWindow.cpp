#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <iostream>
#include <QDebug>
#include "Dice.h"

int rollCountdown=3;
Dice dice1_value=Dice();
Dice dice2_value=Dice();
Dice dice3_value=Dice();
Dice dice4_value=Dice();
Dice dice5_value=Dice();
Dice dice6_value=Dice();
bool dice1_checked=false,dice2_checked=false,dice3_checked=false,dice4_checked=false,dice5_checked=false,dice6_checked=false;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_click_sound(this)
{

    ui->setupUi(this);
    timer=new QTimer(this);
    std::srand(time(NULL));
    //setup for both tables
    setWidthForTable(ui->tableL,m_column_width);
    ui->tableL->setStyleSheet(("QTableWidget {border : 5px solid rgb(114, 159, 207);}"));

    setWidthForTable(ui->tableR,m_column_width);
    ui->tableR->setStyleSheet(("QTableWidget {border : 5px solid rgb(239, 41, 41);}"));

    //merging cells of first six rows in the last column for both tables
    ui->tableL->setSpan(0,10,6,1);
    ui->tableR->setSpan(0,10,6,1);

    //we hide text edit with help so it could be seen only when ask button is clicked
    ui->plainTextEdit->hide();
    connect(ui->btnAsk,&QPushButton::clicked,this,&Widget::hideText);

    //setting-up click sound
    m_click_sound.setSource(QUrl::fromLocalFile(":/sounds/sound-click"));
    m_click_sound.setVolume(0.5f);

    //playing sound when button is clicked
    connect(ui->btnAsk, &QPushButton::clicked, &m_click_sound, &QSoundEffect::play);
    connect(ui->btnSend, &QPushButton::clicked, &m_click_sound, &QSoundEffect::play);
    connect(ui->btnThrow, &QPushButton::clicked, &m_click_sound, &QSoundEffect::play);
    connect(ui->btnMute, &QPushButton::clicked, &m_click_sound, &QSoundEffect::play);
    connect(ui->btnSmiley, &QPushButton::clicked, &m_click_sound, &QSoundEffect::play);

    //decreasing volume
    connect(ui->btnMute,&QPushButton::clicked, this, &Widget::decreaseVolume);

    //sending message
    connect(ui->btnSend,&QPushButton::clicked, this, &Widget::sendMessage);
    connect(ui->btnSend,&QPushButton::clicked,this,&Widget::sendMessage);

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

    ui->btnSend->setFixedWidth(45);
    ui->btnSmiley->setFixedWidth(45);

    ui->scrollArea->hide();

    st = new StartWindow(this);
    st->show();

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

void Widget::hideText(){(!(ui->plainTextEdit->isHidden()))?ui->plainTextEdit->hide():ui->plainTextEdit->show();}

void Widget::decreaseVolume()
{
    switch(m_volume_intensity){
        case full:  m_volume_intensity = mid;
                    m_click_sound.setVolume(0.25f);
                    ui->btnMute->setIcon(QIcon(":/img/img-speaker_m"));
                    break;
        case mid:   m_volume_intensity = low;
                    m_click_sound.setVolume(0.15f);
                    ui->btnMute->setIcon(QIcon(":/img/img-speaker_l"));
                    break;
        case low:   m_volume_intensity = mute;
                    m_click_sound.setVolume(0.0f);
                    ui->btnMute->setIcon(QIcon(":/img/img-speaker_mute"));
                    break;
        case mute:  m_volume_intensity = full;
                    m_click_sound.setVolume(0.5f);
                    ui->btnMute->setIcon(QIcon(":/img/img-speaker_f"));
                    break;
        default: ;
    }
}

void Widget::sendMessage()
{
    int last_item_index = ui->lChat->count();
    if(ui->leMessage->text().size() > 0){
        ui->lChat->addItem(ui->leMessage->text());
        ui->lChat->item(last_item_index)->setTextAlignment(Qt::AlignRight);
        ui->leMessage->setText("");
    }
}

void Widget::setWidthForTable(QTableWidget *table, int width)
{
    for(short i=0;i < table->columnCount()-1;i++)
        table->setColumnWidth(i, width);
    table->setColumnWidth(table->columnCount()-1, width + 20);
}

void Widget::on_btnSmiley_clicked(){(ui->scrollArea->isHidden())?ui->scrollArea->show():ui->scrollArea->hide();}

void Widget::addSmileyToText(QPushButton *button) const{ui->leMessage->setText(ui->leMessage->text() + button->text());}

void Widget::on_btnSmiley1_clicked(){addSmileyToText(ui->btnSmiley1);}
void Widget::on_btnSmiley2_clicked(){addSmileyToText(ui->btnSmiley2);}
void Widget::on_btnSmiley3_clicked(){addSmileyToText(ui->btnSmiley3);}
void Widget::on_btnSmiley4_clicked(){addSmileyToText(ui->btnSmiley4);}
void Widget::on_btnSmiley5_clicked(){addSmileyToText(ui->btnSmiley5);}
void Widget::on_btnSmiley6_clicked(){addSmileyToText(ui->btnSmiley6);}
void Widget::on_btnSmiley7_clicked(){addSmileyToText(ui->btnSmiley7);}
void Widget::on_btnSmiley8_clicked(){addSmileyToText(ui->btnSmiley8);}
void Widget::on_btnSmiley9_clicked(){addSmileyToText(ui->btnSmiley9);}
