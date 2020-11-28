#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <iostream>
#include <QDebug>


int rollCountdown=3;
int dice1_value,dice2_value,dice3_value,dice4_value,dice5_value,dice6_value;
int dice1_checked=0,dice2_checked=0,dice3_checked=0,dice4_checked=0,dice5_checked=0,dice6_checked=0;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_click_sound(this)
{
    ui->setupUi(this);
    timer=new QTimer(this);

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
    m_click_sound.setVolume(0.75f);

    connect(ui->btnAsk, &QPushButton::clicked, &m_click_sound, &QSoundEffect::play);
    connect(ui->btnSend, &QPushButton::clicked, &m_click_sound, &QSoundEffect::play);
    connect(ui->btnThrow, &QPushButton::clicked, &m_click_sound, &QSoundEffect::play);
    connect(ui->btnMute, &QPushButton::clicked, &m_click_sound, &QSoundEffect::play);

    connect(ui->btnMute,&QPushButton::clicked, this, &Widget::decreaseVolume);

    connect(ui->btnSend,&QPushButton::clicked, this, &Widget::sendMessage);

    connect(ui->btnSend,&QPushButton::clicked,this,&Widget::sendMessage);

    connect(ui->btnThrow,&QPushButton::clicked,this,&Widget::diceRoll);

    connect(ui->dice1,&QPushButton::clicked,this,&Widget::dice1Clicked);
    connect(ui->dice2,&QPushButton::clicked,this,&Widget::dice2Clicked);
    connect(ui->dice3,&QPushButton::clicked,this,&Widget::dice3Clicked);
    connect(ui->dice4,&QPushButton::clicked,this,&Widget::dice4Clicked);
    connect(ui->dice5,&QPushButton::clicked,this,&Widget::dice5Clicked);
    connect(ui->dice6,&QPushButton::clicked,this,&Widget::dice6Clicked);
}



Widget::~Widget()
{
    delete ui;
}


void Widget::diceRoll(){
    rollCountdown--;
    if(rollCountdown>=0){
        srand(time(NULL));
        if(dice1_checked!=1){
            dice1_value=1+rand()%6;
            ui->dice1->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice1_value)+");}");
        }

        if(dice2_checked!=1){
            dice2_value=1+rand()%6;
            ui->dice2->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice2_value)+");}");
        }

        if(dice3_checked!=1){
            dice3_value=1+rand()%6;
            ui->dice3->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice3_value)+");}");
        }

        if(dice4_checked!=1){
            dice4_value=1+rand()%6;
            ui->dice4->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice4_value)+");}");
        }

        if(dice5_checked!=1){
            dice5_value=1+rand()%6;
            ui->dice5->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice5_value)+");}");
        }

        if(dice6_checked!=1){
            dice6_value=1+rand()%6;
            ui->dice6->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice6_value)+");}");
        }


    }
    else{
        ui->btnThrow->setEnabled(false);
    }
}

void Widget::dice1Clicked()
{
    if(rollCountdown<3 && rollCountdown>=0){
        dice1_checked++;
        if(dice1_checked==1){
           ui->dice1->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice1_value)+"); border:2px solid blue;}");
        }
        if(dice1_checked==2){
           dice1_checked=0;
           ui->dice1->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice1_value)+");}");
        }
    }
}

void Widget::dice2Clicked()
{
    if(rollCountdown<3 && rollCountdown>=0){
        dice2_checked++;
        if(dice2_checked==1){
           ui->dice2->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice2_value)+"); border:2px solid blue;}");
        }
        if(dice2_checked==2){
           dice2_checked=0;
           ui->dice2->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice2_value)+");}");
        }
    }
}

void Widget::dice3Clicked()
{
    if(rollCountdown<3 && rollCountdown>=0){
        dice3_checked++;
        if(dice3_checked==1){
           ui->dice3->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice3_value)+"); border:2px solid blue;}");
        }
        if(dice3_checked==2){
           dice3_checked=0;
           ui->dice3->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice3_value)+");}");
        }
    }
}

void Widget::dice4Clicked()
{
    if(rollCountdown<3 && rollCountdown>=0){
        dice4_checked++;
        if(dice4_checked==1){
           ui->dice4->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice4_value)+"); border:2px solid blue;}");
        }
        if(dice4_checked==2){
           dice4_checked=0;
           ui->dice4->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice4_value)+");}");
        }
    }
}

void Widget::dice5Clicked()
{
    if(rollCountdown<3 && rollCountdown>=0){
        dice5_checked++;
        if(dice5_checked==1){
           ui->dice5->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice5_value)+"); border:2px solid blue;}");
        }
        if(dice5_checked==2){
           dice5_checked=0;
           ui->dice5->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice5_value)+");}");
        }
    }
}

void Widget::dice6Clicked()
{
    if(rollCountdown<3 && rollCountdown>=0){
        dice6_checked++;
        if(dice6_checked==1){
           ui->dice6->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice6_value)+"); border:2px solid blue;}");
        }
        if(dice6_checked==2){
           dice6_checked=0;
           ui->dice6->setStyleSheet("QPushButton {background-image: url(:/img/img-dice"+QString::number(dice6_value)+");}");
        }
    }
}

void Widget::hideText()
{
    bool isHidden = ui->plainTextEdit->isHidden();

    if(!isHidden){
        ui->plainTextEdit->hide();
    }
    else{
        ui->plainTextEdit->show();
    }
}

void Widget::decreaseVolume()
{
    switch(m_volume_intensity){

        case full:  m_volume_intensity = mid;
                    m_click_sound.setVolume(0.5f);
                    ui->btnMute->setIcon(QIcon(":/img/img-speaker_m"));
                    break;
        case mid:   m_volume_intensity = low;
                    m_click_sound.setVolume(0.25f);
                    ui->btnMute->setIcon(QIcon(":/img/img-speaker_l"));
                    break;
        case low:   m_volume_intensity = mute;
                    m_click_sound.setVolume(0.0f);
                    ui->btnMute->setIcon(QIcon(":/img/img-speaker_mute"));
                    break;
        case mute:  m_volume_intensity = full;
                    m_click_sound.setVolume(0.75f);
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
    for(short i=0;i < table->columnCount()-1;i++){
        table->setColumnWidth(i, width);
    }

    table->setColumnWidth(table->columnCount()-1, width + 20);
}

