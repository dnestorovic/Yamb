#include "Poker.h"
#include "Dice.h"

bool Poker::valid_input(const std::vector<Dice>& input) const{

    if(input.size() != 4)
        return false;

    Dice expected = input[0];
    for(const Dice& dice : input){
        if(dice != expected)
            return false;
    }

    return true;

}
void Poker::calculate_field_value(const std::vector<Dice>& selected_dices){

    if(not this->valid_input(selected_dices))
        field_value = 0;
    else{

//      FIXME change this to std::accumulate when "int + Dice" is implemented
        //FIXME all dices have the same value so just 4 * selected_dices[0]...
//      sum = std::accumulate(selected_dices.cbegin(), selected_dices.cend(), 0);
        int sum = 0;
        for(const Dice& dice : selected_dices){
            sum += dice.get_value();
        }
        field_value = sum + 40;

    }


}
