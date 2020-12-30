#ifndef C_MAXIMUM_H
#define C_MAXIMUM_H

#include "Column.h"

// ALERT: if you need to test this class set public inheritance
class C_Maximum : public Column {
 public:
  C_Maximum() = default;
  C_Maximum(bool *announcement_ptr, Fields *field_announced_ptr,
            int *number_of_filled_columns);

  bool valid_order(Fields type) const override;
};

#endif
