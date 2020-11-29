#ifndef MINMAX_H
#define MINMAX_H

#include "Field.h"
#include "F_Number.h"

class MinMax : Field{
public:

    MinMax()
    {
        field_value = -1;
    }

    // function that we need to override
    void calculate_field_value(const std::vector<Dice>& selected_dices) override ;


    // we simplify arithmetic for MinMax fields
    bool operator-(const MinMax& other) const;
    bool operator+(int other) const;
    bool operator*(int other) const;



private:
    // this function should be private because we need it just in this class
    bool valid_input(const std::vector<Dice>& input) const override ;


};

#endif
