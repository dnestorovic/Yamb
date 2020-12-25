#ifndef STRAIGHT_H
#define STRAIGHT_H

#include "Field.h"

class Straight : Field{

public:

    // just say that we use overlapped operators from the above class
    using Field::operator+;
    using Field::operator==;
    using Field::operator!=;
    using Field::operator=;

    Straight(){
        field_value = -1;
    }

    bool valid_input(const std::vector<Dice>& input) const override ;
    void calculate_field_value(const std::vector<Dice>& selected_dices) override ;
    void calculate_field_value(const std::vector<Dice>& selected_dices, int number_of_throws) ;


    // TODO delete function after finished testing classes
    int get_field_value() const{
        return field_value;
    }


private:



};


#endif
