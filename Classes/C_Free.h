#ifndef C_FREE_H
#define C_FREE_H

#include "Column.h"

class C_Free : Column{
public:

    C_Free() = default;


    C_Free(bool *announcement_ptr, Fields *field_announced_ptr, int* number_of_filled_columns)
            : Column(announcement_ptr, field_announced_ptr, number_of_filled_columns){}

    bool valid_order(Fields type_of_current) const override ;

    using Column::write_in_column;
    using Column::get_column;
    using Column::column_full_filled;


private:

};



#endif