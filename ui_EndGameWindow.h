/********************************************************************************
** Form generated from reading UI file 'EndGameWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDGAMEWINDOW_H
#define UI_ENDGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EndGameWindow
{
public:
    QPushButton *btnExitGame;
    QLabel *labelWinner;

    void setupUi(QDialog *EndGameWindow)
    {
        if (EndGameWindow->objectName().isEmpty())
            EndGameWindow->setObjectName(QStringLiteral("EndGameWindow"));
        EndGameWindow->setWindowModality(Qt::ApplicationModal);
        EndGameWindow->resize(363, 289);
        EndGameWindow->setStyleSheet(QStringLiteral("background: rgb(110, 150, 200);"));
        EndGameWindow->setModal(true);
        btnExitGame = new QPushButton(EndGameWindow);
        btnExitGame->setObjectName(QStringLiteral("btnExitGame"));
        btnExitGame->setGeometry(QRect(130, 240, 101, 30));
        btnExitGame->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color:rgb(255, 45, 45);\n"
"	border-radius:10px;\n"
"	color:black;\n"
"	font-family:Arial;\n"
"	font-size:15px;\n"
"   	font-weight:bold;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(255, 41, 41);\n"
"}\n"
"QPushButton:active {\n"
"	position:relative;\n"
"	top:1px;\n"
"}"));
        labelWinner = new QLabel(EndGameWindow);
        labelWinner->setObjectName(QStringLiteral("labelWinner"));
        labelWinner->setGeometry(QRect(40, 60, 281, 131));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Condensed"));
        font.setPointSize(47);
        font.setBold(true);
        font.setWeight(75);
        labelWinner->setFont(font);
        labelWinner->setStyleSheet(QStringLiteral("color: white;"));
        labelWinner->setAlignment(Qt::AlignCenter);

        retranslateUi(EndGameWindow);

        QMetaObject::connectSlotsByName(EndGameWindow);
    } // setupUi

    void retranslateUi(QDialog *EndGameWindow)
    {
        EndGameWindow->setWindowTitle(QApplication::translate("EndGameWindow", "Dialog", Q_NULLPTR));
        btnExitGame->setText(QApplication::translate("EndGameWindow", "Exit game", Q_NULLPTR));
        labelWinner->setText(QApplication::translate("EndGameWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EndGameWindow: public Ui_EndGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDGAMEWINDOW_H
