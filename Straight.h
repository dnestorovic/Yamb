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
        number_of_throws = -1;
    }

    bool valid_input(const std::vector<Dice>& input) const override ;
    void calculate_field_value(const std::vector<Dice>& selected_dices) override ;


    //FIXME define function that sets number_of_throws needed for calculate func
    //TODO move this field in private section ones the function is implemented(for now,
    // it stays in public section because of testing)
    // defines number of throws needed to get straight
    int number_of_throws;

    // TODO delete function after finished testing classes
    int get_field_value() const{
        return field_value;
    }


private:



};


#endif
