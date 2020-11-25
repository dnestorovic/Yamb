#include <numeric>
#include <iostream>
#include "C_FromUpToDown.h"

// valid order for this column is from the top to the bottom
bool C_FromUpToDown::valid_order(int current_field) const{

    // just checks if the field above is filled
    if(current_field == 0)
        return true;
    else
        return upper_column[current_field - 1] == -1;

}


int C_FromUpToDown::calculate_upper_sum() const{

    // if the last field has been filed
    if(upper_column[5] != -1){

        //FIXME
        //return std::accumulate(upper_column.cbegin(), upper_column.cend(), 0);
        // should use accumulate but for now let just use loop
        int sum = 0;
        for(const auto& x : upper_column){
            sum = x + sum;
        }

        // this is a rule for upper sums
        if(sum >= 60)
            sum += 30;

        return sum;

    } else{
        std::cout << "To calculate sum of upper part of column, please fill all fields"
                  << " from upper part of column" << std::endl;

        return -1;
    }

}

// function that calculates middle sum
int C_FromUpToDown::calculate_middle_sum() const{

    // this is a rule for calculating middle sums
    return (max - min) * upper_column[0].get_field_value();

}



int C_FromUpToDown::calculate_lower_sum() const{

    //TODO

}

