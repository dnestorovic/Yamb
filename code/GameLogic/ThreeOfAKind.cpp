#include "ThreeOfAKind.h"

// Check if input is valid for three of a kind.
bool ThreeOfAKind::valid_input(const std::vector<Dice>& input) const {
  if (input.size() != 3) {
    return false;
  }

  Dice expected = input[0];
  for (const auto& dice : input) {
    if (dice != expected) {
      return false;
    }
  }

  return true;
}

// If everything is alright calculate field value.
void ThreeOfAKind::calculate_field_value(
    const std::vector<Dice>& selected_dices) {
  if (not this->valid_input(selected_dices))
    field_value = 0;
  else
    field_value = 3 * selected_dices[0].get_value() + 20;
}
