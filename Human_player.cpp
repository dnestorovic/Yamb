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

bool HumanPlayer::write_on_ticket(std::vector<Dice>& dices, Fields field, Columns column){

    switch(column){
        case Columns::From_Up:{

            // check if the field can be written
            if(ticket.from_up_to_down.valid_order(field)){
                ticket.from_up_to_down.write_in_column(dices, field);
                return true;
            }
            else{
                std::cout << "You can't write in this field";
                return false;
            }

        }
        case Columns::Free:{

            // check if the field can be written
            if(ticket.free.valid_order(field)){
                ticket.free.write_in_column(dices, field);
                return true;
            }
            else{
                std::cout << "You can't write in this field";
                return false;
            }

        }
        case Columns::From_Bottom:{

            // check if the field can be written
            if(ticket.from_bottom.valid_order(field)){
                ticket.from_bottom.write_in_column(dices, field);
                return true;
            }
            else{
                std::cout << "You can't write in this field";
                return false;
            }

        }
        case Columns::Hand:{

            // check if the field can be written
            if(ticket.hand.valid_order(field)){
                ticket.hand.write_in_column(dices, field);
                return true;
            }
            else{
                std::cout << "You can't write in this field";
                return false;
            }

        }
        case Columns::From_Middle:{

            // check if the field can be written
            if(ticket.from_middle.valid_order(field)){
                ticket.from_middle.write_in_column(dices, field);
                return true;
            }
            else{
                std::cout << "You can't write in this field";
                return false;
            }

        }
        case Columns::To_Middle:{

            // check if the field can be written
            if(ticket.to_middle.valid_order(field)){
                ticket.to_middle.write_in_column(dices, field);
                return true;
            }
            else{
                std::cout << "You can't write in this field";
                return false;
            }


        }


    }

}
