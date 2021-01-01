QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../GameLogic/Dice.cpp \
    EndGameWindow.cpp \
    StartWindow.cpp \
    WaitingWindow.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    ../GameLogic/Dice.h \
    ../NetworkClient/ClientConnection.h \
    ../NetworkCommon/Message.h \
    ../NetworkCommon/RandomGenerator.h \
    ../NetworkCommon/ThreadSafeQueue.h \
    ../NetworkCommon/common.h \
    EndGameWindow.h \
    MainWindow.h \
    StartWindow.h \
    WaitingWindow.h

FORMS += \
    EndGameWindow.ui \
    MainWindow.ui \
    StartWindow.ui \
    WaitingWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
