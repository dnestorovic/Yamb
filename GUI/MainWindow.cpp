#include "MainWindow.h"
#include "ui_MainWindow.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_click_sound(this)
{
    ui->setupUi(this);


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
}

Widget::~Widget()
{
    delete ui;
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

