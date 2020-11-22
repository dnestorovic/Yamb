#include "Human_player.h"
#include "Dice.h"
#include <iostream>

int number_of_dices = 6;

std::vector<Dice> HumanPlayer::throw_dices(std::iostream &s){

    std::vector<Dice> dices;

    int value;
    for(int i = 0; i < number_of_dices; i++){
        s >> value;
        dices.emplace_back(value);
    }

    return dices;

}


std::vector<Dice> HumanPlayer::select_dices(std::vector<Dice> dices, std::vector<Dice> positions){

    unsigned i;
    unsigned n = positions.size();
    std::vector<Dice> selected_dices;

    for(i = 0; i < n; i++){
        selected_dices.push_back(dices[positions[i]]);
    }

    return selected_dices;

};


void HumanPlayer::write_on_ticket(std::vector<Dice> dices) {

    //TODO
}