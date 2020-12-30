#include "Straight.h"

#include <algorithm>
#include <functional>
#include <set>

bool Straight::valid_input(const std::vector<Dice>& input) const {
  std::set<Dice> set_of_dices;

  for (const auto& dice : input) {
    set_of_dices.insert(dice);
  }

  // here we assume that we have 5 different dices but we also need to know if
  // the dices are in range 1-5 or 2-6
  Dice max = *(std::max_element(set_of_dices.cbegin(), set_of_dices.cend()));
  Dice min = *(std::min_element(set_of_dices.cbegin(), set_of_dices.cend()));

  // so if the range distance between max and min dice is not 4 we don't have
  // correct range of dices
  if (max.get_value() - min.get_value() != 4) return false;

  // check if there are 5 dices in set
  return 5 == set_of_dices.size();
}

void Straight::calculate_field_value(const std::vector<Dice>& selected_dices) {
  // This function is not proper for Straight field so we use the function below
}

void Straight::calculate_field_value(const std::vector<Dice>& selected_dices,
                                     int number_of_throws) {
  if (!valid_input(selected_dices)) {
    field_value = 0;
  } else {
    // if we select correct dices, number of throws defines value of field
    switch (number_of_throws) {
      case 1: {
        field_value = 66;
        break;
      }
      case 2: {
        field_value = 56;
        break;
      }
      case 3: {
        field_value = 46;
        break;
      }
      default:
        std::cout << "This should never happen" << std::endl;
    }
  }
}
