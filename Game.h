#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Dice.h"
#include "Player.h"
#include "Ticket.h"

using namespace std;

enum class gameTypes{
    Online,
    Offline,
    Bot,
};

class Game{
public:

    Game(gameTypes type){

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
    // class needs to have two players. Need to solve problem about classes that we use
};


#endif
