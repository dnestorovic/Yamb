#ifndef INC_14_JAMB_COLUMN_H
#define INC_14_JAMB_COLUMN_H

#include "MinMax.h"
#include "Straight.h"
#include "Three_of_a_kind.h"
#include "Full.h"
#include "Poker.h"
#include "Yamb.h"

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

    virtual bool valid_order(int current_field) const = 0;
    virtual int calculate_upper_sum() const = 0;
    virtual int calculate_middle_sum() const = 0;
    virtual int calculate_lower_sum() const = 0;

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
