#ifndef C_FREE_H
#define C_FREE_H

#include "Column.h"

class C_Free : Column{
public:

    C_Free() = default;


    C_Free(bool *announcement_ptr, Fields *field_announced_ptr)
            : Column(announcement_ptr, field_announced_ptr){}

    bool valid_order(Fields type_of_current) const override ;

    using Column::write_in_column;
    using Column::get_column;

private:

};



#endif