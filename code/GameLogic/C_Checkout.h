#ifndef INC_14_JAMB_C_CHECKOUT_H
#define INC_14_JAMB_C_CHECKOUT_H

#include "Column.h"


class C_Checkout : public Column {
 public:
    // Class constructors and override functions.
  C_Checkout() = default;
  C_Checkout(bool *announcement_ptr, Fields *field_announced_ptr,
             int *number_of_filled_columns);

  bool valid_order(Fields type) const override;
};

#endif
