#include "Poker.h"

#include <numeric>

#include "Dice.h"

bool Poker::valid_input(const std::vector<Dice>& input) const {
  if (input.size() != 4) return false;

  Dice expected = input[0];
  for (const Dice& dice : input) {
    if (dice != expected) return false;
  }

  return true;
}
void Poker::calculate_field_value(const std::vector<Dice>& selected_dices) {
  if (not this->valid_input(selected_dices)) {
    field_value = 0;
  } else {
    int sum = std::accumulate(selected_dices.begin(), selected_dices.end(), 0);
    field_value = sum + 40;
  }
}
