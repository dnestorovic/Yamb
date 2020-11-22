#include "MainWindow.h"
#include "ui_MainWindow.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWidthForTable(ui->tableL,m_column_width);
    ui->tableL->setStyleSheet(("QTableWidget {border : 5px solid rgb(114, 159, 207);}"));

    setWidthForTable(ui->tableR,m_column_width);
    ui->tableR->setStyleSheet(("QTableWidget {border : 5px solid rgb(239, 41, 41);}"));

    //merging cells of first six rows in the last column for both tables
    ui->tableL->setSpan(0,10,6,1);
    ui->tableR->setSpan(0,10,6,1);

    ui->plainTextEdit->hide();

    connect(ui->btnAsk,&QPushButton::clicked,this,&Widget::hideText);

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

void Widget::setWidthForTable(QTableWidget *table, int width)
{
    for(short i=0;i < table->columnCount()-1;i++){
        table->setColumnWidth(i, width);
    }

    table->setColumnWidth(table->columnCount()-1, width + 20);
}

