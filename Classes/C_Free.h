#ifndef C_FREE_H
#define C_FREE_H

#include "Column.h"

class C_Free : public Column{
public:
    C_Free() = default;
    C_Free(bool *announcement_ptr, Fields *field_announced_ptr, int* number_of_filled_columns);

    bool valid_order(Fields type_of_current) const override;
};

#endif