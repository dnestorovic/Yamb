#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include "Dice.h"

enum class Fields {
    Number_1, Number_2, Number_3, Number_4, Number_5, Number_6,
    Maximum, Minimum,
    Straight, ThreeOfAKind, Full, Poker, Yamb,
    None //extra field that helps with announcement
};

// class that acts like an interface
class Field {
public:
    // functions that we need to implement in every field
    virtual bool valid_input(const std::vector<Dice>& input) const = 0;
    virtual void calculate_field_value(const std::vector<Dice>& selected_dices) = 0;

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

    static Fields row_to_enum(int8_t row)
    {
        Fields field;

        switch (row)
        {
            case 0:
                field = Fields::Number_1;
                break;
            case 1:
                field = Fields::Number_2;
                break;
            case 2:
                field = Fields::Number_3;
                break;
            case 3:
                field = Fields::Number_4;
                break;
            case 4:
                field = Fields::Number_5;
                break;
            case 5:
                field = Fields::Number_6;
                break;
            case 7:
                field = Fields::Maximum;
                break;
            case 8:
                field = Fields::Minimum;
                break;
            case 10:
                field = Fields::Straight;
                break;
            case 11:
                field = Fields::ThreeOfAKind;
                break;
            case 12:
                field = Fields::Full;
                break;
            case 13:
                field = Fields::Poker;
                break;
            case 14:
                field = Fields::Yamb;
                break;
            default:
                std::cerr << "Failed enum conversion" << std::endl;
        }

        return field;
    }

protected:
    // here we store value of the field
    int field_value;
};

#endif
