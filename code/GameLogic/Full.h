#ifndef JAMB_FULL_H
#define JAMB_FULL_H

#include "Dice.h"
#include "Field.h"

class Full : public Field {
 public:
  // Constructor and override functions.
  Full() { field_value = -1; }

  bool valid_input(const std::vector<Dice>& input) const override;
  void calculate_field_value(const std::vector<Dice>& selected_dices) override;
};

#endif