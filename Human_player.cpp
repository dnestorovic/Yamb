#include "Human_player.h"
#include "Dice.h"
#include <iostream>

std::vector<Dice> HumanPlayer::throw_dices(std::istream &s){

    std::vector<Dice> dices;

    int value;
    Dice pom;
    for(int i = 0; i < number_of_dices; i++){
        s >> value;
        pom = Dice(value);
        dices.emplace_back(pom);
    }

    return dices;

}


std::vector<Dice> HumanPlayer::select_dices(std::vector<Dice> dices, std::vector<int> positions){

    unsigned i;
    unsigned n = positions.size();
    std::vector<Dice> selected_dices;

    for(i = 0; i < n; i++){
        selected_dices.push_back(dices[positions[i]]);
    }

    return selected_dices;

    //TODO

};

// FIXME function should have one more argument. Read .h file
void HumanPlayer::write_on_ticket(std::vector<Dice> dices) {

    //TODO
}