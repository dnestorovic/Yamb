#ifndef C_FROMUP_H
#define C_FROMUP_H

#include <algorithm>
#include <vector>

#include "Column.h"
#include "F_Number.h"
#include "MinMax.h"

class C_FromUp : public Column {
 public:
    // Class constructors and override functions.
  C_FromUp() = default;
  C_FromUp(bool *announcement_ptr, Fields *field_announced_ptr,
           int *number_of_filled_columns);

  bool valid_order(Fields type) const override;
};

#endif
