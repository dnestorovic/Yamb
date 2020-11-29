#include "Straight.h"
#include <algorithm>
#include <set>

struct comparison_struct{

    // Get value can be replaced with override of operator < or > be replaced with
    inline bool operator()(const Dice& d1, const Dice& d2)
    {
        return d1.get_value() < d2.get_value();
    }
};

bool Straight::valid_input(const std::vector<Dice>& input) const{

    std::set<Dice> set_of_dices;

    for(const auto& dice : input){
        set_of_dices.insert(dice);
    }

    return set_of_dices.size() == 5;

}


void Straight::calculate_field_value(const std::vector<Dice>& selected_dices){

    switch(number_of_throws){
        case 1:{
            field_value = 66;
            break;
        }
        case 2:{
            field_value = 56;
            break;
        }
        case 3:{
            field_value = 46;
            break;
        }
        default:
            std::cout << "This should never happen";
    }

}

