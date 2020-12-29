#ifndef INC_14_JAMB_C_MAXIMUM_H
#define INC_14_JAMB_C_MAXIMUM_H

#include "Column.h"

// ALERT: if you need to test this class set public inheritance
class C_Maximum : public Column{
public:

    C_Maximum() = default;

    C_Maximum(bool *announcement_ptr, Fields *field_announced_ptr, int *number_of_filled_columns)
            : Column(announcement_ptr, field_announced_ptr, number_of_filled_columns){}

    bool valid_order(Fields type) const override ;

    using Column::write_in_column;
    using Column::get_column;
    using Column::column_full_filled;


private:

};


#endif
