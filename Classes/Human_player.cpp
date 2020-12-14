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

            if(*announcement){
                std::cout << "Other player announce something";
                return false;
            }

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

            if(*announcement){
                std::cout << "Other player announce something";
                return false;
            }

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

            if(*announcement){
                std::cout << "Other player announce something";
                return false;
            }

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

            if(*announcement){
                std::cout << "Other player announce something";
                return false;
            }

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

            if(*announcement){
                std::cout << "Other player announce something";
                return false;
            }

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

            if(*announcement){
                std::cout << "Other player announce something";
                return false;
            }

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
        case Columns::Announcement:{

            if(!*announcement){
                std::cout << "You must announce field that you want to play";
                return false;
            }
            // check if the field can be written
            if(ticket.announcement.valid_order(field)){
                ticket.announcement.write_in_column(dices, field);
                return true;
            }
            else{
                std::cout << "You can't write in this field";
                return false;
            }


        }
        case Columns::AnnouncementRespond:{

            if(!*announcement){
                std::cout << "Other player didn't announce anything. You can't play this";
                return false;
            }

            // check if the field can be written
            if(ticket.respond.valid_order(field)){
                // write in ticket and then say that player responded to announcement
                ticket.respond.write_in_column(dices, field);
                respond_announce();
                return true;
            }
            else{
                std::cout << "You can't write in this field";
                return false;
            }


        }


    }

}


bool HumanPlayer::announce(Fields field) {

    if(*announcement){
        std::cout << "Something is already announced";
        return false;
    }

    *announcement = true;
    *field_announced = field;

    return true;
}

void HumanPlayer::respond_announce() {
    *announcement = false;
    *field_announced = Fields::None;
}
