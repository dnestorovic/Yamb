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
    // DONE valid_order for C_Announcement tested
    // DONE Announcement set

    /* TODO
     * implement classes for columns:
     * max_column and checkout once the backend was connected to the GUI*/

    ////DONE Testing of announcement and respond

    Game g = Game(gameTypes::Online);

    std::vector<std::vector<int>> t;

    std::vector<Dice> dices;
    dices.push_back(Dice(5));
    dices.push_back(Dice(5));
    dices.push_back(Dice(5));
    dices.push_back(Dice(5));
    dices.push_back(Dice(5));

    g.player1.write_on_ticket(dices, Fields::Yamb, Columns::From_Bottom, 1);

    dices.pop_back();
    g.player1.write_on_ticket(dices, Fields::Poker, Columns::From_Bottom, 1);

    dices.pop_back();
    dices.push_back(Dice(6));
    dices.push_back(Dice(6));

    g.player1.write_on_ticket(dices, Fields::Full, Columns::From_Bottom, 1);

    dices.pop_back();
    dices.pop_back();

    g.player1.write_on_ticket(dices, Fields::Three_of_a_kind, Columns::From_Bottom, 1);

    dices.pop_back();
    dices.pop_back();
    dices.pop_back();

    dices.push_back(Dice(1));
    dices.push_back(Dice(2));
    dices.push_back(Dice(3));
    dices.push_back(Dice(4));
    dices.push_back(Dice(5));

    g.player1.write_on_ticket(dices, Fields::Straight, Columns::From_Bottom, 3);

    dices.pop_back();
    dices.pop_back();
    dices.pop_back();
    dices.pop_back();
    dices.pop_back();
    dices.push_back(Dice(1));
    dices.push_back(Dice(2));
    dices.push_back(Dice(1));
    dices.push_back(Dice(2));
    dices.push_back(Dice(2));


    g.player1.write_on_ticket(dices, Fields::Minimum, Columns::From_Bottom, 3);
    dices.pop_back();
    dices.pop_back();
    dices.pop_back();
    dices.pop_back();
    dices.pop_back();
    dices.push_back(Dice(5));
    dices.push_back(Dice(4));
    dices.push_back(Dice(6));
    dices.push_back(Dice(6));
    dices.push_back(Dice(6));

    g.player1.write_on_ticket(dices, Fields::Maximum, Columns::From_Bottom, 3);

    dices.pop_back();
    dices.pop_back();
    dices.pop_back();
    dices.pop_back();
    dices.pop_back();
    dices.push_back(Dice(6));
    dices.push_back(Dice(6));
    dices.push_back(Dice(6));

    g.player1.write_on_ticket(dices, Fields::Number_6, Columns::From_Bottom, 3);

    dices.pop_back();
    dices.pop_back();
    dices.pop_back();
    dices.push_back(Dice(5));
    dices.push_back(Dice(5));
    dices.push_back(Dice(5));
    dices.push_back(Dice(6));



    g.player1.write_on_ticket(dices, Fields::Number_5, Columns::From_Bottom, 3);

    dices.pop_back();
    dices.pop_back();
    dices.pop_back();
    dices.pop_back();

    dices.push_back(Dice(1));
    dices.push_back(Dice(1));
    dices.push_back(Dice(1));

    g.player1.write_on_ticket(dices, Fields::Number_4, Columns::From_Bottom, 3);
    g.player1.write_on_ticket(dices, Fields::Number_3, Columns::From_Bottom, 3);
    g.player1.write_on_ticket(dices, Fields::Number_2, Columns::From_Bottom, 3);
    g.player1.write_on_ticket(dices, Fields::Number_1, Columns::From_Bottom, 3);






    t = g.player1.get_ticket().get_ticket_value();
    for(auto & i : t){
        for(int j : i){
            std::cout << j << "  ";
        }
        std::cout << std::endl;
    }



    return 0;

}