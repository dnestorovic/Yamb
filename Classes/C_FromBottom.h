#ifndef C_FROMBOTTOM_H
#define C_FROMBOTTOM_H

#include "Column.h"

class C_FromBottom : public Column {
 public:
  C_FromBottom() = default;
  C_FromBottom(bool *announcement_ptr, Fields *field_announced_ptr,
               int *number_of_filled_columns);

  bool valid_order(Fields type) const override;
};

#endif