#ifndef C_FROMUPTODOWN_H
#define C_FROMUPTODOWN_H

#include <vector>
#include <algorithm>

#include "Column.h"
#include "F_Number.h"
#include "MinMax.h"

class C_FromUpToDown : Column{
public:

    C_FromUpToDown(){

        // initialize upper part of column
        for(int i = 0; i < 6; i++){
            F_Number tmp(i + 1);
            upper_column.push_back(tmp);
        }

        // initialize middle part of column
        min = MinMax();
        max = MinMax();

    }

    bool valid_order(int next_field) const override ;
    int calculate_upper_sum() const override ;
    int calculate_middle_sum() const override ;
    int calculate_lower_sum() const override ;



private:

    // every field has it's own logic if it is correctly filled
    std::vector<F_Number> upper_column;
    MinMax max;
    MinMax min;
    // TODO rest of the fields
//    Straight straight;
//    ThreeOfKind three_of_kind;
//    Full full;
//    Poker poker;
//    Yamb yamb;
//

};


#endif
