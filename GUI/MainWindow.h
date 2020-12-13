#ifndef WIDGET_H
#define WIDGET_H

#include "StartWindow.h"
#include <QWidget>
#include <QSoundEffect>
#include <QGraphicsScene>
#include "Dice.h"

class QTableWidget;

enum volume_intensity{mute,low,mid,full};

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void hideText();
    void setVolumeIntensity(const volume_intensity intensity);
    volume_intensity getVolumeIntensity() const;
    void decreaseVolume();
    void sendMessage();
    void setDiceValue(bool,Dice*,QPushButton*);
    void setDiceChecked(bool&,Dice&,QPushButton*);

public slots:
    void diceRoll();
    void dice1Clicked();
    void dice2Clicked();
    void dice3Clicked();
    void dice4Clicked();
    void dice5Clicked();
    void dice6Clicked();

private slots:
    void on_btnSmiley_clicked();
    void on_btnSmiley1_clicked();
    void on_btnSmiley2_clicked();
    void on_btnSmiley3_clicked();
    void on_btnSmiley4_clicked();
    void on_btnSmiley5_clicked();
    void on_btnSmiley6_clicked();
    void on_btnSmiley7_clicked();
    void on_btnSmiley8_clicked();
    void on_btnSmiley9_clicked();

    void on_btnSend_clicked();
    void on_btnMute_clicked();

    void on_btnSurrender_clicked();

signals:
    void volumeIntesityChanged();

private:
    void setWidthForTable(QTableWidget *table, int width);
    void tableSetup(QTableWidget *table, QString border_color);

    void addSmileyToText(QPushButton* button) const;

    void clickSoundSetup();
    void surrenderSoundSetup();

    void btnMuteChangeIcon();

private:
    Ui::Widget *ui;

    const int m_column_width = 30;

    QSoundEffect m_click_sound;
    QSoundEffect m_surrender_sound;
    volume_intensity m_volume_intensity = full;
};
#endif // WIDGET_H
