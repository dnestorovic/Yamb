/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTableWidget *tableL;
    QTableWidget *tableR;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *btnSend;
    QPushButton *btnSmiley;
    QSpacerItem *horizontalSpacer;
    QLineEdit *leMessage;
    QListWidget *lChat;
    QPushButton *btnAsk;
    QPushButton *btnThrow;
    QPlainTextEdit *plainTextEdit;
    QPushButton *btnMute;
    QTextBrowser *textBrowser;
    QPushButton *dice1;
    QPushButton *dice2;
    QPushButton *dice3;
    QPushButton *dice4;
    QPushButton *dice5;
    QPushButton *dice6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *btnSmiley9;
    QPushButton *btnSmiley2;
    QPushButton *btnSmiley3;
    QPushButton *btnSmiley5;
    QPushButton *btnSmiley8;
    QPushButton *btnSmiley6;
    QPushButton *btnSmiley1;
    QPushButton *btnSmiley4;
    QPushButton *btnSmiley7;
    QTextBrowser *textBrowser_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1200, 861);
        Widget->setAutoFillBackground(false);
        Widget->setStyleSheet(QString::fromUtf8(""));
        tableL = new QTableWidget(Widget);
        if (tableL->columnCount() < 11)
            tableL->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableL->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableL->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableL->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableL->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableL->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableL->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableL->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableL->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableL->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableL->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableL->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        if (tableL->rowCount() < 15)
            tableL->setRowCount(15);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        tableL->setVerticalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        tableL->setVerticalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignCenter);
        tableL->setVerticalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignCenter);
        tableL->setVerticalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignCenter);
        tableL->setVerticalHeaderItem(4, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignCenter);
        tableL->setVerticalHeaderItem(5, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignCenter);
        tableL->setVerticalHeaderItem(6, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setTextAlignment(Qt::AlignCenter);
        tableL->setVerticalHeaderItem(7, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setTextAlignment(Qt::AlignCenter);
        tableL->setVerticalHeaderItem(8, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignCenter);
        tableL->setVerticalHeaderItem(9, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setTextAlignment(Qt::AlignCenter);
        tableL->setVerticalHeaderItem(10, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setTextAlignment(Qt::AlignCenter);
        tableL->setVerticalHeaderItem(11, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setTextAlignment(Qt::AlignCenter);
        tableL->setVerticalHeaderItem(12, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setTextAlignment(Qt::AlignCenter);
        tableL->setVerticalHeaderItem(13, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setTextAlignment(Qt::AlignCenter);
        tableL->setVerticalHeaderItem(14, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem26->setFlags(Qt::NoItemFlags);
        tableL->setItem(0, 10, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableL->setItem(1, 10, __qtablewidgetitem27);
        QBrush brush(QColor(252, 233, 79, 255));
        brush.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setBackground(brush);
        tableL->setItem(6, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setBackground(brush);
        tableL->setItem(6, 1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setBackground(brush);
        tableL->setItem(6, 2, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setBackground(brush);
        tableL->setItem(6, 3, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setBackground(brush);
        tableL->setItem(6, 4, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setBackground(brush);
        tableL->setItem(6, 5, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setBackground(brush);
        tableL->setItem(6, 6, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setBackground(brush);
        tableL->setItem(6, 7, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setBackground(brush);
        tableL->setItem(6, 8, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setBackground(brush);
        tableL->setItem(6, 9, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setBackground(brush);
        tableL->setItem(6, 10, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setBackground(brush);
        tableL->setItem(9, 0, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setBackground(brush);
        tableL->setItem(9, 1, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setBackground(brush);
        tableL->setItem(9, 2, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setBackground(brush);
        tableL->setItem(9, 3, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setBackground(brush);
        tableL->setItem(9, 4, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        __qtablewidgetitem44->setBackground(brush);
        tableL->setItem(9, 5, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        __qtablewidgetitem45->setBackground(brush);
        tableL->setItem(9, 6, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        __qtablewidgetitem46->setBackground(brush);
        tableL->setItem(9, 7, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        __qtablewidgetitem47->setBackground(brush);
        tableL->setItem(9, 8, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        __qtablewidgetitem48->setBackground(brush);
        tableL->setItem(9, 9, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        __qtablewidgetitem49->setBackground(brush);
        tableL->setItem(9, 10, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        __qtablewidgetitem50->setBackground(brush);
        tableL->setItem(14, 0, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        __qtablewidgetitem51->setBackground(brush);
        tableL->setItem(14, 1, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        __qtablewidgetitem52->setBackground(brush);
        tableL->setItem(14, 2, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        __qtablewidgetitem53->setBackground(brush);
        tableL->setItem(14, 3, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        __qtablewidgetitem54->setBackground(brush);
        tableL->setItem(14, 4, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        __qtablewidgetitem55->setBackground(brush);
        tableL->setItem(14, 5, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        __qtablewidgetitem56->setBackground(brush);
        tableL->setItem(14, 6, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        __qtablewidgetitem57->setBackground(brush);
        tableL->setItem(14, 7, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        __qtablewidgetitem58->setBackground(brush);
        tableL->setItem(14, 8, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        __qtablewidgetitem59->setBackground(brush);
        tableL->setItem(14, 9, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        __qtablewidgetitem60->setBackground(brush);
        tableL->setItem(14, 10, __qtablewidgetitem60);
        tableL->setObjectName(QString::fromUtf8("tableL"));
        tableL->setGeometry(QRect(30, 50, 423, 480));
        tableL->setStyleSheet(QString::fromUtf8("background-color:rgb(114, 159, 207);"));
        tableL->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableL->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableL->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        tableL->setAutoScroll(false);
        tableL->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableL->horizontalHeader()->setMinimumSectionSize(20);
        tableL->verticalHeader()->setMinimumSectionSize(10);
        tableL->verticalHeader()->setDefaultSectionSize(30);
        tableR = new QTableWidget(Widget);
        if (tableR->columnCount() < 11)
            tableR->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(0, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(1, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(2, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(3, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(4, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(5, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(6, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(7, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(8, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(9, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(10, __qtablewidgetitem71);
        if (tableR->rowCount() < 15)
            tableR->setRowCount(15);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        __qtablewidgetitem72->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(0, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        __qtablewidgetitem73->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(1, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        __qtablewidgetitem74->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(2, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        __qtablewidgetitem75->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(3, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        __qtablewidgetitem76->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(4, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        __qtablewidgetitem77->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(5, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        __qtablewidgetitem78->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(6, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        __qtablewidgetitem79->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(7, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        __qtablewidgetitem80->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(8, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        __qtablewidgetitem81->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(9, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        __qtablewidgetitem82->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(10, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        __qtablewidgetitem83->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(11, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        __qtablewidgetitem84->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(12, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        __qtablewidgetitem85->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(13, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        __qtablewidgetitem86->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(14, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        __qtablewidgetitem87->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem87->setFlags(Qt::NoItemFlags);
        tableR->setItem(0, 10, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        __qtablewidgetitem88->setBackground(brush);
        tableR->setItem(6, 0, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        __qtablewidgetitem89->setBackground(brush);
        tableR->setItem(6, 1, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        __qtablewidgetitem90->setBackground(brush);
        tableR->setItem(6, 2, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        __qtablewidgetitem91->setBackground(brush);
        tableR->setItem(6, 3, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        __qtablewidgetitem92->setBackground(brush);
        tableR->setItem(6, 4, __qtablewidgetitem92);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        __qtablewidgetitem93->setBackground(brush);
        tableR->setItem(6, 5, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        __qtablewidgetitem94->setBackground(brush);
        tableR->setItem(6, 6, __qtablewidgetitem94);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        __qtablewidgetitem95->setBackground(brush);
        tableR->setItem(6, 7, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        __qtablewidgetitem96->setBackground(brush);
        tableR->setItem(6, 8, __qtablewidgetitem96);
        QTableWidgetItem *__qtablewidgetitem97 = new QTableWidgetItem();
        __qtablewidgetitem97->setBackground(brush);
        tableR->setItem(6, 9, __qtablewidgetitem97);
        QTableWidgetItem *__qtablewidgetitem98 = new QTableWidgetItem();
        __qtablewidgetitem98->setBackground(brush);
        tableR->setItem(6, 10, __qtablewidgetitem98);
        QTableWidgetItem *__qtablewidgetitem99 = new QTableWidgetItem();
        __qtablewidgetitem99->setBackground(brush);
        tableR->setItem(9, 0, __qtablewidgetitem99);
        QTableWidgetItem *__qtablewidgetitem100 = new QTableWidgetItem();
        __qtablewidgetitem100->setBackground(brush);
        tableR->setItem(9, 1, __qtablewidgetitem100);
        QTableWidgetItem *__qtablewidgetitem101 = new QTableWidgetItem();
        __qtablewidgetitem101->setBackground(brush);
        tableR->setItem(9, 2, __qtablewidgetitem101);
        QTableWidgetItem *__qtablewidgetitem102 = new QTableWidgetItem();
        __qtablewidgetitem102->setBackground(brush);
        tableR->setItem(9, 3, __qtablewidgetitem102);
        QTableWidgetItem *__qtablewidgetitem103 = new QTableWidgetItem();
        __qtablewidgetitem103->setBackground(brush);
        tableR->setItem(9, 4, __qtablewidgetitem103);
        QTableWidgetItem *__qtablewidgetitem104 = new QTableWidgetItem();
        __qtablewidgetitem104->setBackground(brush);
        tableR->setItem(9, 5, __qtablewidgetitem104);
        QTableWidgetItem *__qtablewidgetitem105 = new QTableWidgetItem();
        __qtablewidgetitem105->setBackground(brush);
        tableR->setItem(9, 6, __qtablewidgetitem105);
        QTableWidgetItem *__qtablewidgetitem106 = new QTableWidgetItem();
        __qtablewidgetitem106->setBackground(brush);
        tableR->setItem(9, 7, __qtablewidgetitem106);
        QTableWidgetItem *__qtablewidgetitem107 = new QTableWidgetItem();
        __qtablewidgetitem107->setBackground(brush);
        tableR->setItem(9, 8, __qtablewidgetitem107);
        QTableWidgetItem *__qtablewidgetitem108 = new QTableWidgetItem();
        __qtablewidgetitem108->setBackground(brush);
        tableR->setItem(9, 9, __qtablewidgetitem108);
        QTableWidgetItem *__qtablewidgetitem109 = new QTableWidgetItem();
        __qtablewidgetitem109->setBackground(brush);
        tableR->setItem(9, 10, __qtablewidgetitem109);
        QTableWidgetItem *__qtablewidgetitem110 = new QTableWidgetItem();
        __qtablewidgetitem110->setBackground(brush);
        tableR->setItem(14, 0, __qtablewidgetitem110);
        QTableWidgetItem *__qtablewidgetitem111 = new QTableWidgetItem();
        __qtablewidgetitem111->setBackground(brush);
        tableR->setItem(14, 1, __qtablewidgetitem111);
        QTableWidgetItem *__qtablewidgetitem112 = new QTableWidgetItem();
        __qtablewidgetitem112->setBackground(brush);
        tableR->setItem(14, 2, __qtablewidgetitem112);
        QTableWidgetItem *__qtablewidgetitem113 = new QTableWidgetItem();
        __qtablewidgetitem113->setBackground(brush);
        tableR->setItem(14, 3, __qtablewidgetitem113);
        QTableWidgetItem *__qtablewidgetitem114 = new QTableWidgetItem();
        __qtablewidgetitem114->setBackground(brush);
        tableR->setItem(14, 4, __qtablewidgetitem114);
        QTableWidgetItem *__qtablewidgetitem115 = new QTableWidgetItem();
        __qtablewidgetitem115->setBackground(brush);
        tableR->setItem(14, 5, __qtablewidgetitem115);
        QTableWidgetItem *__qtablewidgetitem116 = new QTableWidgetItem();
        __qtablewidgetitem116->setBackground(brush);
        tableR->setItem(14, 6, __qtablewidgetitem116);
        QTableWidgetItem *__qtablewidgetitem117 = new QTableWidgetItem();
        __qtablewidgetitem117->setBackground(brush);
        tableR->setItem(14, 7, __qtablewidgetitem117);
        QTableWidgetItem *__qtablewidgetitem118 = new QTableWidgetItem();
        __qtablewidgetitem118->setBackground(brush);
        tableR->setItem(14, 8, __qtablewidgetitem118);
        QTableWidgetItem *__qtablewidgetitem119 = new QTableWidgetItem();
        __qtablewidgetitem119->setBackground(brush);
        tableR->setItem(14, 9, __qtablewidgetitem119);
        QTableWidgetItem *__qtablewidgetitem120 = new QTableWidgetItem();
        __qtablewidgetitem120->setBackground(brush);
        tableR->setItem(14, 10, __qtablewidgetitem120);
        tableR->setObjectName(QString::fromUtf8("tableR"));
        tableR->setGeometry(QRect(740, 50, 423, 480));
        tableR->setStyleSheet(QString::fromUtf8("background-color:rgb(239, 41, 41)"));
        tableR->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableR->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableR->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        tableR->setAutoScroll(false);
        tableR->horizontalHeader()->setMinimumSectionSize(20);
        tableR->verticalHeader()->setMinimumSectionSize(10);
        tableR->verticalHeader()->setDefaultSectionSize(30);
        gridLayoutWidget = new QWidget(Widget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(480, 50, 249, 261));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        btnSend = new QPushButton(gridLayoutWidget);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setStyleSheet(QString::fromUtf8("background-color:rgb(52, 101, 164);"));

        gridLayout->addWidget(btnSend, 2, 2, 1, 1);

        btnSmiley = new QPushButton(gridLayoutWidget);
        btnSmiley->setObjectName(QString::fromUtf8("btnSmiley"));

        gridLayout->addWidget(btnSmiley, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        leMessage = new QLineEdit(gridLayoutWidget);
        leMessage->setObjectName(QString::fromUtf8("leMessage"));

        gridLayout->addWidget(leMessage, 2, 0, 1, 1);

        lChat = new QListWidget(gridLayoutWidget);
        lChat->setObjectName(QString::fromUtf8("lChat"));

        gridLayout->addWidget(lChat, 1, 0, 1, 3);

        btnAsk = new QPushButton(Widget);
        btnAsk->setObjectName(QString::fromUtf8("btnAsk"));
        btnAsk->setGeometry(QRect(570, 370, 51, 25));
        btnThrow = new QPushButton(Widget);
        btnThrow->setObjectName(QString::fromUtf8("btnThrow"));
        btnThrow->setGeometry(QRect(540, 760, 111, 61));
        btnThrow->setStyleSheet(QString::fromUtf8("background-color:rgb(138, 226, 52);"));
        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(470, 400, 251, 131));
        plainTextEdit->setStyleSheet(QString::fromUtf8(""));
        plainTextEdit->setReadOnly(true);
        plainTextEdit->setBackgroundVisible(false);
        btnMute = new QPushButton(Widget);
        btnMute->setObjectName(QString::fromUtf8("btnMute"));
        btnMute->setGeometry(QRect(570, 330, 51, 31));
        btnMute->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img-speaker_f"), QSize(), QIcon::Normal, QIcon::Off);
        btnMute->setIcon(icon);
        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(360, 550, 91, 41));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color:rgb(252, 233, 79);;"));
        dice1 = new QPushButton(Widget);
        dice1->setObjectName(QString::fromUtf8("dice1"));
        dice1->setGeometry(QRect(270, 630, 101, 101));
        dice1->setStyleSheet(QString::fromUtf8("background-image: url(:/img/diceq.png);"));
        dice1->setFlat(true);
        dice2 = new QPushButton(Widget);
        dice2->setObjectName(QString::fromUtf8("dice2"));
        dice2->setGeometry(QRect(380, 630, 101, 101));
        dice2->setStyleSheet(QString::fromUtf8("background-image: url(:/img/diceq.png);"));
        dice2->setFlat(true);
        dice3 = new QPushButton(Widget);
        dice3->setObjectName(QString::fromUtf8("dice3"));
        dice3->setGeometry(QRect(490, 630, 101, 101));
        dice3->setStyleSheet(QString::fromUtf8("background-image: url(:/img/diceq.png);"));
        dice3->setFlat(true);
        dice4 = new QPushButton(Widget);
        dice4->setObjectName(QString::fromUtf8("dice4"));
        dice4->setGeometry(QRect(600, 630, 101, 101));
        dice4->setStyleSheet(QString::fromUtf8("background-image: url(:/img/diceq.png);"));
        dice4->setFlat(true);
        dice5 = new QPushButton(Widget);
        dice5->setObjectName(QString::fromUtf8("dice5"));
        dice5->setGeometry(QRect(710, 630, 101, 101));
        dice5->setStyleSheet(QString::fromUtf8("background-image: url(:/img/diceq.png);"));
        dice5->setFlat(true);
        dice6 = new QPushButton(Widget);
        dice6->setObjectName(QString::fromUtf8("dice6"));
        dice6->setGeometry(QRect(820, 630, 101, 101));
        dice6->setStyleSheet(QString::fromUtf8("background-image: url(:/img/diceq.png);"));
        dice6->setFlat(true);
        scrollArea = new QScrollArea(Widget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(600, 310, 131, 101));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 129, 99));
        gridLayoutWidget_2 = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 10, 239, 83));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnSmiley9 = new QPushButton(gridLayoutWidget_2);
        btnSmiley9->setObjectName(QString::fromUtf8("btnSmiley9"));
        btnSmiley9->setFlat(true);

        gridLayout_2->addWidget(btnSmiley9, 2, 2, 1, 1);

        btnSmiley2 = new QPushButton(gridLayoutWidget_2);
        btnSmiley2->setObjectName(QString::fromUtf8("btnSmiley2"));
        btnSmiley2->setFlat(true);

        gridLayout_2->addWidget(btnSmiley2, 0, 1, 1, 1);

        btnSmiley3 = new QPushButton(gridLayoutWidget_2);
        btnSmiley3->setObjectName(QString::fromUtf8("btnSmiley3"));
        btnSmiley3->setFlat(true);

        gridLayout_2->addWidget(btnSmiley3, 0, 2, 1, 1);

        btnSmiley5 = new QPushButton(gridLayoutWidget_2);
        btnSmiley5->setObjectName(QString::fromUtf8("btnSmiley5"));
        btnSmiley5->setFlat(true);

        gridLayout_2->addWidget(btnSmiley5, 1, 1, 1, 1);

        btnSmiley8 = new QPushButton(gridLayoutWidget_2);
        btnSmiley8->setObjectName(QString::fromUtf8("btnSmiley8"));
        btnSmiley8->setFlat(true);

        gridLayout_2->addWidget(btnSmiley8, 2, 1, 1, 1);

        btnSmiley6 = new QPushButton(gridLayoutWidget_2);
        btnSmiley6->setObjectName(QString::fromUtf8("btnSmiley6"));
        btnSmiley6->setFlat(true);

        gridLayout_2->addWidget(btnSmiley6, 1, 2, 1, 1);

        btnSmiley1 = new QPushButton(gridLayoutWidget_2);
        btnSmiley1->setObjectName(QString::fromUtf8("btnSmiley1"));
        btnSmiley1->setFlat(true);

        gridLayout_2->addWidget(btnSmiley1, 0, 0, 1, 1);

        btnSmiley4 = new QPushButton(gridLayoutWidget_2);
        btnSmiley4->setObjectName(QString::fromUtf8("btnSmiley4"));
        btnSmiley4->setFlat(true);

        gridLayout_2->addWidget(btnSmiley4, 1, 0, 1, 1);

        btnSmiley7 = new QPushButton(gridLayoutWidget_2);
        btnSmiley7->setObjectName(QString::fromUtf8("btnSmiley7"));
        btnSmiley7->setFlat(true);

        gridLayout_2->addWidget(btnSmiley7, 2, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        textBrowser_2 = new QTextBrowser(Widget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(740, 550, 91, 41));
        textBrowser_2->setStyleSheet(QString::fromUtf8("background-color:rgb(252, 233, 79);;"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Yamb", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableL->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "\342\226\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableL->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "\342\226\262\342\226\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableL->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Widget", "\342\226\262", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableL->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Widget", "N", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableL->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Widget", "R", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableL->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Widget", "D", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableL->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Widget", "\342\206\225", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableL->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Widget", "\342\206\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableL->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Widget", "M", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableL->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Widget", "O", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableL->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Widget", "YAMB", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableL->verticalHeaderItem(0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Widget", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableL->verticalHeaderItem(1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Widget", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableL->verticalHeaderItem(2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Widget", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableL->verticalHeaderItem(3);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("Widget", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableL->verticalHeaderItem(4);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("Widget", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableL->verticalHeaderItem(5);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("Widget", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableL->verticalHeaderItem(6);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("Widget", "\316\243", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableL->verticalHeaderItem(7);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("Widget", "MAX", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableL->verticalHeaderItem(8);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("Widget", "MIN", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableL->verticalHeaderItem(9);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("Widget", "\316\243", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableL->verticalHeaderItem(10);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("Widget", "KENTA", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableL->verticalHeaderItem(11);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("Widget", "TRILING", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableL->verticalHeaderItem(12);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("Widget", "FUL", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableL->verticalHeaderItem(13);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("Widget", "YAMB", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableL->verticalHeaderItem(14);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("Widget", "\316\243", nullptr));

        const bool __sortingEnabled = tableL->isSortingEnabled();
        tableL->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem26 = tableL->item(0, 10);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("Widget", "\342\232\205", nullptr));
        tableL->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem27 = tableR->horizontalHeaderItem(0);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("Widget", "\342\226\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableR->horizontalHeaderItem(1);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("Widget", "\342\226\262\342\226\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableR->horizontalHeaderItem(2);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("Widget", "\342\226\262", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableR->horizontalHeaderItem(3);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("Widget", "N", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableR->horizontalHeaderItem(4);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("Widget", "R", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableR->horizontalHeaderItem(5);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("Widget", "D", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableR->horizontalHeaderItem(6);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("Widget", "\342\206\225", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableR->horizontalHeaderItem(7);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("Widget", "\342\206\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableR->horizontalHeaderItem(8);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("Widget", "M", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableR->horizontalHeaderItem(9);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("Widget", "O", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableR->horizontalHeaderItem(10);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("Widget", "YAMB", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableR->verticalHeaderItem(0);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("Widget", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableR->verticalHeaderItem(1);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("Widget", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableR->verticalHeaderItem(2);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("Widget", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableR->verticalHeaderItem(3);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("Widget", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableR->verticalHeaderItem(4);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("Widget", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableR->verticalHeaderItem(5);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("Widget", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableR->verticalHeaderItem(6);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("Widget", "\316\243", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableR->verticalHeaderItem(7);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("Widget", "MAX", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableR->verticalHeaderItem(8);
        ___qtablewidgetitem46->setText(QCoreApplication::translate("Widget", "MIN", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tableR->verticalHeaderItem(9);
        ___qtablewidgetitem47->setText(QCoreApplication::translate("Widget", "\316\243", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = tableR->verticalHeaderItem(10);
        ___qtablewidgetitem48->setText(QCoreApplication::translate("Widget", "KENTA", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = tableR->verticalHeaderItem(11);
        ___qtablewidgetitem49->setText(QCoreApplication::translate("Widget", "TRILING", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = tableR->verticalHeaderItem(12);
        ___qtablewidgetitem50->setText(QCoreApplication::translate("Widget", "FUL", nullptr));
        QTableWidgetItem *___qtablewidgetitem51 = tableR->verticalHeaderItem(13);
        ___qtablewidgetitem51->setText(QCoreApplication::translate("Widget", "YAMB", nullptr));
        QTableWidgetItem *___qtablewidgetitem52 = tableR->verticalHeaderItem(14);
        ___qtablewidgetitem52->setText(QCoreApplication::translate("Widget", "\316\243", nullptr));

        const bool __sortingEnabled1 = tableR->isSortingEnabled();
        tableR->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem53 = tableR->item(0, 10);
        ___qtablewidgetitem53->setText(QCoreApplication::translate("Widget", "\342\232\202", nullptr));
        tableR->setSortingEnabled(__sortingEnabled1);

        label->setText(QCoreApplication::translate("Widget", "Opponent's Name", nullptr));
        btnSend->setText(QCoreApplication::translate("Widget", "Send", nullptr));
#if QT_CONFIG(shortcut)
        btnSend->setShortcut(QCoreApplication::translate("Widget", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        btnSmiley->setText(QCoreApplication::translate("Widget", "\342\230\272", nullptr));
        btnAsk->setText(QCoreApplication::translate("Widget", "?", nullptr));
#if QT_CONFIG(shortcut)
        btnAsk->setShortcut(QCoreApplication::translate("Widget", "/", nullptr));
#endif // QT_CONFIG(shortcut)
        btnThrow->setText(QCoreApplication::translate("Widget", "Throw Dices!", nullptr));
#if QT_CONFIG(shortcut)
        btnThrow->setShortcut(QCoreApplication::translate("Widget", "Space", nullptr));
#endif // QT_CONFIG(shortcut)
        plainTextEdit->setPlainText(QCoreApplication::translate("Widget", "N - najava\n"
"R - rucno\n"
"D - obavezna igra najave prethodnog igraca\n"
"O - poslednja kolona koja se popunjava po redu\n"
"M - maksimalni moguci rezultat", nullptr));
        btnMute->setText(QString());
#if QT_CONFIG(shortcut)
        btnMute->setShortcut(QCoreApplication::translate("Widget", "M", nullptr));
#endif // QT_CONFIG(shortcut)
        dice1->setText(QString());
        dice2->setText(QString());
        dice3->setText(QString());
        dice4->setText(QString());
        dice5->setText(QString());
        dice6->setText(QString());
        btnSmiley9->setText(QCoreApplication::translate("Widget", "\360\237\230\210", nullptr));
        btnSmiley2->setText(QCoreApplication::translate("Widget", "\342\230\271", nullptr));
        btnSmiley3->setText(QCoreApplication::translate("Widget", "\360\237\230\240", nullptr));
        btnSmiley5->setText(QCoreApplication::translate("Widget", "\360\237\230\211", nullptr));
        btnSmiley8->setText(QCoreApplication::translate("Widget", "\360\237\230\213", nullptr));
        btnSmiley6->setText(QCoreApplication::translate("Widget", "\360\237\230\230", nullptr));
        btnSmiley1->setText(QCoreApplication::translate("Widget", "\342\230\272", nullptr));
        btnSmiley4->setText(QCoreApplication::translate("Widget", "\360\237\230\201", nullptr));
        btnSmiley7->setText(QCoreApplication::translate("Widget", "\360\237\230\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
