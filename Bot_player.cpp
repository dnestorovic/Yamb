#include "Bot_player.h"
#include "Dice.h"
#include <iostream>

int number_of_dices = 6;

std::vector<Dice> BotPlayer::throw_dices(std::iostream &s){

    std::vector<Dice> dices;

    int value;
    for(int i = 0; i < number_of_dices; i++){
        s >> value;
        dices.emplace_back(value);
    }

    return dices;

}


std::vector<Dice> BotPlayer::select_dices(std::vector<Dice> dices, std::vector<Dice> positions){

    //TODO

};


void BotPlayer::write_on_ticket(std::vector<Dice> dices) {

    //TODO
}