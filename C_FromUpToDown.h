#ifndef C_FROMUPTODOWN_H
#define C_FROMUPTODOWN_H

#include <vector>
#include <algorithm>

#include "Column.h"
#include "F_Number.h"
#include "MinMax.h"

class C_FromUpToDown : Column{
public:

    C_FromUpToDown()= default;

    bool valid_order(int next_field) const override ;
    int calculate_upper_sum() const override ;
    int calculate_middle_sum() const override ;
    int calculate_lower_sum() const override ;



private:

};


#endif
