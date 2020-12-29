#ifndef C_FROMUPTODOWN_H
#define C_FROMUPTODOWN_H

#include <vector>
#include <algorithm>

#include "Column.h"
#include "F_Number.h"
#include "MinMax.h"

// ALERT: if you need to test this class set public inheritance
class C_FromUpToDown : public Column{
public:
    C_FromUpToDown() = default;

    C_FromUpToDown(bool *announcement_ptr, Fields *field_announced_ptr, int *number_of_filled_columns)
                    : Column(announcement_ptr, field_announced_ptr, number_of_filled_columns){}

    bool valid_order(Fields type) const override ;

    using Column::write_in_column;
    using Column::get_column;
    using Column::column_full_filled;
};


#endif
