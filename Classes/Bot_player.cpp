#include "Bot_player.h"
#include "Dice.h"

#include <set>
#include <iostream>
#include <algorithm>
#include <cmath>

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


bool BotPlayer::write_on_ticket(std::vector<Dice>& dices, Fields field, Columns column, int number_of_throws) {

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


std::pair<Columns, Fields> BotPlayer::find_best_move(std::vector<Dice>& dices, double probability_tolerance) const{

    // variables that bot uses
    Fields field_for_play = Fields::None;
    Columns column_for_play = Columns::None;

    Fields field_tmp = Fields::None;
    Columns column_tmp = Columns::None;

    std::pair<Columns, Fields> tmp;



    // find the best move by priority
    for(const auto& should_play : priority_for_play){

        // convert coordinates to enum
        tmp = convert_priority_to_enum(should_play);

        column_tmp = tmp.first;
        field_tmp = tmp.second;

        // check if this move can be played by the rules of the column, and if the field is not
        // filled yet
        if(!ticket.can_be_played(column_tmp, field_tmp))
            continue;

        double proba = calculate_probability(field_tmp, dices);
        // TODO CALCULATE PROBABILITY


        field_for_play = field_tmp;
        column_for_play = column_tmp;
    }

    return std::make_pair(column_for_play, field_for_play);

}

std::pair<Columns, Fields> BotPlayer::decide_next_move(std::vector<Dice>& dices) const{

    Fields field_for_play = Fields::None;
    Columns column_for_play = Columns::None;


    // starting probability should be 0.99, because if bot already has something to play
    // probability for that move is 1 so he decides to play safe move
    double probability_tolerance = 0.99;



    // until bot decide what he can play, try to find move
    while(field_for_play == Fields::None and column_for_play == Columns::None){

        // find the best possible move for current probability
        std::pair<Columns, Fields> answer = find_best_move(dices, probability_tolerance);

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

    // FIXME this should fix team that works with server and put their function for throw
    std::vector<Dice> dices = throw_dices(std::cin);

    // Which move should bot attempt to play
    std::pair<Columns, Fields> next_move = decide_next_move(dices);

    // select dices based on next move attempt


    //// At the end we must delete played field from priority moves

}

// calculate binomial coefficients for given arguments
int binomialCoeff(int n, int k){
    int C[n + 1][k + 1];
    int i, j;

    // Calculate value of Binomial Coefficient
    // in bottom up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= std::min(i, k); j++) {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

                // Calculate value using previously
                // stored values
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}




/* **********************************************************
 * calculate probability to get something based on dices
 *
 * ->for the upper fields it is okay to have 3 or more of the same because in that way bot will
 *   reach 60+ points in upper part of the column and get 30 extra points
 *
 * ->for maximum it is okay if we can reach sum above 25
 * ->for minimum it is okay if we can reach sum less then 8
 *
 * ->for lower fields it is okay if we can fulfill the condition
 * ***********************************************************/

// calculate probability to get at least 3 of the same
double probability_for_one(std::vector<Dice>& dices){

    int num_of_wanted = 0;
    int num_of_rest = dices.size();

    // calculate current situation
    for(const auto& dice : dices){
        if(dice.get_value() == 1){
            num_of_wanted++;
            num_of_rest--;
        }
    }


    // if we already have wanted number of dices, probability to get it is 1
    if(num_of_wanted >= 3){
        return 1.0;
    }

    // calculate probability to get 3 or more in next move
    int dices_needed = 3 - num_of_wanted;
    double probability = 0.0;

    for(int i = dices_needed; i <= num_of_rest; i++){
        probability += binomialCoeff(num_of_rest, i) * pow((1.0/6.0), i)
                                                     * pow((5.0/6.0),num_of_rest - i);
    }

    return probability;

}

// calculate probability to get at least 3 of the same
double probability_for_two(std::vector<Dice>& dices){

    int num_of_wanted = 0;
    int num_of_rest = dices.size();

    // calculate current situation
    for(const auto& dice : dices){
        if(dice.get_value() == 2){
            num_of_wanted++;
            num_of_rest--;
        }
    }


    // if we already have wanted number of dices, probability to get it is 1
    if(num_of_wanted >= 3){
        return 1.0;
    }

    // calculate probability to get 3 or more in next move
    int dices_needed = 3 - num_of_wanted;
    double probability = 0.0;

    for(int i = dices_needed; i <= num_of_rest; i++){
        probability += binomialCoeff(num_of_rest, i) * pow((1.0/6.0), i)
                       * pow((5.0/6.0),num_of_rest - i);
    }

    return probability;

}


// calculate probability to get at least 3 of the same
double probability_for_three(std::vector<Dice>& dices){

    int num_of_wanted = 0;
    int num_of_rest = dices.size();

    // calculate current situation
    for(const auto& dice : dices){
        if(dice.get_value() == 3){
            num_of_wanted++;
            num_of_rest--;
        }
    }


    // if we already have wanted number of dices, probability to get it is 1
    if(num_of_wanted >= 3){
        return 1.0;
    }


    // calculate probability to get 3 or more in next move
    int dices_needed = 3 - num_of_wanted;
    double probability = 0.0;

    for(int i = dices_needed; i <= num_of_rest; i++){
        probability += binomialCoeff(num_of_rest, i) * pow((1.0/6.0), i)
                       * pow((5.0/6.0),num_of_rest - i);
    }

    return probability;

}


// calculate probability to get at least 3 of the same
double probability_for_four(std::vector<Dice>& dices){


    int num_of_wanted = 0;
    int num_of_rest = dices.size();

    // calculate current situation
    for(const auto& dice : dices){
        if(dice.get_value() == 4){
            num_of_wanted++;
            num_of_rest--;
        }
    }

    // if we already have wanted number of dices, probability to get it is 1
    if(num_of_wanted >= 3){
        return 1.0;
    }

    // calculate probability to get 3 or more in next move
    int dices_needed = 3 - num_of_wanted;
    double probability = 0.0;

    for(int i = dices_needed; i <= num_of_rest; i++){
        probability += binomialCoeff(num_of_rest, i) * pow((1.0/6.0), i)
                       * pow((5.0/6.0),num_of_rest - i);
    }

    return probability;

}


// calculate probability to get at least 3 of the same
double probability_for_five(std::vector<Dice>& dices){

    int num_of_wanted = 0;
    int num_of_rest = dices.size();

    // calculate current situation
    for(const auto& dice : dices){
        if(dice.get_value() == 5){
            num_of_wanted++;
            num_of_rest--;
        }
    }


    // if we already have wanted number of dices, probability to get it is 1
    if(num_of_wanted >= 3){
        return 1.0;
    }


    // calculate probability to get 3 or more in next move
    int dices_needed = 3 - num_of_wanted;
    double probability = 0.0;

    for(int i = dices_needed; i <= num_of_rest; i++){
        probability += binomialCoeff(num_of_rest, i) * pow((1.0/6.0), i)
                       * pow((5.0/6.0),num_of_rest - i);
    }

    return probability;

}


// calculate probability to get at least 3 of the same
double probability_for_six(std::vector<Dice>& dices){

    int num_of_wanted = 0;
    int num_of_rest = dices.size();

    // calculate current situation
    for(const auto& dice : dices){
        if(dice.get_value() == 6){
            num_of_wanted++;
            num_of_rest--;
        }
    }


    // if we already have wanted number of dices, probability to get it is 1
    if(num_of_wanted >= 3){
        return 1.0;
    }

    // calculate probability to get 3 or more in next move
    int dices_needed = 3 - num_of_wanted;
    double probability = 0.0;

    for(int i = dices_needed; i <= num_of_rest; i++){
        probability += binomialCoeff(num_of_rest, i) * pow((1.0/6.0), i)
                       * pow((5.0/6.0),num_of_rest - i);
    }

    return probability;

}



double probability_for_max(std::vector<Dice>& dices){

    // we aim to play with 5 and 6 only as long as we can
    // at the end of the move if we don't have sum above 25 we will decide what to play
    // with the dices we currently have
    int sum = 0;
    int num_of_rest = dices.size();

    // calculate current situation
    for(const auto& dice : dices){
        if(dice.get_value() == 6){
            num_of_rest--;
            sum += 6;
        }

        if(dice.get_value() == 5){
            num_of_rest--;
            sum += 5;
        }

    }


    // if we already have wanted sum of dices, probability to get it is 1
    if(sum >= 25){
        return 1.0;
    }

    // calculate probability to reach sum above 25 with the rest of the dices
    double probability = 0.0;

    for(int i = 0; i <= num_of_rest; i++){
        // probability to get 5 is 1/6
        // probability to get 6 is 1/6
        // probability to get all 5 from the rest is (1/6)^num_of_rest
        // probability to get all 6 from the rest is (1/6)^(num_of_rest - num_of_fives)
        // at the end probability to reach sum of 25 is equal to probability of getting
        // all 5, or some 5 and some 6, or all 6
        probability += pow((1.0/6.0), num_of_rest - i) * pow((1.0/6.0), i)
                                                       * binomialCoeff(num_of_rest, i);
    }

    return probability;


}


// it is okay that we get minimum less then 8
double probability_for_min(std::vector<Dice>& dices){

    // we aim to play miniumu with only 1 and 2 as long as we can
    // when we don't have other choice we will decide what we play with dices that we currently have
    int sum = 0;
    int num_of_rest = dices.size();

    // calculate current situation
    for(const auto& dice : dices){
        if(dice.get_value() == 1){
            num_of_rest--;
            sum += 1;
        }

        if(dice.get_value() == 2){
            num_of_rest--;
            sum += 2;
        }

    }


    // if we already have wanted sum of dices, probability to get it is 1
    if(sum <= 8){
        return 1.0;
    }

    // calculate probability to reach sum less then 8 with the rest of the dices
    double probability = 0.0;

    for(int i = 0; i <= num_of_rest; i++){
        // the formula have been explained earlier in the code when we describe how we calculate
        // probability to get some dices for maximum
        probability += pow((1.0/6.0), num_of_rest - i) * pow((1.0/6.0), i)
                       * binomialCoeff(num_of_rest, i);
    }

    return probability;

}



double probability_for_straight(std::vector<Dice>& dices){

    std::set<Dice> straight_set;

    for(const auto& dice : dices){
        straight_set.insert(dice);
    }

    // if we already have straight probability to get straight is 1.0
    // straight must have 5 dices and it will be in range [1,5] or [2,6]
    // so the distance between first and last dice value must be 4
    if(straight_set.size() == 5){
        if(straight_set.cend()->get_value() - straight_set.cbegin()->get_value() == 4)
            return 1.0;
    }


    // calculate probability to get straight with the rest of the dices
    unsigned num_of_rest = dices.size() - straight_set.size();
    double probability = pow((1.0/6.0), num_of_rest);

    return probability;

}



double probability_for_tok(std::vector<Dice>& dices){

}



double probability_for_full(std::vector<Dice>& dices){

}



double probability_for_poker(std::vector<Dice>& dices){

}


double probability_for_yamb(std::vector<Dice>& dices){

}




// calculates probability based on field that can be play and dices that bot currently has
double BotPlayer::calculate_probability(Fields field, std::vector<Dice>& dices) const{

    switch(field){
        case Fields::Number_1:
            return probability_for_one(dices);
        case Fields::Number_2:
            return probability_for_two(dices);
        case Fields::Number_3:
            return probability_for_three(dices);
        case Fields::Number_4:
            return probability_for_four(dices);
        case Fields::Number_5:
            return probability_for_five(dices);
        case Fields::Number_6:
            return probability_for_six(dices);
        case Fields::Maximum:
            return probability_for_max(dices);
        case Fields::Minimum:
            return probability_for_min(dices);
        case Fields::Straight:
            return probability_for_straight(dices);
        case Fields::Three_of_a_kind:
            return probability_for_tok(dices);
        case Fields::Full:
            return probability_for_full(dices);
        case Fields::Poker:
            return probability_for_poker(dices);
        case Fields::Yamb:
            return probability_for_yamb(dices);
        case Fields::None:
            break;
    }


}
