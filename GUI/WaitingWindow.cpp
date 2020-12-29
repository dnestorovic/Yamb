#include "WaitingWindow.h"
#include "ui_WaitingWindow.h"

WaitingWindow::WaitingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WaitingWindow)
{
    ui->setupUi(this);

    ui->labelGameId->setTextInteractionFlags(Qt::TextSelectableByMouse);
}

WaitingWindow::~WaitingWindow()
{
    delete ui;
}

void WaitingWindow::setId(QString id)
{
    ui->labelGameId->setText(id);
}

void WaitingWindow::on_pushButton_clicked()
{
    emit gameExitedWhileWaiting();
    this->close();
}
