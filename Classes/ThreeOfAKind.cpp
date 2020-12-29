#include "ThreeOfAKind.h"

bool ThreeOfAKind::valid_input(const std::vector<Dice>& input) const {

    if(input.size() != 3){
        return false;
    }

    Dice expected = input[0];
    for(const auto& dice : input){
        if(dice != expected){
            return false;
        }
    }

    return true;
}

void ThreeOfAKind::calculate_field_value(const std::vector<Dice>& selected_dices){

    if(not this->valid_input(selected_dices))
        field_value = 0;
    else
        field_value = 3 * selected_dices[0].get_value() + 20;
}
