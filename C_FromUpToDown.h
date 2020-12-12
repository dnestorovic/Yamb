#ifndef C_FROMUPTODOWN_H
#define C_FROMUPTODOWN_H

#include <vector>
#include <algorithm>

#include "Column.h"
#include "F_Number.h"
#include "MinMax.h"

// ALERT: if you need to test this class set public inheritance
class C_FromUpToDown : Column{
public:

    C_FromUpToDown() = default;
    bool valid_order(Fields type) const override ;

    using Column::write_in_column;
    using Column::get_column;


private:

};


#endif
