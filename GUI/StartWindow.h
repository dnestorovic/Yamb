#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QSoundEffect>

#include "MainWindow.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private slots:

    void on_btnCreate_clicked();
    void on_btnJoinG_clicked();
    void on_btnJoin_clicked();
    void on_btnSingle_clicked();
    void on_btnLocal_clicked();
    void on_btnMulti_clicked();

private:
    void diceImageSetup();
    void chooseSoundSetup();
    void starSoundSetup();
    void errorSoundSetup();

private:

    Ui::StartWindow *ui;
    QWidget* w;
    QSoundEffect m_sound_choose;
    QSoundEffect m_sound_start;
    QSoundEffect m_sound_error;
};

#endif // STARTWINDOW_H
