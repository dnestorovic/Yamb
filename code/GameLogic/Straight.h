#ifndef STRAIGHT_H
#define STRAIGHT_H

#include "Field.h"

class Straight : public Field {
 public:
  // Constructor and override functions.
  Straight() { field_value = -1; }

  bool valid_input(const std::vector<Dice>& input) const override;
  void calculate_field_value(const std::vector<Dice>& selected_dices) override;
  // This function for field value should be different than in other fields
  // because straight depends on number of throws.
  void calculate_field_value(const std::vector<Dice>& selected_dices,
                             int number_of_throws);
};

#endif
