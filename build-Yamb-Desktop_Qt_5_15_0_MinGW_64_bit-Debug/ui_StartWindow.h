/********************************************************************************
** Form generated from reading UI file 'StartWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnCreate;
    QPushButton *btnSingle;
    QPushButton *btnLocal;
    QPushButton *btnMulti;
    QPushButton *btnJoinG;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QPushButton *btnJoin;
    QSpacerItem *horizontalSpacer;
    QLineEdit *leID;

    void setupUi(QDialog *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QString::fromUtf8("StartWindow"));
        StartWindow->resize(332, 331);
        StartWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(52, 101, 164)"));
        verticalLayoutWidget = new QWidget(StartWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 40, 214, 245));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnCreate = new QPushButton(verticalLayoutWidget);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(17);
        font.setBold(true);
        font.setWeight(75);
        btnCreate->setFont(font);
        btnCreate->setFlat(true);

        verticalLayout->addWidget(btnCreate, 0, Qt::AlignHCenter);

        btnSingle = new QPushButton(verticalLayoutWidget);
        btnSingle->setObjectName(QString::fromUtf8("btnSingle"));
        btnSingle->setFlat(true);

        verticalLayout->addWidget(btnSingle, 0, Qt::AlignHCenter);

        btnLocal = new QPushButton(verticalLayoutWidget);
        btnLocal->setObjectName(QString::fromUtf8("btnLocal"));
        btnLocal->setFlat(true);

        verticalLayout->addWidget(btnLocal, 0, Qt::AlignHCenter);

        btnMulti = new QPushButton(verticalLayoutWidget);
        btnMulti->setObjectName(QString::fromUtf8("btnMulti"));
        btnMulti->setFlat(true);

        verticalLayout->addWidget(btnMulti, 0, Qt::AlignHCenter);

        btnJoinG = new QPushButton(verticalLayoutWidget);
        btnJoinG->setObjectName(QString::fromUtf8("btnJoinG"));
        btnJoinG->setFont(font);
        btnJoinG->setFlat(true);

        verticalLayout->addWidget(btnJoinG, 0, Qt::AlignHCenter);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        btnJoin = new QPushButton(verticalLayoutWidget);
        btnJoin->setObjectName(QString::fromUtf8("btnJoin"));

        gridLayout_2->addWidget(btnJoin, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 2, 1, 1);

        leID = new QLineEdit(verticalLayoutWidget);
        leID->setObjectName(QString::fromUtf8("leID"));

        gridLayout_2->addWidget(leID, 1, 1, 1, 2);


        verticalLayout->addLayout(gridLayout_2);


        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QDialog *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "Yamb", nullptr));
        btnCreate->setText(QCoreApplication::translate("StartWindow", "Create game", nullptr));
        btnSingle->setText(QCoreApplication::translate("StartWindow", "Singleplayer", nullptr));
        btnLocal->setText(QCoreApplication::translate("StartWindow", "Local Multiplayer", nullptr));
        btnMulti->setText(QCoreApplication::translate("StartWindow", "Multiplayer", nullptr));
        btnJoinG->setText(QCoreApplication::translate("StartWindow", "Join game", nullptr));
        label->setText(QCoreApplication::translate("StartWindow", "Game ID:", nullptr));
        btnJoin->setText(QCoreApplication::translate("StartWindow", "Join", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
