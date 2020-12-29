cmake_minimum_required(VERSION 3.15)
project(NetworkServer)

set(CMAKE_CXX_STANDARD 14)
set(Boost_USE_STATIC_LIBS OFF)

find_package(Boost REQUIRED COMPONENTS system thread)

include_directories(.)
include_directories(${Boost_INCLUDE_DIR})

add_executable(server
        main.cpp
        ../Classes/Game.cpp
        ../Classes/Game.h
        ../Classes/Player.cpp
        ../Classes/Player.h
        ../Classes/Ticket.cpp
        ../Classes/Ticket.h
        ../Classes/Dice.cpp
        ../Classes/Dice.h
        ../Classes/Human_player.cpp
        ../Classes/Human_player.h
        ../Classes/Column.h
        ../Classes/Column.cpp
        ../Classes/C_FromUp.h
        ../Classes/C_FromUp.cpp
        ../Classes/Field.h
        ../Classes/F_Number.h
        ../Classes/F_Number.cpp
        ../Classes/MinMax.h
        ../Classes/MinMax.cpp
        ../Classes/Straight.h
        ../Classes/Straight.cpp
        ../Classes/ThreeOfAKind.h
        ../Classes/ThreeOfAKind.cpp
        ../Classes/Full.h
        ../Classes/Full.cpp
        ../Classes/Poker.h
        ../Classes/Poker.cpp
        ../Classes/Yamb.h
        ../Classes/Yamb.cpp
        ../Classes/C_Free.h
        ../Classes/C_Free.cpp
        ../Classes/C_FromBottom.h
        ../Classes/C_FromBottom.cpp
        ../Classes/C_Hand.h
        ../Classes/C_Hand.cpp
        ../Classes/C_FromMiddle.h
        ../Classes/C_FromMiddle.cpp
        ../Classes/C_ToMiddle.h
        ../Classes/C_ToMiddle.cpp
        ../Classes/C_Announcement.h
        ../Classes/C_Announcement.cpp
        ../Classes/C_Respond.h
        ../Classes/C_Respond.cpp
        ../Classes/C_Checkout.h
        ../Classes/C_Checkout.cpp
        ../Classes/C_Maximum.h
        ../Classes/C_Maximum.cpp)

target_link_libraries(server ${Boost_LIBRARIES})
