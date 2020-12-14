#ifndef C_FROMMIDDLE_H
#define C_FROMMIDDLE_H

#include "Column.h"

class C_FromMiddle : Column{

public:

    C_FromMiddle() = default;


    C_FromMiddle(bool *announcement_ptr, Fields *field_announced_ptr)
            : Column(announcement_ptr, field_announced_ptr){}

    bool valid_order(Fields type_of_current) const override ;

    using Column::write_in_column;
    using Column::get_column;

};

#endif