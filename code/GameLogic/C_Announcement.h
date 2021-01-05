#ifndef C_ANNOUNCEMENT_H
#define C_ANNOUNCEMENT_H

#include "Column.h"

class C_Announcement : public Column {
 public:
  // Class constructors and override functions.
  C_Announcement() = default;
  C_Announcement(bool *announcement_ptr, Fields *field_announced_ptr,
                 int *number_of_filled_columns);

  bool valid_order(Fields type_of_current) const override;
};

#endif
