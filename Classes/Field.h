#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include "Dice.h"

// class that acts like an interface
class Field{

public:

    // functions that we need to implement in every field
    virtual bool valid_input(const std::vector<Dice>& input) const = 0;
    virtual void calculate_field_value(const std::vector<Dice>& selected_dices) = 0;;

    // operators that we use in same way in every field
    Field& operator=(int other){
        this->field_value = other;
        return *this;
    }

    int operator+(int other) const{
        return field_value + other;
    }

    bool operator==(int other) const{
        return field_value == other;
    }

    bool operator!=(int other) const{
        return field_value != other;
    }


protected:
    // here we store value of the field
    int field_value;

};

#endif
