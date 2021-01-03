#include "C_Announcement.h"

C_Announcement::C_Announcement(bool *announcement_ptr,
                               Fields *field_announced_ptr,
                               int *number_of_filled_columns)
    : Column(announcement_ptr, field_announced_ptr, number_of_filled_columns) {}

bool C_Announcement::valid_order(Fields type_of_current) const {
  /*********Rules*******************
   * -> Fields can be filled in any order if the value of current field is -1
   * -> Player must announce that wants to play some move at the begin
   * *******************************/

  if (!(*announce)) {
    return false;
  }

  switch (type_of_current) {
    case Fields::Number_1: {
      if (*field_announced == Fields::Number_1)
        return upper_column[0] == -1;
      else
        return false;
    }
    case Fields::Number_2: {
      if (*field_announced == Fields::Number_2)
        return upper_column[1] == -1;
      else
        return false;
    }
    case Fields::Number_3: {
      if (*field_announced == Fields::Number_3)
        return upper_column[2] == -1;
      else
        return false;
    }
    case Fields::Number_4: {
      if (*field_announced == Fields::Number_4)
        return upper_column[3] == -1;
      else
        return false;
    }
    case Fields::Number_5: {
      if (*field_announced == Fields::Number_5)
        return upper_column[4] == -1;
      else
        return false;
    }
    case Fields::Number_6: {
      if (*field_announced == Fields::Number_6)
        return upper_column[5] == -1;
      else
        return false;
    }
    case Fields::Maximum: {
      if (*field_announced == Fields::Maximum)
        return max == -1;
      else
        return false;
    }
    case Fields::Minimum: {
      if (*field_announced == Fields::Minimum)
        return min == -1;
      else
        return false;
    }
    case Fields::Straight: {
      if (*field_announced == Fields::Straight)
        return straight == -1;
      else
        return false;
    }
    case Fields::ThreeOfAKind: {
      if (*field_announced == Fields::ThreeOfAKind)
        return three_of_a_kind == -1;
      else
        return false;
    }
    case Fields::Full: {
      if (*field_announced == Fields::Full)
        return full == -1;
      else
        return false;
    }
    case Fields::Poker: {
      if (*field_announced == Fields::Poker)
        return poker == -1;
      else
        return false;
    }
    case Fields::Yamb: {
      if (*field_announced == Fields::Yamb)
        return yamb == -1;
      else
        return false;
    }
    default: {
      return false;
    }
  }
}
