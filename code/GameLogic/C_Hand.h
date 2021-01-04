#ifndef JAMB_HAND_H
#define JAMB_HAND_H

#include "Column.h"

class C_Hand : public Column {
 public:
  C_Hand() = default;
  C_Hand(bool *announcement_ptr, Fields *field_announced_ptr,
         int *number_of_filled_columns);

  bool valid_order(Fields type) const override;
};

#endif