#include "StartWindow.h"
#include "ui_StartWindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    ui->btnSingle->hide();
    ui->btnLocal->hide();
    ui->btnMulti->hide();

    ui->label->hide();
    ui->leID->hide();
    ui->btnJoin->hide();

    timer = new QTimer(this);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_btnCreate_clicked()
{
    if(ui->btnMulti->isHidden()){
        ui->btnSingle->show();
        ui->btnLocal->show();
        ui->btnMulti->show();
    }
    else {
        ui->btnSingle->hide();
        ui->btnLocal->hide();
        ui->btnMulti->hide();
    }

    if(!ui->btnJoin->isHidden()){
        ui->label->hide();
        ui->leID->hide();
        ui->btnJoin->hide();
    }
}

void StartWindow::on_btnJoinG_clicked()
{
    if(ui->btnJoin->isHidden()){
        ui->label->show();
        ui->leID->show();
        ui->btnJoin->show();
    }
    else {
        ui->label->hide();
        ui->leID->hide();
        ui->btnJoin->hide();
    }

    if(!ui->btnMulti->isHidden()){
        ui->btnSingle->hide();
        ui->btnLocal->hide();
        ui->btnMulti->hide();
    }
}

void StartWindow::on_btnJoin_clicked()
{
    if(ui->leID->text().size()==0)
        QMessageBox::warning(this,"Connection error","Wrong game ID");
}
