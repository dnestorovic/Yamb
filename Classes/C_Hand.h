#ifndef JAMB_HAND_H
#define JAMB_HAND_H

#include "Column.h"

class C_Hand : Column{

public:

    C_Hand() = default;
    bool valid_order(Fields type) const override;

    using Column::write_in_column;
    using Column::get_column;

};


#endif