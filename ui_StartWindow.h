/********************************************************************************
** Form generated from reading UI file 'StartWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnCreate;
    QPushButton *btnMulti;
    QPushButton *btnJoinG;
    QGridLayout *gridLayout_2;
    QPushButton *btnJoin;
    QLineEdit *leID;
    QPushButton *btnExit;
    QLabel *label_2;

    void setupUi(QDialog *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QStringLiteral("StartWindow"));
        StartWindow->resize(321, 440);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StartWindow->sizePolicy().hasHeightForWidth());
        StartWindow->setSizePolicy(sizePolicy);
        StartWindow->setStyleSheet(QLatin1String("background-color:rgb(52, 101, 164)\n"
""));
        verticalLayoutWidget = new QWidget(StartWindow);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(90, 130, 144, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnCreate = new QPushButton(verticalLayoutWidget);
        btnCreate->setObjectName(QStringLiteral("btnCreate"));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Condensed"));
        font.setPointSize(17);
        font.setBold(true);
        font.setWeight(75);
        btnCreate->setFont(font);
        btnCreate->setCheckable(true);
        btnCreate->setAutoExclusive(true);
        btnCreate->setFlat(true);

        verticalLayout->addWidget(btnCreate, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        btnMulti = new QPushButton(verticalLayoutWidget);
        btnMulti->setObjectName(QStringLiteral("btnMulti"));
        btnMulti->setFlat(true);

        verticalLayout->addWidget(btnMulti, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        btnJoinG = new QPushButton(verticalLayoutWidget);
        btnJoinG->setObjectName(QStringLiteral("btnJoinG"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnJoinG->sizePolicy().hasHeightForWidth());
        btnJoinG->setSizePolicy(sizePolicy1);
        btnJoinG->setMaximumSize(QSize(219, 16777215));
        btnJoinG->setFont(font);
        btnJoinG->setLayoutDirection(Qt::LeftToRight);
        btnJoinG->setCheckable(true);
        btnJoinG->setAutoExclusive(true);
        btnJoinG->setFlat(true);

        verticalLayout->addWidget(btnJoinG, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(3);
        gridLayout_2->setVerticalSpacing(5);
        btnJoin = new QPushButton(verticalLayoutWidget);
        btnJoin->setObjectName(QStringLiteral("btnJoin"));
        btnJoin->setEnabled(true);
        btnJoin->setMinimumSize(QSize(60, 30));
        btnJoin->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color:rgb(41, 219, 41);\n"
"	border-radius:10px;\n"
"	color:black;\n"
"	font-family:Arial;\n"
"	font-size:18px;\n"
"   	font-weight:bold;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(41, 255, 41);\n"
"}\n"
"QPushButton:active {\n"
"	position:relative;\n"
"	top:1px;\n"
"}"));

        gridLayout_2->addWidget(btnJoin, 1, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        leID = new QLineEdit(verticalLayoutWidget);
        leID->setObjectName(QStringLiteral("leID"));
        sizePolicy1.setHeightForWidth(leID->sizePolicy().hasHeightForWidth());
        leID->setSizePolicy(sizePolicy1);
        leID->setMinimumSize(QSize(60, 0));
        leID->setAlignment(Qt::AlignCenter);
        leID->setClearButtonEnabled(false);

        gridLayout_2->addWidget(leID, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout->addLayout(gridLayout_2);

        btnExit = new QPushButton(StartWindow);
        btnExit->setObjectName(QStringLiteral("btnExit"));
        btnExit->setGeometry(QRect(90, 390, 151, 35));
        btnExit->setFont(font);
        btnExit->setCheckable(true);
        btnExit->setAutoExclusive(true);
        btnExit->setFlat(true);
        label_2 = new QLabel(StartWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 20, 141, 50));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu Condensed"));
        font1.setPointSize(40);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral(""));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QDialog *StartWindow)
    {
        StartWindow->setWindowTitle(QApplication::translate("StartWindow", "Yamb", Q_NULLPTR));
        btnCreate->setText(QApplication::translate("StartWindow", "Create game", Q_NULLPTR));
        btnMulti->setText(QApplication::translate("StartWindow", "Multiplayer", Q_NULLPTR));
        btnJoinG->setText(QApplication::translate("StartWindow", "Join game", Q_NULLPTR));
        btnJoin->setText(QApplication::translate("StartWindow", "Join", Q_NULLPTR));
        leID->setText(QString());
        btnExit->setText(QApplication::translate("StartWindow", "Exit game", Q_NULLPTR));
        label_2->setText(QApplication::translate("StartWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">YAMB</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
