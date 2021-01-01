#include "C_FromMiddle.h"

C_FromMiddle::C_FromMiddle(bool *announcement_ptr, Fields *field_announced_ptr,
                           int *number_of_filled_columns)
    : Column(announcement_ptr, field_announced_ptr, number_of_filled_columns) {}

// valid order for this column is from the top to the bottom
bool C_FromMiddle::valid_order(Fields type_of_current) const {
  /*********Rules*******************
   * ->Min and Max fields can be filled if it wasn't filled previously
   * ->Upper part of column can be filled if the lower field was filled
   * ->Bottom part of column can be filled if the field above was filled
   * ! Field has value -1 if it wasn't filled yet !
   * *******************************/

  switch (type_of_current) {
    case Fields::Number_1: {
      // if the first field wasn't filled, we can fill it
      return upper_column[1] != -1 and upper_column[0] == -1;
    }
    case Fields::Number_2: {
      return upper_column[2] != -1 and upper_column[1] == -1;
    }
    case Fields::Number_3: {
      return upper_column[3] != -1 and upper_column[2] == -1;
    }
    case Fields::Number_4: {
      return upper_column[4] != -1 and upper_column[3] == -1;
    }
    case Fields::Number_5: {
      return upper_column[5] != -1 and upper_column[4] == -1;
    }
    case Fields::Number_6: {
      return max != -1 and upper_column[5] == -1;
    }
    case Fields::Maximum: {
      return max == -1;
    }
    case Fields::Minimum: {
      return min == -1;
    }
    case Fields::Straight: {
      return min != -1 and straight == -1;
    }
    case Fields::ThreeOfAKind: {
      return straight != -1 and three_of_a_kind == -1;
    }
    case Fields::Full: {
      return three_of_a_kind != -1 and full == -1;
    }
    case Fields::Poker: {
      return full != -1 and poker == -1;
    }
    case Fields::Yamb: {
      return poker != -1 and yamb == -1;
    }
    default: {
      std::cerr << "This should never happen";
      return false;
    }
  }
}
