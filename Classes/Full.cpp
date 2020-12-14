#include "Full.h"
#include <map>
#include <numeric>

bool Full::valid_input(const std::vector<Dice>& input) const{


    std::map<Dice, int> check;
    for(const Dice& dice : input){
        check[dice]++;
    }
    if(check.size() != 2){
        return false;
    }

    /* we determined that we have only two dices, so the first one is at the begin
     * and the second one right behind first
     * */
    int num_first_dice = check.begin()->second;
    int num_second_dice = (++check.begin())->second;


    // rule for Full house
    return (num_first_dice == 2 and num_second_dice == 3) or
           (num_first_dice == 3 and num_second_dice == 2);


}


void Full::calculate_field_value(const std::vector<Dice>& selected_dices){

    if(not this->valid_input(selected_dices)){
        field_value = 0;
    } else{

//      FIXME change this to std::accumulate when "int + Dice" is implemented
//      sum = std::accumulate(selected_dices.cbegin(), selected_dices.cend(), 0);
        int sum = 0;
        for(const Dice& dice : selected_dices){
            sum += dice.get_value();
        }
        field_value = sum + 30;
    }

}
