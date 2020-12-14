#ifndef INC_14_JAMB_ANNOUNCEMENT_H
#define INC_14_JAMB_ANNOUNCEMENT_H


#include "Column.h"

class C_Announcement : Column{
public:

    C_Announcement() = default;


    C_Announcement(bool *announcement_ptr, Fields *field_announced_ptr)
            : Column(announcement_ptr, field_announced_ptr){}

    bool valid_order(Fields type_of_current) const override ;

    using Column::write_in_column;
    using Column::get_column;

private:

};

#endif
