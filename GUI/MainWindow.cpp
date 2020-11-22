#include "MainWindow.h"
#include "ui_MainWindow.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWidthForTable(ui->tableL,m_column_width);
    ui->tableL->setStyleSheet(("QTableWidget {border : 5px solid blue;}"));

    setWidthForTable(ui->tableR,m_column_width);
    ui->tableR->setStyleSheet(("QTableWidget {border : 5px solid red;}"));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::setWidthForTable(QTableWidget *table, int width)
{
    for(auto i=0;i < table->columnCount()-1;i++)
        table->setColumnWidth(i, width);
    table->setColumnWidth(table->columnCount()-1, width + 20);
}

