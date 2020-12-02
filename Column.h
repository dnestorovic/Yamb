#ifndef INC_14_JAMB_COLUMN_H
#define INC_14_JAMB_COLUMN_H

#include "MinMax.h"
#include "Straight.h"
#include "Three_of_a_kind.h"
#include "Full.h"
#include "Poker.h"
#include "Yamb.h"

enum class Column_part{
    Upper, Middle, Lower
};

enum class Fields{
    Number_1, Number_2, Number_3, Number_4, Number_5, Number_6,
    Maximum, Minimum,
    Straight, Three_of_a_kind, Full, Poker, Yamb
};

// class that acts like an interface
class Column{
public:

    Column(){

        // initialize upper part of column
        for(int i = 0; i < 6; i++){
            F_Number tmp(i + 1);
            upper_column.push_back(tmp);
        }

        // initialize middle part of column
        min = MinMax();
        max = MinMax();

        //initialize bottom part of column
        straight = Straight();
        three_of_a_kind = ThreeOfAKind();
        full = Full();
        poker = Poker();
        yamb = Yamb();


    }

    // function that should be overriden
    virtual bool valid_order(Fields type) const = 0;


    int calculate_upper_sum() const;
    int calculate_middle_sum() const;
    int calculate_lower_sum() const;
    bool check_if_filled(Column_part part) const;

//FIXME uncomment protected section after finish testing
//protected:

    // every field has it's own logic if it is correctly filled
    std::vector<F_Number> upper_column;
    MinMax max;
    MinMax min;
    Straight straight;
    ThreeOfAKind three_of_a_kind;
    Full full;
    Poker poker;
    Yamb yamb;


};

#endif
