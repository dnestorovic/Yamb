#include "MinMax.h"

#include <numeric>

// function that checks whatever we use valid input values or not
bool MinMax::valid_input(const std::vector<Dice>& input) const {
  // the only condition is that we select 5 dices
  return input.size() == 5;
}

// function that calculates value of the field
void MinMax::calculate_field_value(const std::vector<Dice>& selected_dices) {
  if (not valid_input(selected_dices)) {
    // Need to select 5 dices to play this move.
    return;
  }

  int sum = std::accumulate(selected_dices.begin(), selected_dices.end(), 0);
  field_value = sum;
}
