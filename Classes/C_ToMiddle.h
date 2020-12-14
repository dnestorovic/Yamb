#ifndef C_TOMIDDLE_H
#define C_TOMIDDLE_H

#include "Column.h"

class C_ToMiddle : Column{

public:

    C_ToMiddle() = default;
    bool valid_order(Fields type_of_current) const override ;

    using Column::write_in_column;
    using Column::get_column;

};

#endif