#include <iostream>
#include <vector>

#include "Game.h"
#include "C_FromUpToDown.h"
#include "Straight.h"
#include "Column.h"
#include "C_Free.h"
#include "C_FromBottom.h"
#include "C_Hand.h"
#include "C_FromMiddle.h"
#include "C_ToMiddle.h"
#include "Human_player.h"

int main(){

    // DONE all field classes have been tested
    // DONE valid_order for C_FromUpToDown tested
    // DONE valid_order for C_Free tested
    // DONE valid_order for C_FromBottom tested
    // DONE valid_order for C_Hand tested
    // DONE valid_order for C_FromMiddle tested
    // DONE valid_order for C_ToMiddle tested

    /* TODO
     * implement classes for columns announcement, announcement_respond,
     * max_column and checkout once the backend was connected to the GUI*/

    HumanPlayer h = HumanPlayer();

    std::vector<std::vector<int>> listic;

    std::vector<Dice> dices;
    dices.push_back(Dice(6));
    dices.push_back(Dice(6));
    dices.push_back(Dice(6));
    dices.push_back(Dice(6));
    dices.push_back(Dice(6));


    if(!h.write_on_ticket(dices, Fields::Yamb, Columns::From_Bottom))
        return -1;



    listic = h.ticket.get_ticket();
    for(auto & i : listic){
        for(int j : i){
            std::cout << j << "  ";
        }
        std::cout << std::endl;
    }

    return 0;

}