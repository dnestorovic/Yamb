#ifndef C_TOMIDDLE_H
#define C_TOMIDDLE_H

#include "Column.h"

class C_ToMiddle : Column{

public:

    C_ToMiddle() = default;

    C_ToMiddle(bool *announcement_ptr, Fields *field_announced_ptr)
            : Column(announcement_ptr, field_announced_ptr){}

    bool valid_order(Fields type_of_current) const override ;

    using Column::write_in_column;
    using Column::get_column;

};

#endif