#ifndef POKER_H
#define POKER_H

#include "Field.h"

class Poker : public Field {
 public:
    // Constructor and override functions.

    Poker() { field_value = -1; }

  bool valid_input(const std::vector<Dice>& input) const override;
  void calculate_field_value(const std::vector<Dice>& selected_dices) override;
};

#endif
