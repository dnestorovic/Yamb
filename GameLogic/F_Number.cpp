#include "F_Number.h"

// function that checks if the selected dices are valid for this type of field
bool F_Number::valid_input(const std::vector<Dice>& input) const {
  // if we find some selected value that we didn't expect, we return false
  for (const auto& dice : input) {
    if (dice.get_value() != expected_value) {
      return false;
    }
  }

  return true;
}

// function that calculates sum of the selected dices
void F_Number::calculate_field_value(const std::vector<Dice>& selected_dices) {
  // but first we check if the selected dices are valid for this type of field
  if (not valid_input(selected_dices)) {
    std::cerr << "You select some invalid dice for this field "
              << expected_value << std::endl;
    field_value = 0;
    return;
  }

  // if everything is alright...
  int sum = 0;
  for (const auto& dice : selected_dices) {
    sum += expected_value;
  }

  field_value = sum;
}
