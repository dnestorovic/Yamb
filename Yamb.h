#ifndef YAMB_H
#define YAMB_H

#include "Field.h"

class Yamb : Field {

public:

    Yamb(){
        field_value = -1;
    }

    bool valid_input(const std::vector<Dice>& input) const override ;
    void calculate_field_value(const std::vector<Dice>& selected_dices) override ;



};



#endif
