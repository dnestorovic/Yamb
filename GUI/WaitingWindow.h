#ifndef WAITINGWINDOW_H
#define WAITINGWINDOW_H

#include <QDialog>
#include <QMovie>
#include <QScreen>

namespace Ui {
class WaitingWindow;
}

class WaitingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WaitingWindow(QWidget *parent = nullptr);
    ~WaitingWindow();
    void setId(QString id);

signals:
    void gameExitedWhileWaiting();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WaitingWindow *ui;
};

#endif // WAITINGWINDOW_H
