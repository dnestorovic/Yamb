cmake_minimum_required(VERSION 3.15)
project(14_jamb)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(14_jamb
        Classes/Game.cpp
        Classes/Game.h
        main.cpp
        Classes/Player.cpp
        Classes/Player.h
        Classes/Ticket.cpp
        Classes/Ticket.h
        Classes/Dice.cpp
        Classes/Dice.h
        Classes/Human_player.cpp
        Classes/Human_player.h
        Classes/Bot_player.h
        Classes/Bot_player.cpp
        Classes/Column.h
        Classes/Column.cpp
        Classes/C_FromUpToDown.h
        Classes/C_FromUpToDown.cpp
        Classes/Field.h
        Classes/F_Number.h
        Classes/F_Number.cpp
        Classes/MinMax.h
        Classes/MinMax.cpp
        Classes/Straight.h
        Classes/Straight.cpp
        Classes/Three_of_a_kind.h
        Classes/Three_of_a_kind.cpp
        Classes/Full.h
        Classes/Full.cpp
        Classes/Poker.h
        Classes/Poker.cpp
        Classes/Yamb.h
        Classes/Yamb.cpp
        Classes/C_Free.h
        Classes/C_Free.cpp
        Classes/C_FromBottom.h
        Classes/C_FromBottom.cpp
        Classes/C_Hand.h
        Classes/C_Hand.cpp
        Classes/C_FromMiddle.h
        Classes/C_FromMiddle.cpp
        Classes/C_ToMiddle.h
        Classes/C_ToMiddle.cpp
        Classes/C_Announcement.h
        Classes/C_Announcement.cpp
        Classes/C_AnnouncementRespond.h
        Classes/C_AnnouncementRespond.cpp
        Classes/C_Checkout.h
        Classes/C_Checkout.cpp
        Classes/C_Maximum.h
        Classes/C_Maximum.cpp)
