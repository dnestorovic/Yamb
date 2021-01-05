/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTableWidget *tableL;
    QTableWidget *tableR;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *leMessage;
    QPushButton *btnSend;
    QListWidget *lChat;
    QPushButton *btnSmiley;
    QPushButton *btnMuteChat;
    QPushButton *btnMuteChatSound;
    QPushButton *btnThrow;
    QPushButton *btnMute;
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
    QPushButton *btnSmiley4;
    QPushButton *btnSmiley8;
    QPushButton *btnSmiley1;
    QPushButton *btnSmiley9;
    QPushButton *btnSmiley2;
    QPushButton *btnSmiley5;
    QPushButton *btnSmiley7;
    QPushButton *btnSmiley3;
    QPushButton *btnSmiley6;
    QPushButton *btnSurrender;
    QPushButton *btnFinishMove;
    QLabel *labelFinishMove;
    QLabel *labelYourTurn;
    QLabel *labelIllegalMove;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setWindowModality(Qt::NonModal);
        Widget->resize(1200, 860);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        QFont font;
        font.setKerning(true);
        Widget->setFont(font);
        Widget->setAutoFillBackground(false);
        Widget->setStyleSheet(QStringLiteral(""));
        tableL = new QTableWidget(Widget);
        if (tableL->columnCount() < 11)
            tableL->setColumnCount(11);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setForeground(brush);
        tableL->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableL->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableL->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
#ifndef QT_NO_TOOLTIP
        __qtablewidgetitem3->setToolTip(QString::fromUtf8("Popunjava se bilo kojim redosledom, pri \304\215emu je obavezno protivniku Najaviti, nakon prvog bacanja kockica koje polje \305\276elite da popunite, bez mogu\304\207nosti promene izbora polja u slede\304\207a dva bacanja. "));
#endif // QT_NO_TOOLTIP
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
        if (tableL->rowCount() < 16)
            tableL->setRowCount(16);
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
        tableL->setVerticalHeaderItem(15, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(0, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(0, 1, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(0, 2, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(0, 3, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(0, 4, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(0, 5, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(0, 6, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(0, 7, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(0, 8, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(0, 9, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem37->setFlags(Qt::NoItemFlags);
        tableL->setItem(0, 10, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(1, 0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(1, 1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(1, 2, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(1, 3, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(1, 4, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(1, 5, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        __qtablewidgetitem44->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(1, 6, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        __qtablewidgetitem45->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(1, 7, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        __qtablewidgetitem46->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(1, 8, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        __qtablewidgetitem47->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(1, 9, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        __qtablewidgetitem48->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(1, 10, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        __qtablewidgetitem49->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(2, 0, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        __qtablewidgetitem50->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(2, 1, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        __qtablewidgetitem51->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(2, 2, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        __qtablewidgetitem52->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(2, 3, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        __qtablewidgetitem53->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(2, 4, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        __qtablewidgetitem54->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(2, 5, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        __qtablewidgetitem55->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(2, 6, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        __qtablewidgetitem56->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(2, 7, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        __qtablewidgetitem57->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(2, 8, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        __qtablewidgetitem58->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(2, 9, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        __qtablewidgetitem59->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(2, 10, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        __qtablewidgetitem60->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(3, 0, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        __qtablewidgetitem61->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(3, 1, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        __qtablewidgetitem62->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(3, 2, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        __qtablewidgetitem63->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(3, 3, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        __qtablewidgetitem64->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(3, 4, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        __qtablewidgetitem65->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(3, 5, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        __qtablewidgetitem66->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(3, 6, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        __qtablewidgetitem67->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(3, 7, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        __qtablewidgetitem68->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(3, 8, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        __qtablewidgetitem69->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(3, 9, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        __qtablewidgetitem70->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(3, 10, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        __qtablewidgetitem71->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(4, 0, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        __qtablewidgetitem72->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(4, 1, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        __qtablewidgetitem73->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(4, 2, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        __qtablewidgetitem74->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(4, 3, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        __qtablewidgetitem75->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(4, 4, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        __qtablewidgetitem76->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(4, 5, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        __qtablewidgetitem77->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(4, 6, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        __qtablewidgetitem78->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(4, 7, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        __qtablewidgetitem79->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(4, 8, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        __qtablewidgetitem80->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(4, 9, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        __qtablewidgetitem81->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(4, 10, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        __qtablewidgetitem82->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(5, 0, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        __qtablewidgetitem83->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(5, 1, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        __qtablewidgetitem84->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(5, 2, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        __qtablewidgetitem85->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(5, 3, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        __qtablewidgetitem86->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(5, 4, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        __qtablewidgetitem87->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(5, 5, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        __qtablewidgetitem88->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(5, 6, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        __qtablewidgetitem89->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(5, 7, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        __qtablewidgetitem90->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(5, 8, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        __qtablewidgetitem91->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(5, 9, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        __qtablewidgetitem92->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(5, 10, __qtablewidgetitem92);
        QBrush brush1(QColor(252, 233, 79, 255));
        brush1.setStyle(Qt::SolidPattern);
        QFont font1;
        font1.setPointSize(8);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        __qtablewidgetitem93->setFont(font1);
        __qtablewidgetitem93->setBackground(brush1);
        __qtablewidgetitem93->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(6, 0, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        __qtablewidgetitem94->setFont(font1);
        __qtablewidgetitem94->setBackground(brush1);
        __qtablewidgetitem94->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(6, 1, __qtablewidgetitem94);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        __qtablewidgetitem95->setFont(font1);
        __qtablewidgetitem95->setBackground(brush1);
        __qtablewidgetitem95->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(6, 2, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        __qtablewidgetitem96->setFont(font1);
        __qtablewidgetitem96->setBackground(brush1);
        __qtablewidgetitem96->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(6, 3, __qtablewidgetitem96);
        QTableWidgetItem *__qtablewidgetitem97 = new QTableWidgetItem();
        __qtablewidgetitem97->setFont(font1);
        __qtablewidgetitem97->setBackground(brush1);
        __qtablewidgetitem97->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(6, 4, __qtablewidgetitem97);
        QTableWidgetItem *__qtablewidgetitem98 = new QTableWidgetItem();
        __qtablewidgetitem98->setFont(font1);
        __qtablewidgetitem98->setBackground(brush1);
        __qtablewidgetitem98->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(6, 5, __qtablewidgetitem98);
        QTableWidgetItem *__qtablewidgetitem99 = new QTableWidgetItem();
        __qtablewidgetitem99->setFont(font1);
        __qtablewidgetitem99->setBackground(brush1);
        __qtablewidgetitem99->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(6, 6, __qtablewidgetitem99);
        QTableWidgetItem *__qtablewidgetitem100 = new QTableWidgetItem();
        __qtablewidgetitem100->setFont(font1);
        __qtablewidgetitem100->setBackground(brush1);
        __qtablewidgetitem100->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(6, 7, __qtablewidgetitem100);
        QTableWidgetItem *__qtablewidgetitem101 = new QTableWidgetItem();
        __qtablewidgetitem101->setFont(font1);
        __qtablewidgetitem101->setBackground(brush1);
        __qtablewidgetitem101->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(6, 8, __qtablewidgetitem101);
        QTableWidgetItem *__qtablewidgetitem102 = new QTableWidgetItem();
        __qtablewidgetitem102->setFont(font1);
        __qtablewidgetitem102->setBackground(brush1);
        __qtablewidgetitem102->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(6, 9, __qtablewidgetitem102);
        QTableWidgetItem *__qtablewidgetitem103 = new QTableWidgetItem();
        __qtablewidgetitem103->setFont(font1);
        __qtablewidgetitem103->setBackground(brush1);
        __qtablewidgetitem103->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(6, 10, __qtablewidgetitem103);
        QTableWidgetItem *__qtablewidgetitem104 = new QTableWidgetItem();
        __qtablewidgetitem104->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(7, 0, __qtablewidgetitem104);
        QTableWidgetItem *__qtablewidgetitem105 = new QTableWidgetItem();
        __qtablewidgetitem105->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(7, 1, __qtablewidgetitem105);
        QTableWidgetItem *__qtablewidgetitem106 = new QTableWidgetItem();
        __qtablewidgetitem106->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(7, 2, __qtablewidgetitem106);
        QTableWidgetItem *__qtablewidgetitem107 = new QTableWidgetItem();
        __qtablewidgetitem107->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(7, 3, __qtablewidgetitem107);
        QTableWidgetItem *__qtablewidgetitem108 = new QTableWidgetItem();
        __qtablewidgetitem108->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(7, 4, __qtablewidgetitem108);
        QTableWidgetItem *__qtablewidgetitem109 = new QTableWidgetItem();
        __qtablewidgetitem109->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(7, 5, __qtablewidgetitem109);
        QTableWidgetItem *__qtablewidgetitem110 = new QTableWidgetItem();
        __qtablewidgetitem110->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(7, 6, __qtablewidgetitem110);
        QTableWidgetItem *__qtablewidgetitem111 = new QTableWidgetItem();
        __qtablewidgetitem111->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(7, 7, __qtablewidgetitem111);
        QTableWidgetItem *__qtablewidgetitem112 = new QTableWidgetItem();
        __qtablewidgetitem112->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(7, 8, __qtablewidgetitem112);
        QTableWidgetItem *__qtablewidgetitem113 = new QTableWidgetItem();
        __qtablewidgetitem113->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(7, 9, __qtablewidgetitem113);
        QTableWidgetItem *__qtablewidgetitem114 = new QTableWidgetItem();
        __qtablewidgetitem114->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(7, 10, __qtablewidgetitem114);
        QTableWidgetItem *__qtablewidgetitem115 = new QTableWidgetItem();
        __qtablewidgetitem115->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(8, 0, __qtablewidgetitem115);
        QTableWidgetItem *__qtablewidgetitem116 = new QTableWidgetItem();
        __qtablewidgetitem116->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(8, 1, __qtablewidgetitem116);
        QTableWidgetItem *__qtablewidgetitem117 = new QTableWidgetItem();
        __qtablewidgetitem117->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(8, 2, __qtablewidgetitem117);
        QTableWidgetItem *__qtablewidgetitem118 = new QTableWidgetItem();
        __qtablewidgetitem118->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(8, 3, __qtablewidgetitem118);
        QTableWidgetItem *__qtablewidgetitem119 = new QTableWidgetItem();
        __qtablewidgetitem119->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(8, 4, __qtablewidgetitem119);
        QTableWidgetItem *__qtablewidgetitem120 = new QTableWidgetItem();
        __qtablewidgetitem120->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(8, 5, __qtablewidgetitem120);
        QTableWidgetItem *__qtablewidgetitem121 = new QTableWidgetItem();
        __qtablewidgetitem121->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(8, 6, __qtablewidgetitem121);
        QTableWidgetItem *__qtablewidgetitem122 = new QTableWidgetItem();
        __qtablewidgetitem122->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(8, 7, __qtablewidgetitem122);
        QTableWidgetItem *__qtablewidgetitem123 = new QTableWidgetItem();
        __qtablewidgetitem123->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(8, 8, __qtablewidgetitem123);
        QTableWidgetItem *__qtablewidgetitem124 = new QTableWidgetItem();
        __qtablewidgetitem124->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(8, 9, __qtablewidgetitem124);
        QTableWidgetItem *__qtablewidgetitem125 = new QTableWidgetItem();
        __qtablewidgetitem125->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(8, 10, __qtablewidgetitem125);
        QTableWidgetItem *__qtablewidgetitem126 = new QTableWidgetItem();
        __qtablewidgetitem126->setFont(font1);
        __qtablewidgetitem126->setBackground(brush1);
        __qtablewidgetitem126->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(9, 0, __qtablewidgetitem126);
        QTableWidgetItem *__qtablewidgetitem127 = new QTableWidgetItem();
        __qtablewidgetitem127->setFont(font1);
        __qtablewidgetitem127->setBackground(brush1);
        __qtablewidgetitem127->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(9, 1, __qtablewidgetitem127);
        QTableWidgetItem *__qtablewidgetitem128 = new QTableWidgetItem();
        __qtablewidgetitem128->setFont(font1);
        __qtablewidgetitem128->setBackground(brush1);
        __qtablewidgetitem128->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(9, 2, __qtablewidgetitem128);
        QTableWidgetItem *__qtablewidgetitem129 = new QTableWidgetItem();
        __qtablewidgetitem129->setFont(font1);
        __qtablewidgetitem129->setBackground(brush1);
        __qtablewidgetitem129->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(9, 3, __qtablewidgetitem129);
        QTableWidgetItem *__qtablewidgetitem130 = new QTableWidgetItem();
        __qtablewidgetitem130->setFont(font1);
        __qtablewidgetitem130->setBackground(brush1);
        __qtablewidgetitem130->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(9, 4, __qtablewidgetitem130);
        QTableWidgetItem *__qtablewidgetitem131 = new QTableWidgetItem();
        __qtablewidgetitem131->setFont(font1);
        __qtablewidgetitem131->setBackground(brush1);
        __qtablewidgetitem131->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(9, 5, __qtablewidgetitem131);
        QTableWidgetItem *__qtablewidgetitem132 = new QTableWidgetItem();
        __qtablewidgetitem132->setFont(font1);
        __qtablewidgetitem132->setBackground(brush1);
        __qtablewidgetitem132->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(9, 6, __qtablewidgetitem132);
        QTableWidgetItem *__qtablewidgetitem133 = new QTableWidgetItem();
        __qtablewidgetitem133->setFont(font1);
        __qtablewidgetitem133->setBackground(brush1);
        __qtablewidgetitem133->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(9, 7, __qtablewidgetitem133);
        QTableWidgetItem *__qtablewidgetitem134 = new QTableWidgetItem();
        __qtablewidgetitem134->setFont(font1);
        __qtablewidgetitem134->setBackground(brush1);
        __qtablewidgetitem134->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(9, 8, __qtablewidgetitem134);
        QTableWidgetItem *__qtablewidgetitem135 = new QTableWidgetItem();
        __qtablewidgetitem135->setFont(font1);
        __qtablewidgetitem135->setBackground(brush1);
        __qtablewidgetitem135->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(9, 9, __qtablewidgetitem135);
        QTableWidgetItem *__qtablewidgetitem136 = new QTableWidgetItem();
        __qtablewidgetitem136->setFont(font1);
        __qtablewidgetitem136->setBackground(brush1);
        __qtablewidgetitem136->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(9, 10, __qtablewidgetitem136);
        QTableWidgetItem *__qtablewidgetitem137 = new QTableWidgetItem();
        __qtablewidgetitem137->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(10, 0, __qtablewidgetitem137);
        QTableWidgetItem *__qtablewidgetitem138 = new QTableWidgetItem();
        __qtablewidgetitem138->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(10, 1, __qtablewidgetitem138);
        QTableWidgetItem *__qtablewidgetitem139 = new QTableWidgetItem();
        __qtablewidgetitem139->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(10, 2, __qtablewidgetitem139);
        QTableWidgetItem *__qtablewidgetitem140 = new QTableWidgetItem();
        __qtablewidgetitem140->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(10, 3, __qtablewidgetitem140);
        QTableWidgetItem *__qtablewidgetitem141 = new QTableWidgetItem();
        __qtablewidgetitem141->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(10, 4, __qtablewidgetitem141);
        QTableWidgetItem *__qtablewidgetitem142 = new QTableWidgetItem();
        __qtablewidgetitem142->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(10, 5, __qtablewidgetitem142);
        QTableWidgetItem *__qtablewidgetitem143 = new QTableWidgetItem();
        __qtablewidgetitem143->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(10, 6, __qtablewidgetitem143);
        QTableWidgetItem *__qtablewidgetitem144 = new QTableWidgetItem();
        __qtablewidgetitem144->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(10, 7, __qtablewidgetitem144);
        QTableWidgetItem *__qtablewidgetitem145 = new QTableWidgetItem();
        __qtablewidgetitem145->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(10, 8, __qtablewidgetitem145);
        QTableWidgetItem *__qtablewidgetitem146 = new QTableWidgetItem();
        __qtablewidgetitem146->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(10, 9, __qtablewidgetitem146);
        QTableWidgetItem *__qtablewidgetitem147 = new QTableWidgetItem();
        __qtablewidgetitem147->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(10, 10, __qtablewidgetitem147);
        QTableWidgetItem *__qtablewidgetitem148 = new QTableWidgetItem();
        __qtablewidgetitem148->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(11, 0, __qtablewidgetitem148);
        QTableWidgetItem *__qtablewidgetitem149 = new QTableWidgetItem();
        __qtablewidgetitem149->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(11, 1, __qtablewidgetitem149);
        QTableWidgetItem *__qtablewidgetitem150 = new QTableWidgetItem();
        __qtablewidgetitem150->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(11, 2, __qtablewidgetitem150);
        QTableWidgetItem *__qtablewidgetitem151 = new QTableWidgetItem();
        __qtablewidgetitem151->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(11, 3, __qtablewidgetitem151);
        QTableWidgetItem *__qtablewidgetitem152 = new QTableWidgetItem();
        __qtablewidgetitem152->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(11, 4, __qtablewidgetitem152);
        QTableWidgetItem *__qtablewidgetitem153 = new QTableWidgetItem();
        __qtablewidgetitem153->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(11, 5, __qtablewidgetitem153);
        QTableWidgetItem *__qtablewidgetitem154 = new QTableWidgetItem();
        __qtablewidgetitem154->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(11, 6, __qtablewidgetitem154);
        QTableWidgetItem *__qtablewidgetitem155 = new QTableWidgetItem();
        __qtablewidgetitem155->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(11, 7, __qtablewidgetitem155);
        QTableWidgetItem *__qtablewidgetitem156 = new QTableWidgetItem();
        __qtablewidgetitem156->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(11, 8, __qtablewidgetitem156);
        QTableWidgetItem *__qtablewidgetitem157 = new QTableWidgetItem();
        __qtablewidgetitem157->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(11, 9, __qtablewidgetitem157);
        QTableWidgetItem *__qtablewidgetitem158 = new QTableWidgetItem();
        __qtablewidgetitem158->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(11, 10, __qtablewidgetitem158);
        QTableWidgetItem *__qtablewidgetitem159 = new QTableWidgetItem();
        __qtablewidgetitem159->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(12, 0, __qtablewidgetitem159);
        QTableWidgetItem *__qtablewidgetitem160 = new QTableWidgetItem();
        __qtablewidgetitem160->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(12, 1, __qtablewidgetitem160);
        QTableWidgetItem *__qtablewidgetitem161 = new QTableWidgetItem();
        __qtablewidgetitem161->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(12, 2, __qtablewidgetitem161);
        QTableWidgetItem *__qtablewidgetitem162 = new QTableWidgetItem();
        __qtablewidgetitem162->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(12, 3, __qtablewidgetitem162);
        QTableWidgetItem *__qtablewidgetitem163 = new QTableWidgetItem();
        __qtablewidgetitem163->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(12, 4, __qtablewidgetitem163);
        QTableWidgetItem *__qtablewidgetitem164 = new QTableWidgetItem();
        __qtablewidgetitem164->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(12, 5, __qtablewidgetitem164);
        QTableWidgetItem *__qtablewidgetitem165 = new QTableWidgetItem();
        __qtablewidgetitem165->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(12, 6, __qtablewidgetitem165);
        QTableWidgetItem *__qtablewidgetitem166 = new QTableWidgetItem();
        __qtablewidgetitem166->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(12, 7, __qtablewidgetitem166);
        QTableWidgetItem *__qtablewidgetitem167 = new QTableWidgetItem();
        __qtablewidgetitem167->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(12, 8, __qtablewidgetitem167);
        QTableWidgetItem *__qtablewidgetitem168 = new QTableWidgetItem();
        __qtablewidgetitem168->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(12, 9, __qtablewidgetitem168);
        QTableWidgetItem *__qtablewidgetitem169 = new QTableWidgetItem();
        __qtablewidgetitem169->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(12, 10, __qtablewidgetitem169);
        QTableWidgetItem *__qtablewidgetitem170 = new QTableWidgetItem();
        __qtablewidgetitem170->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(13, 0, __qtablewidgetitem170);
        QTableWidgetItem *__qtablewidgetitem171 = new QTableWidgetItem();
        __qtablewidgetitem171->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(13, 1, __qtablewidgetitem171);
        QTableWidgetItem *__qtablewidgetitem172 = new QTableWidgetItem();
        __qtablewidgetitem172->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(13, 2, __qtablewidgetitem172);
        QTableWidgetItem *__qtablewidgetitem173 = new QTableWidgetItem();
        __qtablewidgetitem173->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(13, 3, __qtablewidgetitem173);
        QTableWidgetItem *__qtablewidgetitem174 = new QTableWidgetItem();
        __qtablewidgetitem174->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(13, 4, __qtablewidgetitem174);
        QTableWidgetItem *__qtablewidgetitem175 = new QTableWidgetItem();
        __qtablewidgetitem175->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(13, 5, __qtablewidgetitem175);
        QTableWidgetItem *__qtablewidgetitem176 = new QTableWidgetItem();
        __qtablewidgetitem176->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(13, 6, __qtablewidgetitem176);
        QTableWidgetItem *__qtablewidgetitem177 = new QTableWidgetItem();
        __qtablewidgetitem177->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(13, 7, __qtablewidgetitem177);
        QTableWidgetItem *__qtablewidgetitem178 = new QTableWidgetItem();
        __qtablewidgetitem178->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(13, 8, __qtablewidgetitem178);
        QTableWidgetItem *__qtablewidgetitem179 = new QTableWidgetItem();
        __qtablewidgetitem179->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(13, 9, __qtablewidgetitem179);
        QTableWidgetItem *__qtablewidgetitem180 = new QTableWidgetItem();
        __qtablewidgetitem180->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(13, 10, __qtablewidgetitem180);
        QTableWidgetItem *__qtablewidgetitem181 = new QTableWidgetItem();
        __qtablewidgetitem181->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(14, 0, __qtablewidgetitem181);
        QTableWidgetItem *__qtablewidgetitem182 = new QTableWidgetItem();
        __qtablewidgetitem182->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(14, 1, __qtablewidgetitem182);
        QTableWidgetItem *__qtablewidgetitem183 = new QTableWidgetItem();
        __qtablewidgetitem183->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(14, 2, __qtablewidgetitem183);
        QTableWidgetItem *__qtablewidgetitem184 = new QTableWidgetItem();
        __qtablewidgetitem184->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(14, 3, __qtablewidgetitem184);
        QTableWidgetItem *__qtablewidgetitem185 = new QTableWidgetItem();
        __qtablewidgetitem185->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(14, 4, __qtablewidgetitem185);
        QTableWidgetItem *__qtablewidgetitem186 = new QTableWidgetItem();
        __qtablewidgetitem186->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(14, 5, __qtablewidgetitem186);
        QTableWidgetItem *__qtablewidgetitem187 = new QTableWidgetItem();
        __qtablewidgetitem187->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(14, 6, __qtablewidgetitem187);
        QTableWidgetItem *__qtablewidgetitem188 = new QTableWidgetItem();
        __qtablewidgetitem188->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(14, 7, __qtablewidgetitem188);
        QTableWidgetItem *__qtablewidgetitem189 = new QTableWidgetItem();
        __qtablewidgetitem189->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(14, 8, __qtablewidgetitem189);
        QTableWidgetItem *__qtablewidgetitem190 = new QTableWidgetItem();
        __qtablewidgetitem190->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableL->setItem(14, 9, __qtablewidgetitem190);
        QTableWidgetItem *__qtablewidgetitem191 = new QTableWidgetItem();
        __qtablewidgetitem191->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(14, 10, __qtablewidgetitem191);
        QTableWidgetItem *__qtablewidgetitem192 = new QTableWidgetItem();
        __qtablewidgetitem192->setFont(font1);
        __qtablewidgetitem192->setBackground(brush1);
        __qtablewidgetitem192->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(15, 0, __qtablewidgetitem192);
        QTableWidgetItem *__qtablewidgetitem193 = new QTableWidgetItem();
        __qtablewidgetitem193->setFont(font1);
        __qtablewidgetitem193->setBackground(brush1);
        __qtablewidgetitem193->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(15, 1, __qtablewidgetitem193);
        QTableWidgetItem *__qtablewidgetitem194 = new QTableWidgetItem();
        __qtablewidgetitem194->setFont(font1);
        __qtablewidgetitem194->setBackground(brush1);
        __qtablewidgetitem194->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(15, 2, __qtablewidgetitem194);
        QTableWidgetItem *__qtablewidgetitem195 = new QTableWidgetItem();
        __qtablewidgetitem195->setFont(font1);
        __qtablewidgetitem195->setBackground(brush1);
        __qtablewidgetitem195->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(15, 3, __qtablewidgetitem195);
        QTableWidgetItem *__qtablewidgetitem196 = new QTableWidgetItem();
        __qtablewidgetitem196->setFont(font1);
        __qtablewidgetitem196->setBackground(brush1);
        __qtablewidgetitem196->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(15, 4, __qtablewidgetitem196);
        QTableWidgetItem *__qtablewidgetitem197 = new QTableWidgetItem();
        __qtablewidgetitem197->setFont(font1);
        __qtablewidgetitem197->setBackground(brush1);
        __qtablewidgetitem197->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(15, 5, __qtablewidgetitem197);
        QTableWidgetItem *__qtablewidgetitem198 = new QTableWidgetItem();
        __qtablewidgetitem198->setFont(font1);
        __qtablewidgetitem198->setBackground(brush1);
        __qtablewidgetitem198->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(15, 6, __qtablewidgetitem198);
        QTableWidgetItem *__qtablewidgetitem199 = new QTableWidgetItem();
        __qtablewidgetitem199->setFont(font1);
        __qtablewidgetitem199->setBackground(brush1);
        __qtablewidgetitem199->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(15, 7, __qtablewidgetitem199);
        QTableWidgetItem *__qtablewidgetitem200 = new QTableWidgetItem();
        __qtablewidgetitem200->setFont(font1);
        __qtablewidgetitem200->setBackground(brush1);
        __qtablewidgetitem200->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(15, 8, __qtablewidgetitem200);
        QTableWidgetItem *__qtablewidgetitem201 = new QTableWidgetItem();
        __qtablewidgetitem201->setFont(font1);
        __qtablewidgetitem201->setBackground(brush1);
        __qtablewidgetitem201->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(15, 9, __qtablewidgetitem201);
        QTableWidgetItem *__qtablewidgetitem202 = new QTableWidgetItem();
        __qtablewidgetitem202->setFont(font1);
        __qtablewidgetitem202->setBackground(brush1);
        __qtablewidgetitem202->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled);
        tableL->setItem(15, 10, __qtablewidgetitem202);
        tableL->setObjectName(QStringLiteral("tableL"));
        tableL->setGeometry(QRect(30, 50, 423, 511));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableL->sizePolicy().hasHeightForWidth());
        tableL->setSizePolicy(sizePolicy1);
        tableL->setFocusPolicy(Qt::ClickFocus);
        tableL->setStyleSheet(QStringLiteral("background-color:rgb(114, 159, 207);"));
        tableL->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableL->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableL->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableL->setAutoScroll(false);
        tableL->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableL->setTabKeyNavigation(false);
        tableL->setDragDropOverwriteMode(false);
        tableL->setSelectionMode(QAbstractItemView::SingleSelection);
        tableL->setSelectionBehavior(QAbstractItemView::SelectItems);
        tableL->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableL->horizontalHeader()->setHighlightSections(false);
        tableL->horizontalHeader()->setMinimumSectionSize(20);
        tableL->verticalHeader()->setDefaultSectionSize(30);
        tableL->verticalHeader()->setHighlightSections(false);
        tableL->verticalHeader()->setMinimumSectionSize(10);
        tableR = new QTableWidget(Widget);
        if (tableR->columnCount() < 11)
            tableR->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem203 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(0, __qtablewidgetitem203);
        QTableWidgetItem *__qtablewidgetitem204 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(1, __qtablewidgetitem204);
        QTableWidgetItem *__qtablewidgetitem205 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(2, __qtablewidgetitem205);
        QTableWidgetItem *__qtablewidgetitem206 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(3, __qtablewidgetitem206);
        QTableWidgetItem *__qtablewidgetitem207 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(4, __qtablewidgetitem207);
        QTableWidgetItem *__qtablewidgetitem208 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(5, __qtablewidgetitem208);
        QTableWidgetItem *__qtablewidgetitem209 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(6, __qtablewidgetitem209);
        QTableWidgetItem *__qtablewidgetitem210 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(7, __qtablewidgetitem210);
        QTableWidgetItem *__qtablewidgetitem211 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(8, __qtablewidgetitem211);
        QTableWidgetItem *__qtablewidgetitem212 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(9, __qtablewidgetitem212);
        QTableWidgetItem *__qtablewidgetitem213 = new QTableWidgetItem();
        tableR->setHorizontalHeaderItem(10, __qtablewidgetitem213);
        if (tableR->rowCount() < 16)
            tableR->setRowCount(16);
        QTableWidgetItem *__qtablewidgetitem214 = new QTableWidgetItem();
        __qtablewidgetitem214->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(0, __qtablewidgetitem214);
        QTableWidgetItem *__qtablewidgetitem215 = new QTableWidgetItem();
        __qtablewidgetitem215->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(1, __qtablewidgetitem215);
        QTableWidgetItem *__qtablewidgetitem216 = new QTableWidgetItem();
        __qtablewidgetitem216->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(2, __qtablewidgetitem216);
        QTableWidgetItem *__qtablewidgetitem217 = new QTableWidgetItem();
        __qtablewidgetitem217->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(3, __qtablewidgetitem217);
        QTableWidgetItem *__qtablewidgetitem218 = new QTableWidgetItem();
        __qtablewidgetitem218->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(4, __qtablewidgetitem218);
        QTableWidgetItem *__qtablewidgetitem219 = new QTableWidgetItem();
        __qtablewidgetitem219->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(5, __qtablewidgetitem219);
        QTableWidgetItem *__qtablewidgetitem220 = new QTableWidgetItem();
        __qtablewidgetitem220->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(6, __qtablewidgetitem220);
        QTableWidgetItem *__qtablewidgetitem221 = new QTableWidgetItem();
        __qtablewidgetitem221->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(7, __qtablewidgetitem221);
        QTableWidgetItem *__qtablewidgetitem222 = new QTableWidgetItem();
        __qtablewidgetitem222->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(8, __qtablewidgetitem222);
        QTableWidgetItem *__qtablewidgetitem223 = new QTableWidgetItem();
        __qtablewidgetitem223->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(9, __qtablewidgetitem223);
        QTableWidgetItem *__qtablewidgetitem224 = new QTableWidgetItem();
        __qtablewidgetitem224->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(10, __qtablewidgetitem224);
        QTableWidgetItem *__qtablewidgetitem225 = new QTableWidgetItem();
        __qtablewidgetitem225->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(11, __qtablewidgetitem225);
        QTableWidgetItem *__qtablewidgetitem226 = new QTableWidgetItem();
        __qtablewidgetitem226->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(12, __qtablewidgetitem226);
        QTableWidgetItem *__qtablewidgetitem227 = new QTableWidgetItem();
        __qtablewidgetitem227->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(13, __qtablewidgetitem227);
        QTableWidgetItem *__qtablewidgetitem228 = new QTableWidgetItem();
        __qtablewidgetitem228->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(14, __qtablewidgetitem228);
        QTableWidgetItem *__qtablewidgetitem229 = new QTableWidgetItem();
        __qtablewidgetitem229->setTextAlignment(Qt::AlignCenter);
        tableR->setVerticalHeaderItem(15, __qtablewidgetitem229);
        QTableWidgetItem *__qtablewidgetitem230 = new QTableWidgetItem();
        __qtablewidgetitem230->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(0, 0, __qtablewidgetitem230);
        QTableWidgetItem *__qtablewidgetitem231 = new QTableWidgetItem();
        __qtablewidgetitem231->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(0, 1, __qtablewidgetitem231);
        QTableWidgetItem *__qtablewidgetitem232 = new QTableWidgetItem();
        __qtablewidgetitem232->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(0, 2, __qtablewidgetitem232);
        QTableWidgetItem *__qtablewidgetitem233 = new QTableWidgetItem();
        __qtablewidgetitem233->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(0, 3, __qtablewidgetitem233);
        QTableWidgetItem *__qtablewidgetitem234 = new QTableWidgetItem();
        __qtablewidgetitem234->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(0, 4, __qtablewidgetitem234);
        QTableWidgetItem *__qtablewidgetitem235 = new QTableWidgetItem();
        __qtablewidgetitem235->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(0, 5, __qtablewidgetitem235);
        QTableWidgetItem *__qtablewidgetitem236 = new QTableWidgetItem();
        __qtablewidgetitem236->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(0, 6, __qtablewidgetitem236);
        QTableWidgetItem *__qtablewidgetitem237 = new QTableWidgetItem();
        __qtablewidgetitem237->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(0, 7, __qtablewidgetitem237);
        QTableWidgetItem *__qtablewidgetitem238 = new QTableWidgetItem();
        __qtablewidgetitem238->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(0, 8, __qtablewidgetitem238);
        QTableWidgetItem *__qtablewidgetitem239 = new QTableWidgetItem();
        __qtablewidgetitem239->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(0, 9, __qtablewidgetitem239);
        QTableWidgetItem *__qtablewidgetitem240 = new QTableWidgetItem();
        __qtablewidgetitem240->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem240->setFlags(Qt::NoItemFlags);
        tableR->setItem(0, 10, __qtablewidgetitem240);
        QTableWidgetItem *__qtablewidgetitem241 = new QTableWidgetItem();
        __qtablewidgetitem241->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(1, 0, __qtablewidgetitem241);
        QTableWidgetItem *__qtablewidgetitem242 = new QTableWidgetItem();
        __qtablewidgetitem242->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(1, 1, __qtablewidgetitem242);
        QTableWidgetItem *__qtablewidgetitem243 = new QTableWidgetItem();
        __qtablewidgetitem243->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(1, 2, __qtablewidgetitem243);
        QTableWidgetItem *__qtablewidgetitem244 = new QTableWidgetItem();
        __qtablewidgetitem244->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(1, 3, __qtablewidgetitem244);
        QTableWidgetItem *__qtablewidgetitem245 = new QTableWidgetItem();
        __qtablewidgetitem245->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(1, 4, __qtablewidgetitem245);
        QTableWidgetItem *__qtablewidgetitem246 = new QTableWidgetItem();
        __qtablewidgetitem246->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(1, 5, __qtablewidgetitem246);
        QTableWidgetItem *__qtablewidgetitem247 = new QTableWidgetItem();
        __qtablewidgetitem247->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(1, 6, __qtablewidgetitem247);
        QTableWidgetItem *__qtablewidgetitem248 = new QTableWidgetItem();
        __qtablewidgetitem248->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(1, 7, __qtablewidgetitem248);
        QTableWidgetItem *__qtablewidgetitem249 = new QTableWidgetItem();
        __qtablewidgetitem249->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(1, 8, __qtablewidgetitem249);
        QTableWidgetItem *__qtablewidgetitem250 = new QTableWidgetItem();
        __qtablewidgetitem250->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(1, 9, __qtablewidgetitem250);
        QTableWidgetItem *__qtablewidgetitem251 = new QTableWidgetItem();
        __qtablewidgetitem251->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(1, 10, __qtablewidgetitem251);
        QTableWidgetItem *__qtablewidgetitem252 = new QTableWidgetItem();
        __qtablewidgetitem252->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(2, 0, __qtablewidgetitem252);
        QTableWidgetItem *__qtablewidgetitem253 = new QTableWidgetItem();
        __qtablewidgetitem253->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(2, 1, __qtablewidgetitem253);
        QTableWidgetItem *__qtablewidgetitem254 = new QTableWidgetItem();
        __qtablewidgetitem254->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(2, 2, __qtablewidgetitem254);
        QTableWidgetItem *__qtablewidgetitem255 = new QTableWidgetItem();
        __qtablewidgetitem255->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(2, 3, __qtablewidgetitem255);
        QTableWidgetItem *__qtablewidgetitem256 = new QTableWidgetItem();
        __qtablewidgetitem256->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(2, 4, __qtablewidgetitem256);
        QTableWidgetItem *__qtablewidgetitem257 = new QTableWidgetItem();
        __qtablewidgetitem257->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(2, 5, __qtablewidgetitem257);
        QTableWidgetItem *__qtablewidgetitem258 = new QTableWidgetItem();
        __qtablewidgetitem258->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(2, 6, __qtablewidgetitem258);
        QTableWidgetItem *__qtablewidgetitem259 = new QTableWidgetItem();
        __qtablewidgetitem259->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(2, 7, __qtablewidgetitem259);
        QTableWidgetItem *__qtablewidgetitem260 = new QTableWidgetItem();
        __qtablewidgetitem260->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(2, 8, __qtablewidgetitem260);
        QTableWidgetItem *__qtablewidgetitem261 = new QTableWidgetItem();
        __qtablewidgetitem261->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(2, 9, __qtablewidgetitem261);
        QTableWidgetItem *__qtablewidgetitem262 = new QTableWidgetItem();
        __qtablewidgetitem262->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(2, 10, __qtablewidgetitem262);
        QTableWidgetItem *__qtablewidgetitem263 = new QTableWidgetItem();
        __qtablewidgetitem263->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(3, 0, __qtablewidgetitem263);
        QTableWidgetItem *__qtablewidgetitem264 = new QTableWidgetItem();
        __qtablewidgetitem264->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(3, 1, __qtablewidgetitem264);
        QTableWidgetItem *__qtablewidgetitem265 = new QTableWidgetItem();
        __qtablewidgetitem265->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(3, 2, __qtablewidgetitem265);
        QTableWidgetItem *__qtablewidgetitem266 = new QTableWidgetItem();
        __qtablewidgetitem266->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(3, 3, __qtablewidgetitem266);
        QTableWidgetItem *__qtablewidgetitem267 = new QTableWidgetItem();
        __qtablewidgetitem267->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(3, 4, __qtablewidgetitem267);
        QTableWidgetItem *__qtablewidgetitem268 = new QTableWidgetItem();
        __qtablewidgetitem268->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(3, 5, __qtablewidgetitem268);
        QTableWidgetItem *__qtablewidgetitem269 = new QTableWidgetItem();
        __qtablewidgetitem269->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(3, 6, __qtablewidgetitem269);
        QTableWidgetItem *__qtablewidgetitem270 = new QTableWidgetItem();
        __qtablewidgetitem270->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(3, 7, __qtablewidgetitem270);
        QTableWidgetItem *__qtablewidgetitem271 = new QTableWidgetItem();
        __qtablewidgetitem271->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(3, 8, __qtablewidgetitem271);
        QTableWidgetItem *__qtablewidgetitem272 = new QTableWidgetItem();
        __qtablewidgetitem272->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(3, 9, __qtablewidgetitem272);
        QTableWidgetItem *__qtablewidgetitem273 = new QTableWidgetItem();
        __qtablewidgetitem273->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(3, 10, __qtablewidgetitem273);
        QTableWidgetItem *__qtablewidgetitem274 = new QTableWidgetItem();
        __qtablewidgetitem274->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(4, 0, __qtablewidgetitem274);
        QTableWidgetItem *__qtablewidgetitem275 = new QTableWidgetItem();
        __qtablewidgetitem275->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(4, 1, __qtablewidgetitem275);
        QTableWidgetItem *__qtablewidgetitem276 = new QTableWidgetItem();
        __qtablewidgetitem276->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(4, 2, __qtablewidgetitem276);
        QTableWidgetItem *__qtablewidgetitem277 = new QTableWidgetItem();
        __qtablewidgetitem277->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(4, 3, __qtablewidgetitem277);
        QTableWidgetItem *__qtablewidgetitem278 = new QTableWidgetItem();
        __qtablewidgetitem278->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(4, 4, __qtablewidgetitem278);
        QTableWidgetItem *__qtablewidgetitem279 = new QTableWidgetItem();
        __qtablewidgetitem279->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(4, 5, __qtablewidgetitem279);
        QTableWidgetItem *__qtablewidgetitem280 = new QTableWidgetItem();
        __qtablewidgetitem280->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(4, 6, __qtablewidgetitem280);
        QTableWidgetItem *__qtablewidgetitem281 = new QTableWidgetItem();
        __qtablewidgetitem281->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(4, 7, __qtablewidgetitem281);
        QTableWidgetItem *__qtablewidgetitem282 = new QTableWidgetItem();
        __qtablewidgetitem282->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(4, 8, __qtablewidgetitem282);
        QTableWidgetItem *__qtablewidgetitem283 = new QTableWidgetItem();
        __qtablewidgetitem283->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(4, 9, __qtablewidgetitem283);
        QTableWidgetItem *__qtablewidgetitem284 = new QTableWidgetItem();
        __qtablewidgetitem284->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(4, 10, __qtablewidgetitem284);
        QTableWidgetItem *__qtablewidgetitem285 = new QTableWidgetItem();
        __qtablewidgetitem285->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(5, 0, __qtablewidgetitem285);
        QTableWidgetItem *__qtablewidgetitem286 = new QTableWidgetItem();
        __qtablewidgetitem286->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(5, 1, __qtablewidgetitem286);
        QTableWidgetItem *__qtablewidgetitem287 = new QTableWidgetItem();
        __qtablewidgetitem287->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(5, 2, __qtablewidgetitem287);
        QTableWidgetItem *__qtablewidgetitem288 = new QTableWidgetItem();
        __qtablewidgetitem288->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(5, 3, __qtablewidgetitem288);
        QTableWidgetItem *__qtablewidgetitem289 = new QTableWidgetItem();
        __qtablewidgetitem289->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(5, 4, __qtablewidgetitem289);
        QTableWidgetItem *__qtablewidgetitem290 = new QTableWidgetItem();
        __qtablewidgetitem290->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(5, 5, __qtablewidgetitem290);
        QTableWidgetItem *__qtablewidgetitem291 = new QTableWidgetItem();
        __qtablewidgetitem291->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(5, 6, __qtablewidgetitem291);
        QTableWidgetItem *__qtablewidgetitem292 = new QTableWidgetItem();
        __qtablewidgetitem292->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(5, 7, __qtablewidgetitem292);
        QTableWidgetItem *__qtablewidgetitem293 = new QTableWidgetItem();
        __qtablewidgetitem293->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(5, 8, __qtablewidgetitem293);
        QTableWidgetItem *__qtablewidgetitem294 = new QTableWidgetItem();
        __qtablewidgetitem294->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(5, 9, __qtablewidgetitem294);
        QTableWidgetItem *__qtablewidgetitem295 = new QTableWidgetItem();
        __qtablewidgetitem295->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(5, 10, __qtablewidgetitem295);
        QTableWidgetItem *__qtablewidgetitem296 = new QTableWidgetItem();
        __qtablewidgetitem296->setBackground(brush1);
        __qtablewidgetitem296->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(6, 0, __qtablewidgetitem296);
        QTableWidgetItem *__qtablewidgetitem297 = new QTableWidgetItem();
        __qtablewidgetitem297->setBackground(brush1);
        __qtablewidgetitem297->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(6, 1, __qtablewidgetitem297);
        QTableWidgetItem *__qtablewidgetitem298 = new QTableWidgetItem();
        __qtablewidgetitem298->setBackground(brush1);
        __qtablewidgetitem298->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(6, 2, __qtablewidgetitem298);
        QTableWidgetItem *__qtablewidgetitem299 = new QTableWidgetItem();
        __qtablewidgetitem299->setBackground(brush1);
        __qtablewidgetitem299->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(6, 3, __qtablewidgetitem299);
        QTableWidgetItem *__qtablewidgetitem300 = new QTableWidgetItem();
        __qtablewidgetitem300->setBackground(brush1);
        __qtablewidgetitem300->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(6, 4, __qtablewidgetitem300);
        QTableWidgetItem *__qtablewidgetitem301 = new QTableWidgetItem();
        __qtablewidgetitem301->setBackground(brush1);
        __qtablewidgetitem301->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(6, 5, __qtablewidgetitem301);
        QTableWidgetItem *__qtablewidgetitem302 = new QTableWidgetItem();
        __qtablewidgetitem302->setBackground(brush1);
        __qtablewidgetitem302->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(6, 6, __qtablewidgetitem302);
        QTableWidgetItem *__qtablewidgetitem303 = new QTableWidgetItem();
        __qtablewidgetitem303->setBackground(brush1);
        __qtablewidgetitem303->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(6, 7, __qtablewidgetitem303);
        QTableWidgetItem *__qtablewidgetitem304 = new QTableWidgetItem();
        __qtablewidgetitem304->setBackground(brush1);
        __qtablewidgetitem304->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(6, 8, __qtablewidgetitem304);
        QTableWidgetItem *__qtablewidgetitem305 = new QTableWidgetItem();
        __qtablewidgetitem305->setBackground(brush1);
        __qtablewidgetitem305->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(6, 9, __qtablewidgetitem305);
        QTableWidgetItem *__qtablewidgetitem306 = new QTableWidgetItem();
        __qtablewidgetitem306->setBackground(brush1);
        __qtablewidgetitem306->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(6, 10, __qtablewidgetitem306);
        QTableWidgetItem *__qtablewidgetitem307 = new QTableWidgetItem();
        __qtablewidgetitem307->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(7, 0, __qtablewidgetitem307);
        QTableWidgetItem *__qtablewidgetitem308 = new QTableWidgetItem();
        __qtablewidgetitem308->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(7, 1, __qtablewidgetitem308);
        QTableWidgetItem *__qtablewidgetitem309 = new QTableWidgetItem();
        __qtablewidgetitem309->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(7, 2, __qtablewidgetitem309);
        QTableWidgetItem *__qtablewidgetitem310 = new QTableWidgetItem();
        __qtablewidgetitem310->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(7, 3, __qtablewidgetitem310);
        QTableWidgetItem *__qtablewidgetitem311 = new QTableWidgetItem();
        __qtablewidgetitem311->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(7, 4, __qtablewidgetitem311);
        QTableWidgetItem *__qtablewidgetitem312 = new QTableWidgetItem();
        __qtablewidgetitem312->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(7, 5, __qtablewidgetitem312);
        QTableWidgetItem *__qtablewidgetitem313 = new QTableWidgetItem();
        __qtablewidgetitem313->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(7, 6, __qtablewidgetitem313);
        QTableWidgetItem *__qtablewidgetitem314 = new QTableWidgetItem();
        __qtablewidgetitem314->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(7, 7, __qtablewidgetitem314);
        QTableWidgetItem *__qtablewidgetitem315 = new QTableWidgetItem();
        __qtablewidgetitem315->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(7, 8, __qtablewidgetitem315);
        QTableWidgetItem *__qtablewidgetitem316 = new QTableWidgetItem();
        __qtablewidgetitem316->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(7, 9, __qtablewidgetitem316);
        QTableWidgetItem *__qtablewidgetitem317 = new QTableWidgetItem();
        __qtablewidgetitem317->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(7, 10, __qtablewidgetitem317);
        QTableWidgetItem *__qtablewidgetitem318 = new QTableWidgetItem();
        __qtablewidgetitem318->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(8, 0, __qtablewidgetitem318);
        QTableWidgetItem *__qtablewidgetitem319 = new QTableWidgetItem();
        __qtablewidgetitem319->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(8, 1, __qtablewidgetitem319);
        QTableWidgetItem *__qtablewidgetitem320 = new QTableWidgetItem();
        __qtablewidgetitem320->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(8, 2, __qtablewidgetitem320);
        QTableWidgetItem *__qtablewidgetitem321 = new QTableWidgetItem();
        __qtablewidgetitem321->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(8, 3, __qtablewidgetitem321);
        QTableWidgetItem *__qtablewidgetitem322 = new QTableWidgetItem();
        __qtablewidgetitem322->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(8, 4, __qtablewidgetitem322);
        QTableWidgetItem *__qtablewidgetitem323 = new QTableWidgetItem();
        __qtablewidgetitem323->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(8, 5, __qtablewidgetitem323);
        QTableWidgetItem *__qtablewidgetitem324 = new QTableWidgetItem();
        __qtablewidgetitem324->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(8, 6, __qtablewidgetitem324);
        QTableWidgetItem *__qtablewidgetitem325 = new QTableWidgetItem();
        __qtablewidgetitem325->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(8, 7, __qtablewidgetitem325);
        QTableWidgetItem *__qtablewidgetitem326 = new QTableWidgetItem();
        __qtablewidgetitem326->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(8, 8, __qtablewidgetitem326);
        QTableWidgetItem *__qtablewidgetitem327 = new QTableWidgetItem();
        __qtablewidgetitem327->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(8, 9, __qtablewidgetitem327);
        QTableWidgetItem *__qtablewidgetitem328 = new QTableWidgetItem();
        __qtablewidgetitem328->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(8, 10, __qtablewidgetitem328);
        QTableWidgetItem *__qtablewidgetitem329 = new QTableWidgetItem();
        __qtablewidgetitem329->setBackground(brush1);
        __qtablewidgetitem329->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(9, 0, __qtablewidgetitem329);
        QTableWidgetItem *__qtablewidgetitem330 = new QTableWidgetItem();
        __qtablewidgetitem330->setBackground(brush1);
        __qtablewidgetitem330->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(9, 1, __qtablewidgetitem330);
        QTableWidgetItem *__qtablewidgetitem331 = new QTableWidgetItem();
        __qtablewidgetitem331->setBackground(brush1);
        __qtablewidgetitem331->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(9, 2, __qtablewidgetitem331);
        QTableWidgetItem *__qtablewidgetitem332 = new QTableWidgetItem();
        __qtablewidgetitem332->setBackground(brush1);
        __qtablewidgetitem332->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(9, 3, __qtablewidgetitem332);
        QTableWidgetItem *__qtablewidgetitem333 = new QTableWidgetItem();
        __qtablewidgetitem333->setBackground(brush1);
        __qtablewidgetitem333->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(9, 4, __qtablewidgetitem333);
        QTableWidgetItem *__qtablewidgetitem334 = new QTableWidgetItem();
        __qtablewidgetitem334->setBackground(brush1);
        __qtablewidgetitem334->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(9, 5, __qtablewidgetitem334);
        QTableWidgetItem *__qtablewidgetitem335 = new QTableWidgetItem();
        __qtablewidgetitem335->setBackground(brush1);
        __qtablewidgetitem335->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(9, 6, __qtablewidgetitem335);
        QTableWidgetItem *__qtablewidgetitem336 = new QTableWidgetItem();
        __qtablewidgetitem336->setBackground(brush1);
        __qtablewidgetitem336->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(9, 7, __qtablewidgetitem336);
        QTableWidgetItem *__qtablewidgetitem337 = new QTableWidgetItem();
        __qtablewidgetitem337->setBackground(brush1);
        __qtablewidgetitem337->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(9, 8, __qtablewidgetitem337);
        QTableWidgetItem *__qtablewidgetitem338 = new QTableWidgetItem();
        __qtablewidgetitem338->setBackground(brush1);
        __qtablewidgetitem338->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(9, 9, __qtablewidgetitem338);
        QTableWidgetItem *__qtablewidgetitem339 = new QTableWidgetItem();
        __qtablewidgetitem339->setBackground(brush1);
        __qtablewidgetitem339->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(9, 10, __qtablewidgetitem339);
        QTableWidgetItem *__qtablewidgetitem340 = new QTableWidgetItem();
        __qtablewidgetitem340->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(10, 0, __qtablewidgetitem340);
        QTableWidgetItem *__qtablewidgetitem341 = new QTableWidgetItem();
        __qtablewidgetitem341->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(10, 1, __qtablewidgetitem341);
        QTableWidgetItem *__qtablewidgetitem342 = new QTableWidgetItem();
        __qtablewidgetitem342->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(10, 2, __qtablewidgetitem342);
        QTableWidgetItem *__qtablewidgetitem343 = new QTableWidgetItem();
        __qtablewidgetitem343->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(10, 3, __qtablewidgetitem343);
        QTableWidgetItem *__qtablewidgetitem344 = new QTableWidgetItem();
        __qtablewidgetitem344->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(10, 4, __qtablewidgetitem344);
        QTableWidgetItem *__qtablewidgetitem345 = new QTableWidgetItem();
        __qtablewidgetitem345->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(10, 5, __qtablewidgetitem345);
        QTableWidgetItem *__qtablewidgetitem346 = new QTableWidgetItem();
        __qtablewidgetitem346->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(10, 6, __qtablewidgetitem346);
        QTableWidgetItem *__qtablewidgetitem347 = new QTableWidgetItem();
        __qtablewidgetitem347->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(10, 7, __qtablewidgetitem347);
        QTableWidgetItem *__qtablewidgetitem348 = new QTableWidgetItem();
        __qtablewidgetitem348->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(10, 8, __qtablewidgetitem348);
        QTableWidgetItem *__qtablewidgetitem349 = new QTableWidgetItem();
        __qtablewidgetitem349->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(10, 9, __qtablewidgetitem349);
        QTableWidgetItem *__qtablewidgetitem350 = new QTableWidgetItem();
        __qtablewidgetitem350->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(10, 10, __qtablewidgetitem350);
        QTableWidgetItem *__qtablewidgetitem351 = new QTableWidgetItem();
        __qtablewidgetitem351->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(11, 0, __qtablewidgetitem351);
        QTableWidgetItem *__qtablewidgetitem352 = new QTableWidgetItem();
        __qtablewidgetitem352->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(11, 1, __qtablewidgetitem352);
        QTableWidgetItem *__qtablewidgetitem353 = new QTableWidgetItem();
        __qtablewidgetitem353->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(11, 2, __qtablewidgetitem353);
        QTableWidgetItem *__qtablewidgetitem354 = new QTableWidgetItem();
        __qtablewidgetitem354->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(11, 3, __qtablewidgetitem354);
        QTableWidgetItem *__qtablewidgetitem355 = new QTableWidgetItem();
        __qtablewidgetitem355->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(11, 4, __qtablewidgetitem355);
        QTableWidgetItem *__qtablewidgetitem356 = new QTableWidgetItem();
        __qtablewidgetitem356->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(11, 5, __qtablewidgetitem356);
        QTableWidgetItem *__qtablewidgetitem357 = new QTableWidgetItem();
        __qtablewidgetitem357->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(11, 6, __qtablewidgetitem357);
        QTableWidgetItem *__qtablewidgetitem358 = new QTableWidgetItem();
        __qtablewidgetitem358->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(11, 7, __qtablewidgetitem358);
        QTableWidgetItem *__qtablewidgetitem359 = new QTableWidgetItem();
        __qtablewidgetitem359->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(11, 8, __qtablewidgetitem359);
        QTableWidgetItem *__qtablewidgetitem360 = new QTableWidgetItem();
        __qtablewidgetitem360->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(11, 9, __qtablewidgetitem360);
        QTableWidgetItem *__qtablewidgetitem361 = new QTableWidgetItem();
        __qtablewidgetitem361->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(11, 10, __qtablewidgetitem361);
        QTableWidgetItem *__qtablewidgetitem362 = new QTableWidgetItem();
        __qtablewidgetitem362->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(12, 0, __qtablewidgetitem362);
        QTableWidgetItem *__qtablewidgetitem363 = new QTableWidgetItem();
        __qtablewidgetitem363->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(12, 1, __qtablewidgetitem363);
        QTableWidgetItem *__qtablewidgetitem364 = new QTableWidgetItem();
        __qtablewidgetitem364->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(12, 2, __qtablewidgetitem364);
        QTableWidgetItem *__qtablewidgetitem365 = new QTableWidgetItem();
        __qtablewidgetitem365->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(12, 3, __qtablewidgetitem365);
        QTableWidgetItem *__qtablewidgetitem366 = new QTableWidgetItem();
        __qtablewidgetitem366->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(12, 4, __qtablewidgetitem366);
        QTableWidgetItem *__qtablewidgetitem367 = new QTableWidgetItem();
        __qtablewidgetitem367->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(12, 5, __qtablewidgetitem367);
        QTableWidgetItem *__qtablewidgetitem368 = new QTableWidgetItem();
        __qtablewidgetitem368->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(12, 6, __qtablewidgetitem368);
        QTableWidgetItem *__qtablewidgetitem369 = new QTableWidgetItem();
        __qtablewidgetitem369->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(12, 7, __qtablewidgetitem369);
        QTableWidgetItem *__qtablewidgetitem370 = new QTableWidgetItem();
        __qtablewidgetitem370->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(12, 8, __qtablewidgetitem370);
        QTableWidgetItem *__qtablewidgetitem371 = new QTableWidgetItem();
        __qtablewidgetitem371->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(12, 9, __qtablewidgetitem371);
        QTableWidgetItem *__qtablewidgetitem372 = new QTableWidgetItem();
        __qtablewidgetitem372->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(12, 10, __qtablewidgetitem372);
        QTableWidgetItem *__qtablewidgetitem373 = new QTableWidgetItem();
        __qtablewidgetitem373->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(14, 0, __qtablewidgetitem373);
        QTableWidgetItem *__qtablewidgetitem374 = new QTableWidgetItem();
        __qtablewidgetitem374->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(14, 1, __qtablewidgetitem374);
        QTableWidgetItem *__qtablewidgetitem375 = new QTableWidgetItem();
        __qtablewidgetitem375->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(14, 3, __qtablewidgetitem375);
        QTableWidgetItem *__qtablewidgetitem376 = new QTableWidgetItem();
        __qtablewidgetitem376->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(14, 4, __qtablewidgetitem376);
        QTableWidgetItem *__qtablewidgetitem377 = new QTableWidgetItem();
        __qtablewidgetitem377->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(14, 5, __qtablewidgetitem377);
        QTableWidgetItem *__qtablewidgetitem378 = new QTableWidgetItem();
        __qtablewidgetitem378->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(14, 6, __qtablewidgetitem378);
        QTableWidgetItem *__qtablewidgetitem379 = new QTableWidgetItem();
        __qtablewidgetitem379->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(14, 7, __qtablewidgetitem379);
        QTableWidgetItem *__qtablewidgetitem380 = new QTableWidgetItem();
        __qtablewidgetitem380->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(14, 8, __qtablewidgetitem380);
        QTableWidgetItem *__qtablewidgetitem381 = new QTableWidgetItem();
        __qtablewidgetitem381->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(14, 9, __qtablewidgetitem381);
        QTableWidgetItem *__qtablewidgetitem382 = new QTableWidgetItem();
        __qtablewidgetitem382->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(14, 10, __qtablewidgetitem382);
        QTableWidgetItem *__qtablewidgetitem383 = new QTableWidgetItem();
        __qtablewidgetitem383->setBackground(brush1);
        __qtablewidgetitem383->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(15, 0, __qtablewidgetitem383);
        QTableWidgetItem *__qtablewidgetitem384 = new QTableWidgetItem();
        __qtablewidgetitem384->setBackground(brush1);
        __qtablewidgetitem384->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(15, 1, __qtablewidgetitem384);
        QTableWidgetItem *__qtablewidgetitem385 = new QTableWidgetItem();
        __qtablewidgetitem385->setBackground(brush1);
        __qtablewidgetitem385->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(15, 2, __qtablewidgetitem385);
        QTableWidgetItem *__qtablewidgetitem386 = new QTableWidgetItem();
        __qtablewidgetitem386->setBackground(brush1);
        __qtablewidgetitem386->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(15, 3, __qtablewidgetitem386);
        QTableWidgetItem *__qtablewidgetitem387 = new QTableWidgetItem();
        __qtablewidgetitem387->setBackground(brush1);
        __qtablewidgetitem387->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(15, 4, __qtablewidgetitem387);
        QTableWidgetItem *__qtablewidgetitem388 = new QTableWidgetItem();
        __qtablewidgetitem388->setBackground(brush1);
        __qtablewidgetitem388->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(15, 5, __qtablewidgetitem388);
        QTableWidgetItem *__qtablewidgetitem389 = new QTableWidgetItem();
        __qtablewidgetitem389->setBackground(brush1);
        __qtablewidgetitem389->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(15, 6, __qtablewidgetitem389);
        QTableWidgetItem *__qtablewidgetitem390 = new QTableWidgetItem();
        __qtablewidgetitem390->setBackground(brush1);
        __qtablewidgetitem390->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(15, 7, __qtablewidgetitem390);
        QTableWidgetItem *__qtablewidgetitem391 = new QTableWidgetItem();
        __qtablewidgetitem391->setBackground(brush1);
        __qtablewidgetitem391->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(15, 8, __qtablewidgetitem391);
        QTableWidgetItem *__qtablewidgetitem392 = new QTableWidgetItem();
        __qtablewidgetitem392->setBackground(brush1);
        __qtablewidgetitem392->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(15, 9, __qtablewidgetitem392);
        QTableWidgetItem *__qtablewidgetitem393 = new QTableWidgetItem();
        __qtablewidgetitem393->setBackground(brush1);
        __qtablewidgetitem393->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableR->setItem(15, 10, __qtablewidgetitem393);
        tableR->setObjectName(QStringLiteral("tableR"));
        tableR->setGeometry(QRect(740, 50, 423, 511));
        tableR->setStyleSheet(QStringLiteral("background-color:rgb(239, 41, 41);"));
        tableR->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableR->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableR->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        tableR->setAutoScroll(false);
        tableR->horizontalHeader()->setMinimumSectionSize(20);
        tableR->verticalHeader()->setDefaultSectionSize(30);
        tableR->verticalHeader()->setMinimumSectionSize(10);
        gridLayoutWidget = new QWidget(Widget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(480, 50, 233, 301));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        leMessage = new QLineEdit(gridLayoutWidget);
        leMessage->setObjectName(QStringLiteral("leMessage"));

        gridLayout->addWidget(leMessage, 2, 0, 1, 1);

        btnSend = new QPushButton(gridLayoutWidget);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setStyleSheet(QLatin1String("background-color:rgb(52, 101, 164);\n"
"color:white;\n"
""));

        gridLayout->addWidget(btnSend, 2, 2, 1, 1);

        lChat = new QListWidget(gridLayoutWidget);
        lChat->setObjectName(QStringLiteral("lChat"));

        gridLayout->addWidget(lChat, 1, 0, 1, 3);

        btnSmiley = new QPushButton(gridLayoutWidget);
        btnSmiley->setObjectName(QStringLiteral("btnSmiley"));

        gridLayout->addWidget(btnSmiley, 2, 1, 1, 1);

        btnMuteChat = new QPushButton(gridLayoutWidget);
        btnMuteChat->setObjectName(QStringLiteral("btnMuteChat"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img-no_chat"), QSize(), QIcon::Normal, QIcon::Off);
        btnMuteChat->setIcon(icon);

        gridLayout->addWidget(btnMuteChat, 0, 2, 1, 1);

        btnMuteChatSound = new QPushButton(gridLayoutWidget);
        btnMuteChatSound->setObjectName(QStringLiteral("btnMuteChatSound"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img-msg"), QSize(), QIcon::Normal, QIcon::Off);
        btnMuteChatSound->setIcon(icon1);

        gridLayout->addWidget(btnMuteChatSound, 0, 1, 1, 1);

        btnThrow = new QPushButton(Widget);
        btnThrow->setObjectName(QStringLiteral("btnThrow"));
        btnThrow->setGeometry(QRect(520, 750, 151, 61));
        btnThrow->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgb(252,233,79);\n"
"	border-radius:10px;\n"
"	color:black;\n"
"	font-family:Arial;\n"
"	font-size:20px;\n"
"   	font-weight:bold;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(242,223,69);\n"
"}\n"
"QPushButton:active {\n"
"	position:relative;\n"
"	top:1px;\n"
"}\n"
""));
        btnMute = new QPushButton(Widget);
        btnMute->setObjectName(QStringLiteral("btnMute"));
        btnMute->setGeometry(QRect(570, 370, 51, 31));
        btnMute->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/img-speaker_f"), QSize(), QIcon::Normal, QIcon::Off);
        btnMute->setIcon(icon2);
        dice1 = new QPushButton(Widget);
        dice1->setObjectName(QStringLiteral("dice1"));
        dice1->setGeometry(QRect(270, 630, 101, 101));
        dice1->setStyleSheet(QStringLiteral("background-image: url(:/img/img-dice0);"));
        dice1->setFlat(true);
        dice2 = new QPushButton(Widget);
        dice2->setObjectName(QStringLiteral("dice2"));
        dice2->setGeometry(QRect(380, 630, 101, 101));
        dice2->setStyleSheet(QStringLiteral("background-image: url(:/img/img-dice0);"));
        dice2->setFlat(true);
        dice3 = new QPushButton(Widget);
        dice3->setObjectName(QStringLiteral("dice3"));
        dice3->setGeometry(QRect(490, 630, 101, 101));
        dice3->setStyleSheet(QStringLiteral("background-image: url(:/img/img-dice0);"));
        dice3->setFlat(true);
        dice4 = new QPushButton(Widget);
        dice4->setObjectName(QStringLiteral("dice4"));
        dice4->setGeometry(QRect(600, 630, 101, 101));
        dice4->setStyleSheet(QStringLiteral("background-image: url(:/img/img-dice0);"));
        dice4->setFlat(true);
        dice5 = new QPushButton(Widget);
        dice5->setObjectName(QStringLiteral("dice5"));
        dice5->setGeometry(QRect(710, 630, 101, 101));
        dice5->setStyleSheet(QStringLiteral("background-image: url(:/img/img-dice0);"));
        dice5->setFlat(true);
        dice6 = new QPushButton(Widget);
        dice6->setObjectName(QStringLiteral("dice6"));
        dice6->setGeometry(QRect(820, 630, 101, 101));
        dice6->setStyleSheet(QStringLiteral("background-image: url(:/img/img-dice0);"));
        dice6->setFlat(true);
        scrollArea = new QScrollArea(Widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(590, 350, 131, 101));
        scrollArea->setMouseTracking(false);
        scrollArea->setFrameShape(QFrame::StyledPanel);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 129, 99));
        gridLayoutWidget_2 = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 11, 111, 81));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnSmiley4 = new QPushButton(gridLayoutWidget_2);
        btnSmiley4->setObjectName(QStringLiteral("btnSmiley4"));
        btnSmiley4->setFlat(true);

        gridLayout_2->addWidget(btnSmiley4, 1, 0, 1, 1);

        btnSmiley8 = new QPushButton(gridLayoutWidget_2);
        btnSmiley8->setObjectName(QStringLiteral("btnSmiley8"));
        btnSmiley8->setFlat(true);

        gridLayout_2->addWidget(btnSmiley8, 2, 1, 1, 1);

        btnSmiley1 = new QPushButton(gridLayoutWidget_2);
        btnSmiley1->setObjectName(QStringLiteral("btnSmiley1"));
        btnSmiley1->setFlat(true);

        gridLayout_2->addWidget(btnSmiley1, 0, 0, 1, 1);

        btnSmiley9 = new QPushButton(gridLayoutWidget_2);
        btnSmiley9->setObjectName(QStringLiteral("btnSmiley9"));
        btnSmiley9->setFlat(true);

        gridLayout_2->addWidget(btnSmiley9, 2, 2, 1, 1);

        btnSmiley2 = new QPushButton(gridLayoutWidget_2);
        btnSmiley2->setObjectName(QStringLiteral("btnSmiley2"));
        btnSmiley2->setFlat(true);

        gridLayout_2->addWidget(btnSmiley2, 0, 1, 1, 1);

        btnSmiley5 = new QPushButton(gridLayoutWidget_2);
        btnSmiley5->setObjectName(QStringLiteral("btnSmiley5"));
        btnSmiley5->setFlat(true);

        gridLayout_2->addWidget(btnSmiley5, 1, 1, 1, 1);

        btnSmiley7 = new QPushButton(gridLayoutWidget_2);
        btnSmiley7->setObjectName(QStringLiteral("btnSmiley7"));
        btnSmiley7->setFlat(true);

        gridLayout_2->addWidget(btnSmiley7, 2, 0, 1, 1);

        btnSmiley3 = new QPushButton(gridLayoutWidget_2);
        btnSmiley3->setObjectName(QStringLiteral("btnSmiley3"));
        btnSmiley3->setFlat(true);

        gridLayout_2->addWidget(btnSmiley3, 0, 2, 1, 1);

        btnSmiley6 = new QPushButton(gridLayoutWidget_2);
        btnSmiley6->setObjectName(QStringLiteral("btnSmiley6"));
        btnSmiley6->setFlat(true);

        gridLayout_2->addWidget(btnSmiley6, 1, 2, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        btnSurrender = new QPushButton(Widget);
        btnSurrender->setObjectName(QStringLiteral("btnSurrender"));
        btnSurrender->setGeometry(QRect(1070, 10, 91, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("Ubuntu"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        font2.setKerning(true);
        btnSurrender->setFont(font2);
        btnSurrender->setStyleSheet(QStringLiteral("color: red;"));
        btnSurrender->setFlat(true);
        btnFinishMove = new QPushButton(Widget);
        btnFinishMove->setObjectName(QStringLiteral("btnFinishMove"));
        btnFinishMove->setGeometry(QRect(30, 750, 141, 61));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setBold(true);
        font3.setWeight(75);
        font3.setKerning(true);
        btnFinishMove->setFont(font3);
        btnFinishMove->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color:rgb(114, 159, 207);\n"
"	border-radius:10px;\n"
"	color:black;\n"
"	font-family:Arial;\n"
"	font-size:20px;\n"
"        font-weight:bold;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color:rgb(120, 165, 225);\n"
"}\n"
"QPushButton:active {\n"
"	position:relative;\n"
"	top:1px;\n"
"}"));
        labelFinishMove = new QLabel(Widget);
        labelFinishMove->setObjectName(QStringLiteral("labelFinishMove"));
        labelFinishMove->setGeometry(QRect(30, 720, 141, 21));
        QFont font4;
        font4.setFamily(QStringLiteral("Ubuntu Condensed"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        font4.setKerning(true);
        labelFinishMove->setFont(font4);
        labelFinishMove->setStyleSheet(QLatin1String("color: red;\n"
""));
        labelFinishMove->setAlignment(Qt::AlignCenter);
        labelYourTurn = new QLabel(Widget);
        labelYourTurn->setObjectName(QStringLiteral("labelYourTurn"));
        labelYourTurn->setGeometry(QRect(370, 370, 461, 191));
        QFont font5;
        font5.setFamily(QStringLiteral("Ubuntu Condensed"));
        font5.setPointSize(72);
        font5.setBold(true);
        font5.setWeight(75);
        font5.setKerning(true);
        labelYourTurn->setFont(font5);
        labelYourTurn->setStyleSheet(QStringLiteral("color:rgb(239, 41, 41);"));
        labelYourTurn->setAlignment(Qt::AlignCenter);
        labelIllegalMove = new QLabel(Widget);
        labelIllegalMove->setObjectName(QStringLiteral("labelIllegalMove"));
        labelIllegalMove->setGeometry(QRect(460, 520, 281, 41));
        QFont font6;
        font6.setFamily(QStringLiteral("Ubuntu Condensed"));
        font6.setPointSize(20);
        font6.setBold(true);
        font6.setWeight(75);
        font6.setKerning(true);
        labelIllegalMove->setFont(font6);
        labelIllegalMove->setStyleSheet(QStringLiteral("color:rgb(239, 41, 41);"));
        labelIllegalMove->setAlignment(Qt::AlignCenter);
        tableL->raise();
        tableR->raise();
        gridLayoutWidget->raise();
        btnThrow->raise();
        btnMute->raise();
        dice1->raise();
        dice2->raise();
        dice3->raise();
        dice4->raise();
        dice5->raise();
        dice6->raise();
        btnSurrender->raise();
        btnFinishMove->raise();
        scrollArea->raise();
        labelFinishMove->raise();
        labelYourTurn->raise();
        labelIllegalMove->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Yamb", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableL->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "\342\226\274", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem->setToolTip(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Popunjava se odozgo na dole, redom, bez mogu\304\207nosti preskakanja polja. </p></body></html>", "sadasdadd"));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem1 = tableL->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "\342\226\262\342\226\274", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem1->setToolTip(QApplication::translate("Widget", "Popunjava se bilo kojim redosledom, sa mogu\304\207no\305\241\304\207u preskakanja polja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem2 = tableL->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget", "\342\226\262", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem2->setToolTip(QApplication::translate("Widget", " Popunjava se odozdo na gore, redom, bez mogu\304\207nosti preskakanja polja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem3 = tableL->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget", "N", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableL->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget", "R", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem4->setToolTip(QApplication::translate("Widget", "Popunjava se bilo kojim redosledom, ako je zbir koji \305\276elite da upi\305\241ete dobijen bacanjem svih 6 kockica(nema prethodno selektovanih), u bilo kojem od 3 dozvoljena bacanja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem5 = tableL->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget", "D", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem5->setToolTip(QApplication::translate("Widget", " 	Popunjava se obavezno onim redosledom, koji diktira protivnik popunjavaju\304\207i odredjeno polje u koloni najave (N). ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem6 = tableL->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget", "\342\206\225", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem6->setToolTip(QApplication::translate("Widget", "Popunjava se od polja MAX na gore, redom, i od polja MIN na dole, redom, bez mogu\304\207nosti preskakanja polja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem7 = tableL->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget", "\342\206\250", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem7->setToolTip(QApplication::translate("Widget", "Popunjava se od vrha na dole, zakljucno sa poljem MAX , redom, i odozdo na gore,zakljucno sa kolonom MIN, redom,bez mogu\304\207nosti preskakanja polja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem8 = tableL->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget", "O", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem8->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>Kolona koja se popunjava poslednja po redu.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem9 = tableL->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("Widget", "M", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem9->setToolTip(QApplication::translate("Widget", "Popunjava se bilo kojim redosledom, sa mogu\304\207no\305\241\304\207u preskakanja polja, ako je ostvaren maksimalan mogu\304\207i rezultat predvi\304\221en za to polje, u toku 3 dozvoljena bacanja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem10 = tableL->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("Widget", "YAMB", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableL->verticalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("Widget", "1", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem11->setToolTip(QApplication::translate("Widget", "Maksimalni broj jedinica u sva 3 bacanja.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem12 = tableL->verticalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("Widget", "2", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem12->setToolTip(QApplication::translate("Widget", " Maksimalni broj dvojki u sva 3 bacanja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem13 = tableL->verticalHeaderItem(2);
        ___qtablewidgetitem13->setText(QApplication::translate("Widget", "3", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem13->setToolTip(QApplication::translate("Widget", " Maksimalni broj trojki u sva 3 bacanja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem14 = tableL->verticalHeaderItem(3);
        ___qtablewidgetitem14->setText(QApplication::translate("Widget", "4", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem14->setToolTip(QApplication::translate("Widget", "Maksimalni broj \304\215etvorki u sva 3 bacanja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem15 = tableL->verticalHeaderItem(4);
        ___qtablewidgetitem15->setText(QApplication::translate("Widget", "5", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem15->setToolTip(QApplication::translate("Widget", "Maksimalni broj petica u sva 3 bacanja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem16 = tableL->verticalHeaderItem(5);
        ___qtablewidgetitem16->setText(QApplication::translate("Widget", "6", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem16->setToolTip(QApplication::translate("Widget", "Maksimalni broj \305\241estica u sva 3 bacanja.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem17 = tableL->verticalHeaderItem(6);
        ___qtablewidgetitem17->setText(QApplication::translate("Widget", "\316\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem17->setToolTip(QApplication::translate("Widget", "Zbir.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem18 = tableL->verticalHeaderItem(7);
        ___qtablewidgetitem18->setText(QApplication::translate("Widget", "MAX", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem18->setToolTip(QApplication::translate("Widget", " Maksimalni zbir 5 selektovanih kockica u sva 3 bacanja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem19 = tableL->verticalHeaderItem(8);
        ___qtablewidgetitem19->setText(QApplication::translate("Widget", "MIN", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem19->setToolTip(QApplication::translate("Widget", " Minimalni zbir 5 selektovanih kockica u sva 3 bacanja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem20 = tableL->verticalHeaderItem(9);
        ___qtablewidgetitem20->setText(QApplication::translate("Widget", "\316\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem20->setToolTip(QApplication::translate("Widget", "Zbir.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem21 = tableL->verticalHeaderItem(10);
        ___qtablewidgetitem21->setText(QApplication::translate("Widget", "KENTA", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem21->setToolTip(QApplication::translate("Widget", "Kombinacija kockica ( '1' '2' '3' '4' '5') or ( '2' '3' '4' '5' '6'). Kao rezultat upisuje se 66, ako se neka od kombinacija dobije bacanjem svih \305\241est kockica, bez prethodno selektovanih, 56 ako se neka od kombinacija dobije kroz dva bacanja kockica, 46 ako se neka od kombinacija dobije kroz tri dozvoljena bacanja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem22 = tableL->verticalHeaderItem(11);
        ___qtablewidgetitem22->setText(QApplication::translate("Widget", "TRILING", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem22->setToolTip(QApplication::translate("Widget", " Kombinacija tri iste kockice. Kao rezultat upisuje se zbir tri iste selektovane kockice+20, nezavisno od broja bacanja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem23 = tableL->verticalHeaderItem(12);
        ___qtablewidgetitem23->setText(QApplication::translate("Widget", "FUL", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem23->setToolTip(QApplication::translate("Widget", " Kombinacija tri iste + dve iste kockice. Kao rezultat upisuje se zbir selektovanih kockica+30, nezavisno od broja bacanja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem24 = tableL->verticalHeaderItem(13);
        ___qtablewidgetitem24->setText(QApplication::translate("Widget", "POKER", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem24->setToolTip(QApplication::translate("Widget", " Kombinacija \304\215etiri iste kockice. Kao rezultat se upisuje zbir selektovanih kockica+40, nezavisno od broja bacanja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem25 = tableL->verticalHeaderItem(14);
        ___qtablewidgetitem25->setText(QApplication::translate("Widget", "YAMB", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem25->setToolTip(QApplication::translate("Widget", " Kombinacija 5 istih kockica. Kao rezultat se upisuje zbir selektovanih kockica+50, nezavisno od broja bacanja. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem26 = tableL->verticalHeaderItem(15);
        ___qtablewidgetitem26->setText(QApplication::translate("Widget", "\316\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem26->setToolTip(QApplication::translate("Widget", "Zbir.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP

        const bool __sortingEnabled = tableL->isSortingEnabled();
        tableL->setSortingEnabled(false);
        tableL->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem27 = tableR->horizontalHeaderItem(0);
        ___qtablewidgetitem27->setText(QApplication::translate("Widget", "\342\226\274", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableR->horizontalHeaderItem(1);
        ___qtablewidgetitem28->setText(QApplication::translate("Widget", "\342\226\262\342\226\274", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tableR->horizontalHeaderItem(2);
        ___qtablewidgetitem29->setText(QApplication::translate("Widget", "\342\226\262", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = tableR->horizontalHeaderItem(3);
        ___qtablewidgetitem30->setText(QApplication::translate("Widget", "N", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem31 = tableR->horizontalHeaderItem(4);
        ___qtablewidgetitem31->setText(QApplication::translate("Widget", "R", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem32 = tableR->horizontalHeaderItem(5);
        ___qtablewidgetitem32->setText(QApplication::translate("Widget", "D", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem33 = tableR->horizontalHeaderItem(6);
        ___qtablewidgetitem33->setText(QApplication::translate("Widget", "\342\206\225", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem34 = tableR->horizontalHeaderItem(7);
        ___qtablewidgetitem34->setText(QApplication::translate("Widget", "\342\206\250", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem35 = tableR->horizontalHeaderItem(8);
        ___qtablewidgetitem35->setText(QApplication::translate("Widget", "O", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem36 = tableR->horizontalHeaderItem(9);
        ___qtablewidgetitem36->setText(QApplication::translate("Widget", "M", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem37 = tableR->horizontalHeaderItem(10);
        ___qtablewidgetitem37->setText(QApplication::translate("Widget", "YAMB", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem38 = tableR->verticalHeaderItem(0);
        ___qtablewidgetitem38->setText(QApplication::translate("Widget", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem39 = tableR->verticalHeaderItem(1);
        ___qtablewidgetitem39->setText(QApplication::translate("Widget", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem40 = tableR->verticalHeaderItem(2);
        ___qtablewidgetitem40->setText(QApplication::translate("Widget", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem41 = tableR->verticalHeaderItem(3);
        ___qtablewidgetitem41->setText(QApplication::translate("Widget", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem42 = tableR->verticalHeaderItem(4);
        ___qtablewidgetitem42->setText(QApplication::translate("Widget", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem43 = tableR->verticalHeaderItem(5);
        ___qtablewidgetitem43->setText(QApplication::translate("Widget", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem44 = tableR->verticalHeaderItem(6);
        ___qtablewidgetitem44->setText(QApplication::translate("Widget", "\316\243", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem45 = tableR->verticalHeaderItem(7);
        ___qtablewidgetitem45->setText(QApplication::translate("Widget", "MAX", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem46 = tableR->verticalHeaderItem(8);
        ___qtablewidgetitem46->setText(QApplication::translate("Widget", "MIN", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem47 = tableR->verticalHeaderItem(9);
        ___qtablewidgetitem47->setText(QApplication::translate("Widget", "\316\243", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem48 = tableR->verticalHeaderItem(10);
        ___qtablewidgetitem48->setText(QApplication::translate("Widget", "KENTA", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem49 = tableR->verticalHeaderItem(11);
        ___qtablewidgetitem49->setText(QApplication::translate("Widget", "TRILING", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem50 = tableR->verticalHeaderItem(12);
        ___qtablewidgetitem50->setText(QApplication::translate("Widget", "FUL", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem51 = tableR->verticalHeaderItem(13);
        ___qtablewidgetitem51->setText(QApplication::translate("Widget", "POKER", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem52 = tableR->verticalHeaderItem(14);
        ___qtablewidgetitem52->setText(QApplication::translate("Widget", "YAMB", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem53 = tableR->verticalHeaderItem(15);
        ___qtablewidgetitem53->setText(QApplication::translate("Widget", "\316\243", Q_NULLPTR));

        const bool __sortingEnabled1 = tableR->isSortingEnabled();
        tableR->setSortingEnabled(false);
        tableR->setSortingEnabled(__sortingEnabled1);

        btnSend->setText(QApplication::translate("Widget", "Send", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        btnSend->setShortcut(QApplication::translate("Widget", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        btnSmiley->setText(QApplication::translate("Widget", "\342\230\272", Q_NULLPTR));
        btnMuteChat->setText(QString());
        btnMuteChatSound->setText(QString());
        btnThrow->setText(QApplication::translate("Widget", "Throw Dice!", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        btnThrow->setShortcut(QApplication::translate("Widget", "Space", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        btnMute->setText(QString());
#ifndef QT_NO_SHORTCUT
        btnMute->setShortcut(QApplication::translate("Widget", "M", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        dice1->setText(QString());
#ifndef QT_NO_SHORTCUT
        dice1->setShortcut(QApplication::translate("Widget", "1", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        dice2->setText(QString());
#ifndef QT_NO_SHORTCUT
        dice2->setShortcut(QApplication::translate("Widget", "2", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        dice3->setText(QString());
#ifndef QT_NO_SHORTCUT
        dice3->setShortcut(QApplication::translate("Widget", "3", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        dice4->setText(QString());
#ifndef QT_NO_SHORTCUT
        dice4->setShortcut(QApplication::translate("Widget", "4", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        dice5->setText(QString());
#ifndef QT_NO_SHORTCUT
        dice5->setShortcut(QApplication::translate("Widget", "5", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        dice6->setText(QString());
#ifndef QT_NO_SHORTCUT
        dice6->setShortcut(QApplication::translate("Widget", "6", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        btnSmiley4->setText(QApplication::translate("Widget", "\360\237\230\201", Q_NULLPTR));
        btnSmiley8->setText(QApplication::translate("Widget", "\360\237\230\213", Q_NULLPTR));
        btnSmiley1->setText(QApplication::translate("Widget", "\342\230\272", Q_NULLPTR));
        btnSmiley9->setText(QApplication::translate("Widget", "\360\237\230\210", Q_NULLPTR));
        btnSmiley2->setText(QApplication::translate("Widget", "\342\230\271", Q_NULLPTR));
        btnSmiley5->setText(QApplication::translate("Widget", "\360\237\230\211", Q_NULLPTR));
        btnSmiley7->setText(QApplication::translate("Widget", "\360\237\230\202", Q_NULLPTR));
        btnSmiley3->setText(QApplication::translate("Widget", "\360\237\230\240", Q_NULLPTR));
        btnSmiley6->setText(QApplication::translate("Widget", "\360\237\230\230", Q_NULLPTR));
        btnSurrender->setText(QApplication::translate("Widget", "Surrender", Q_NULLPTR));
        btnFinishMove->setText(QApplication::translate("Widget", "Finish move!", Q_NULLPTR));
        labelFinishMove->setText(QApplication::translate("Widget", "Select cell first!", Q_NULLPTR));
        labelYourTurn->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:72pt;\">YOUR TURN!</span></p></body></html>", Q_NULLPTR));
        labelIllegalMove->setText(QApplication::translate("Widget", "Illegal move!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
