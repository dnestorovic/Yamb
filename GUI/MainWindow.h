#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSoundEffect>
#include <QTimer>
#include <QGraphicsScene>
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
    void decreaseVolume();
    void sendMessage();
public slots:
    void diceRoll();
    void dice1Clicked();
    void dice2Clicked();
    void dice3Clicked();
    void dice4Clicked();
    void dice5Clicked();
    void dice6Clicked();
private:
    void setWidthForTable(QTableWidget *table, int width);
    QTimer *timer;

private:
    Ui::Widget *ui;
    const int m_column_width = 30;
    QSoundEffect m_click_sound;
    volume_intensity m_volume_intensity = full;
};
#endif // WIDGET_H
