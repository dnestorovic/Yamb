#include "Bot_player.h"
#include "Dice.h"
#include <iostream>

/*TODO
 * This function is yet to be implement, for now focus is on Human player game
 * */
std::vector<Dice> BotPlayer::throw_dices(std::istream &s){

    std::vector<Dice> dices;

    int value;
    for(int i = 0; i < number_of_dices; i++){
        s >> value;
        dices.emplace_back(value);
    }

    return dices;

}


std::vector<Dice> BotPlayer::select_dices(std::vector<Dice> dices, std::vector<int> positions){

    //TODO

};


bool BotPlayer::write_on_ticket(std::vector<Dice>& dices, Fields field, Columns column) {

    //TODO
}


bool BotPlayer::announce(Fields field) {

    //TODO

}

void BotPlayer::respond_announce(){

    // TODO

}