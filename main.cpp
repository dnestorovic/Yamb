#include <iostream>
#include <vector>

#include "Classes/Game.h"
#include "Classes/C_FromUpToDown.h"
#include "Classes/Straight.h"
#include "Classes/Column.h"
#include "Classes/C_Free.h"
#include "Classes/C_FromBottom.h"
#include "Classes/C_Hand.h"
#include "Classes/C_FromMiddle.h"
#include "Classes/C_ToMiddle.h"
#include "Classes/Human_player.h"

int main(){

    // DONE all field classes have been tested
    // DONE valid_order for C_FromUpToDown tested
    // DONE valid_order for C_Free tested
    // DONE valid_order for C_FromBottom tested
    // DONE valid_order for C_Hand tested
    // DONE valid_order for C_FromMiddle tested
    // DONE valid_order for C_ToMiddle tested

    /* TODO
     * implement classes for columns announcement_respond,
     * max_column and checkout once the backend was connected to the GUI*/

    Game g = Game(gameTypes::Online);

    std::vector<std::vector<int>> listic;

    std::vector<Dice> dices;
    dices.push_back(Dice(6));
    dices.push_back(Dice(6));
    dices.push_back(Dice(6));
    dices.push_back(Dice(6));
    dices.push_back(Dice(6));


    if(!g.player1.write_on_ticket(dices, Fields::Yamb, Columns::Announcement))
        return -1;

    dices.pop_back();
    dices.pop_back();

    if(!g.player1.write_on_ticket(dices, Fields::Three_of_a_kind, Columns::Announcement))
        return -1;


    listic = g.player1.ticket.get_ticket();
    for(auto & i : listic){
        for(int j : i){
            std::cout << j << "  ";
        }
        std::cout << std::endl;
    }

    return 0;

}