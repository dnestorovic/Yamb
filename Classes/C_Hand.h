#ifndef JAMB_HAND_H
#define JAMB_HAND_H

#include "Column.h"

class C_Hand : Column{

public:

    C_Hand() = default;

    C_Hand(bool *announcement_ptr, Fields *field_announced_ptr, int *number_of_filled_columns)
            : Column(announcement_ptr, field_announced_ptr, number_of_filled_columns){}

    bool valid_order(Fields type) const override;

    using Column::write_in_column;
    using Column::get_column;
    using Column::column_full_filled;


};


#endif