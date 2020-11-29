#include "Yamb.h"
#include <map>

bool Yamb::valid_input(const std::vector<Dice>& input) const{

    std::map<Dice, int> check;

    for(const Dice& dice : input){
        check[dice]++;
    }

    if(check.size() != 1){
        return false;
    }

    return check.cbegin()->second == 5;


}


void Yamb::calculate_field_value(const std::vector<Dice>& selected_dices){

    if(!valid_input(selected_dices)){
        field_value = 0;
    }
    else{
        field_value = 5 * selected_dices[0].get_value() + 50;
    }

}
