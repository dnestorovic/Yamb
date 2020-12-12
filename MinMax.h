#ifndef MINMAX_H
#define MINMAX_H

#include "Field.h"
#include "F_Number.h"

class MinMax : Field{
public:

    // just say that we use overlapped operator from the above class
    using Field::operator+;

    MinMax()
    {
        field_value = -1;
    }

    // function that we need to override
    void calculate_field_value(const std::vector<Dice>& selected_dices) override ;


    // we simplify arithmetic for MinMax fields
    using Field::operator==;
    using Field::operator!=;
    using Field::operator=;
    bool operator-(const MinMax& other) const;
    bool operator*(int other) const;

    int get_field_value() const{
        return field_value;
    }



private:
    // this function should be private because we need it just in this class
    bool valid_input(const std::vector<Dice>& input) const override ;


};

#endif
