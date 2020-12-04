#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include<QTimer>

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

private:
    Ui::StartWindow *ui;
    QTimer *timer;
};

#endif // STARTWINDOW_H
