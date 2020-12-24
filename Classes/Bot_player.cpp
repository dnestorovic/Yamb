#include "Bot_player.h"
#include "Dice.h"
#include <iostream>
#include <algorithm>

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


void BotPlayer::calculate_priority() {

    int number_of_fields = 13;

    ////IF ANYTHING WAS ANNOUNCED THAT HAS TOP PRIORITY BY THE RULES OF THE GAME

    // everything from hand is top priority
    for(int i = 0; i < number_of_fields; i++){
        priority_for_play.emplace_back(i, 4);
    }

    // max column has second priority
    // lower fields have higher priority
    for(int i = number_of_fields; i > 0; i--){
        priority_for_play.emplace_back(i, 9);
    }

    // announce column has third priority
    // lower fields have higher priority
    for(int i = number_of_fields; i > 0; i--){
        priority_for_play.emplace_back(i, 3);
    }

    // column from_up has fourth priority
    // by the rules of the game, upper fields have higher priority
    for(int i=0; i < number_of_fields; i++){
        priority_for_play.emplace_back(i, 0);
    }

    // column from_bottom has fifth priority
    // by the rules of the game, lower fields have higher priority
    for(int i = number_of_fields; i > 0; i--){
        priority_for_play.emplace_back(i, 2);
    }

    // column from_middle has sixth priority
    // lower fields have higher priority
    //// it must be check if the player can play some move by the rules of the game for this column
    for(int i = number_of_fields; i > 0; i--){
        priority_for_play.emplace_back(i, 6);
    }


    // column to_middle has seventh priority
    // lower fields have higher priority
    for(int i = number_of_fields; i > 0; i--){
        priority_for_play.emplace_back(i, 7);
    }

    // free has lowest priority
    // lower fields have higher priority
    for(int i = number_of_fields; i > 0; i--){
        priority_for_play.emplace_back(i, 1);
    }

}

std::pair<Columns, Fields> BotPlayer::convert_priority_to_enum(std::pair<int, int> coordinates) const{

    int i = coordinates.first;
    int j = coordinates.second;

    Fields field;
    Columns column;

    // calculate field by index
    switch(i){
        case 0:
            field = Fields::Number_1;
            break;
        case 1:
            field = Fields::Number_2;
            break;
        case 2:
            field = Fields::Number_3;
            break;
        case 3:
            field = Fields::Number_4;
            break;
        case 4:
            field = Fields::Number_5;
            break;
        case 5:
            field = Fields::Number_6;
            break;
        case 6:
            field = Fields::Maximum;
            break;
        case 7:
            field = Fields::Minimum;
            break;
        case 8:
            field = Fields::Straight;
            break;
        case 9:
            field = Fields::Three_of_a_kind;
            break;
        case 10:
            field = Fields::Full;
            break;
        case 11:
            field = Fields::Poker;
            break;
        case 12:
            field = Fields::Yamb;
            break;
        default:
            std::cerr << "This should never happen(enum conversion)";
    }

    // calculate column by index
    switch(j){
        case 0:
            column = Columns::From_Up;
            break;
        case 1:
            column = Columns::Free;
            break;
        case 2:
            column = Columns::From_Bottom;
            break;
        case 3:
            column = Columns::Announcement;
            break;
        case 4:
            column = Columns::Hand;
            break;
        case 5:
            column = Columns::AnnouncementRespond;
            break;
        case 6:
            column = Columns::From_Middle;
            break;
        case 7:
            column = Columns::To_Middle;
            break;
        case 8:
            column = Columns::Checkout;
            break;
        case 9:
            column = Columns::Maximum;
            break;
        default:
            std::cerr << "This should never happen(enum conversion)";
    }


    return std::make_pair(column, field);


}


std::pair<Columns, Fields> BotPlayer::find_best_move(double probability_tolerance) const{

    // variables that bot uses
    Fields field_for_play = Fields::None;
    Columns column_for_play = Columns::None;

    Fields field_tmp = Fields::None;
    Columns column_tmp = Columns::None;

    std::pair<Columns, Fields> tmp;

    // find the best move by priority
    for(const auto& should_play : priority_for_play){

        tmp = convert_priority_to_enum(should_play);

        column_tmp = tmp.first;
        field_tmp = tmp.second;

        // check if this move can be played by the rules of the column, and if the field is not
        // filled yet
        if(!ticket.can_be_played(column_tmp, field_tmp))
            continue;


        // TODO CALCULATE PROBABILITY
        

        field_for_play = field_tmp;
        column_for_play = column_tmp;
    }

    return std::make_pair(column_for_play, field_for_play);

}

std::pair<Columns, Fields> BotPlayer::decide_next_move() const{

    Fields field_for_play = Fields::None;
    Columns column_for_play = Columns::None;


    // starting probability should be 0.99, because if bot already has something to play
    // probability for that move is 1 so he decides to play safe move
    double probability_tolerance = 0.99;



    // until bot decide what he can play, try to find move
    while(field_for_play == Fields::None and column_for_play == Columns::None){

        // find the best possible move for current probability
        std::pair<Columns, Fields> answer = find_best_move(probability_tolerance);

        // answer from the best move function
        column_for_play = answer.first;
        field_for_play = answer.second;


        // if bot has no move to play we decrease required probability
        // and we give the bot a chance to find other move
        if(field_for_play == Fields::None or column_for_play == Columns::None) {
            std::cout << "Bot hasn't decide yet what he can play" << std::endl;

            // TODO this parameter should be tested to decide how fast tolerance should decrease
            probability_tolerance -= 0.1;
        }

    }

    return std::make_pair(column_for_play, field_for_play);

}


void BotPlayer::play_next_move() {




    //// At the end we must delete played field from priority moves

}

