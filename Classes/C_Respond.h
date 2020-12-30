#ifndef INC_14_JAMB_C_ANNOUNCEMENTRESPOND_H
#define INC_14_JAMB_C_ANNOUNCEMENTRESPOND_H

#include "Column.h"

class C_Respond : public Column{
public:
    C_Respond() = default;
    C_Respond(bool *announcement_ptr, Fields *field_announced_ptr, int *number_of_filled_columns);

    bool valid_order(Fields type_of_current) const override;
};

#endif