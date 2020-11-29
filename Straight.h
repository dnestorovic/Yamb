#ifndef STRAIGHT_H
#define STRAIGHT_H

#include "Field.h"

class Straight : Field{

public:

    Straight(){
        field_value = -1;
        number_of_throws = -1;
    }

    bool valid_input(const std::vector<Dice>& input) const override ;
    void calculate_field_value(const std::vector<Dice>& selected_dices) override ;


    //FIXME define function that sets number_of_throws needed for calculate func

private:
    // defines number of throws needed to get straight
    int number_of_throws;



};


#endif
