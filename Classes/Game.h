#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Dice.h"
#include "Player.h"
#include "Human_player.h"
#include "Classes/Bot_player.h"
#include "Ticket.h"
#include "Column.h"



enum class gameTypes{
    Online,
    Offline,
    Bot,
};


class Game{
public:

    explicit Game(gameTypes type){

        announcement = false;
        field_announced = Fields :: None;

        if(type == gameTypes::Online or type == gameTypes::Offline){
            player1 = HumanPlayer(&announcement, &field_announced, 1);
            player2 = HumanPlayer(&announcement, &field_announced, 2);
        }
        else if(type == gameTypes::Bot){
            // TODO add ctor and field for bot player
        }

        // resize dices vector to 6 because we use 6 dices in game
        dices.resize(6);

        player_turn = 1;
    }

    void switch_turn();


    // all fields should be public because everyone can watch game state
    std::vector<Dice> dices;
    HumanPlayer player1;
    HumanPlayer player2;

    // defines which player is yet to play
    int player_turn;

    // set communication fields between game and players
    bool announcement;
    Fields field_announced;

};


#endif
