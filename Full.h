#ifndef JAMB_FULL_H
#define JAMB_FULL_H

#include "Field.h"
#include "Dice.h"

class Full : Field{

public:

    Full(){
        field_value = -1;
    }

    bool valid_input(const std::vector<Dice>& input) const override ;
    void calculate_field_value(const std::vector<Dice>& selected_dices) override;


};


#endif