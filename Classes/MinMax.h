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
    int get_field_value() const;
    void calculate_field_value(const std::vector<Dice>& selected_dices) override ;

    // we simplify arithmetic for MinMax fields
    using Field::operator+;
    using Field::operator==;
    using Field::operator!=;
    using Field::operator=;

    int operator-(const MinMax& other) const;
    int operator*(int other) const;


private:
    // this function should be private because we need it just in this class
    bool valid_input(const std::vector<Dice>& input) const override;
};

#endif
