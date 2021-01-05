/********************************************************************************
** Form generated from reading UI file 'WaitingWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITINGWINDOW_H
#define UI_WAITINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaitingWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *labelGameId;
    QPushButton *pushButton;
    QLabel *labelGif;
    QLabel *label;

    void setupUi(QDialog *WaitingWindow)
    {
        if (WaitingWindow->objectName().isEmpty())
            WaitingWindow->setObjectName(QStringLiteral("WaitingWindow"));
        WaitingWindow->resize(284, 375);
        WaitingWindow->setStyleSheet(QLatin1String("background-color:rgb(52, 101, 164)\n"
""));
        verticalLayoutWidget = new QWidget(WaitingWindow);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 250, 211, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setBold(false);
        font.setWeight(50);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3, 0, Qt::AlignHCenter);

        labelGameId = new QLabel(verticalLayoutWidget);
        labelGameId->setObjectName(QStringLiteral("labelGameId"));
        labelGameId->setFont(font);
        labelGameId->setMouseTracking(true);
        labelGameId->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelGameId);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color:rgb(219, 41, 41);\n"
"	border-radius:10px;\n"
"	color:black;\n"
"	font-family:Arial;\n"
"	font-size:18px;\n"
"   	font-weight:bold;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(255, 41, 41);\n"
"}\n"
"QPushButton:active {\n"
"	position:relative;\n"
"	top:1px;\n"
"}"));
        pushButton->setFlat(false);

        verticalLayout->addWidget(pushButton, 0, Qt::AlignHCenter);

        labelGif = new QLabel(WaitingWindow);
        labelGif->setObjectName(QStringLiteral("labelGif"));
        labelGif->setGeometry(QRect(20, 90, 241, 151));
        labelGif->setAlignment(Qt::AlignCenter);
        label = new QLabel(WaitingWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 16, 261, 51));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(WaitingWindow);

        QMetaObject::connectSlotsByName(WaitingWindow);
    } // setupUi

    void retranslateUi(QDialog *WaitingWindow)
    {
        WaitingWindow->setWindowTitle(QApplication::translate("WaitingWindow", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("WaitingWindow", "Your game id is:", Q_NULLPTR));
        labelGameId->setText(QApplication::translate("WaitingWindow", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("WaitingWindow", "Exit Game", Q_NULLPTR));
        labelGif->setText(QString());
        label->setText(QApplication::translate("WaitingWindow", "<html><head/><body><p align=\"center\">Waiting for your opponent </p><p align=\"center\">to join the room</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WaitingWindow: public Ui_WaitingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITINGWINDOW_H
