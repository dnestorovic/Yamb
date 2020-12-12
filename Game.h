#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Dice.h"
#include "Player.h"
#include "Human_player.h"
#include "Bot_player.h"
#include "Ticket.h"
#include "Column.h"


using namespace std;

enum class gameTypes{
    Online,
    Offline,
    Bot,
};


enum class columnType{


};

class Game{
public:

    Game(gameTypes type){

        // TODO discuss with people who works on server how to create games of different types
        // determinate which type of game we are going to create
        switch(type){
            case gameTypes::Online: ;
                // game constructor for online game
            case gameTypes::Offline: ;
                // game constructor for offline game
            case gameTypes::Bot: ;
                // game constructor for Bot game
            default: ;
                // default behavior that should not happen

        }

        // resize dices vector to 6 because we use 6 dices in game
        dices.resize(6);

    }

private:
    std::vector<Dice> dices;


    // TODO create players here
    // class needs to have two players. Need to solve problem about classes that we use
};


#endif
