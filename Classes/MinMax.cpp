#include "MinMax.h"

// function that checks whatever we use valid input values or not
bool MinMax::valid_input(const std::vector<Dice>& input) const{
    // the only condition is that we select 5 dices
    return input.size() == 5;
}

int MinMax::get_field_value() const {
    return field_value;
}

// function that calculates value of the field
void MinMax::calculate_field_value(const std::vector<Dice>& selected_dices){

    if(not valid_input(selected_dices)){
        std::cout << "Please select 5 dices to play this move!" << std::endl;
        return;
    }

    int sum = 0;
    for(const auto& dice : selected_dices){
        sum += dice.get_value();
    }

    field_value = sum;
}

// we use this for middle sums
int MinMax::operator-(const MinMax& other) const{
    return this->field_value - other.field_value;
}

int MinMax::operator*(int other) const{
    return this->field_value * other;
}
