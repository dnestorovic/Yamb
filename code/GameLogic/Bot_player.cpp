#include "Bot_player.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>

#include "Dice.h"

/*Bot player can be implemented in some later versions of the game.*/
std::vector<Dice> BotPlayer::throw_dices(std::istream& s) {
  std::vector<Dice> dices;

  int value;
  for (int i = 0; i < number_of_dices; i++) {
    s >> value;
    dices.emplace_back(value);
  }

  return dices;
}

std::vector<Dice> BotPlayer::select_dices(std::vector<Dice> dices,
                                          std::vector<int> positions){ };

bool BotPlayer::write_on_ticket(std::vector<Dice> dices, Fields field,
                                Columns column, int number_of_throws) { }

bool BotPlayer::announce(Fields field) { }

void BotPlayer::respond_announce() { }

// Function that defines order how bot player should fill ticket columns.
void BotPlayer::calculate_priority() {
  int number_of_fields = 13;

  ////IF ANYTHING WAS ANNOUNCED THAT HAS TOP PRIORITY BY THE RULES OF THE GAME.

  // Everything from hand is top priority.
  for (int i = 0; i < number_of_fields; i++) {
    priority_for_play.emplace_back(i, 4);
  }

  // Max column has second priority.
  // Lower fields have higher priority.
  for (int i = number_of_fields; i > 0; i--) {
    priority_for_play.emplace_back(i, 9);
  }

  // Announce column has third priority.
  // Lower fields have higher priority.
  for (int i = number_of_fields; i > 0; i--) {
    priority_for_play.emplace_back(i, 3);
  }

  // Column from_up has fourth priority.
  // By the rules of the game, upper fields have higher priority.
  for (int i = 0; i < number_of_fields; i++) {
    priority_for_play.emplace_back(i, 0);
  }

  // Column from_bottom has fifth priority.
  // By the rules of the game, lower fields have higher priority.
  for (int i = number_of_fields; i > 0; i--) {
    priority_for_play.emplace_back(i, 2);
  }

  // Column from_middle has sixth priority.
  // Lower fields have higher priority.
  //// It must be check if the player can play some move by the rules of the
  ///game for this column.
  for (int i = number_of_fields; i > 0; i--) {
    priority_for_play.emplace_back(i, 6);
  }

  // Column to_middle has seventh priority.
  // Lower fields have higher priority.
  for (int i = number_of_fields; i > 0; i--) {
    priority_for_play.emplace_back(i, 7);
  }

  // Free has lowest priority.
  // Lower fields have higher priority.
  for (int i = number_of_fields; i > 0; i--) {
    priority_for_play.emplace_back(i, 1);
  }
}


// Because of gui implementation, ticket is presented as matrix but in backend, ticket
// is presented with many columns that contains fields, so this function adjusts gui
// style of ticket to backend type.
std::pair<Columns, Fields> BotPlayer::convert_priority_to_enum(
    std::pair<int, int> coordinates) const {
  int i = coordinates.first;
  int j = coordinates.second;

  Fields field;
  Columns column;

  // Calculate field by index.
  switch (i) {
    case 0:
      field = Fields::Number_1;
      break;
    case 1:
      field = Fields::Number_2;
      break;
    case 2:
      field = Fields::Number_3;
      break;
    case 3:
      field = Fields::Number_4;
      break;
    case 4:
      field = Fields::Number_5;
      break;
    case 5:
      field = Fields::Number_6;
      break;
    case 6:
      field = Fields::Maximum;
      break;
    case 7:
      field = Fields::Minimum;
      break;
    case 8:
      field = Fields::Straight;
      break;
    case 9:
      field = Fields::ThreeOfAKind;
      break;
    case 10:
      field = Fields::Full;
      break;
    case 11:
      field = Fields::Poker;
      break;
    case 12:
      field = Fields::Yamb;
      break;
  }

  // Calculate column by index.
  switch (j) {
    case 0:
      column = Columns::FromUp;
      break;
    case 1:
      column = Columns::Free;
      break;
    case 2:
      column = Columns::FromBottom;
      break;
    case 3:
      column = Columns::Announcement;
      break;
    case 4:
      column = Columns::Hand;
      break;
    case 5:
      column = Columns::Respond;
      break;
    case 6:
      column = Columns::FromMiddle;
      break;
    case 7:
      column = Columns::ToMiddle;
      break;
    case 8:
      column = Columns::Checkout;
      break;
    case 9:
      column = Columns::Maximum;
      break;
  }

  return std::make_pair(column, field);
}

// Function that finds best move by priority and probability to get that field in future.
std::pair<Columns, Fields> BotPlayer::find_best_move(
    std::vector<Dice>& dices, double probability_tolerance) const {
  // Variables that bot uses.
  Fields field_for_play = Fields::None;
  Columns column_for_play = Columns::None;

  Fields field_tmp = Fields::None;
  Columns column_tmp = Columns::None;

  std::pair<Columns, Fields> tmp;

  // Find the best move by priority.
  for (const auto& should_play : priority_for_play) {
    // Convert coordinates to enum.
    tmp = convert_priority_to_enum(should_play);

    column_tmp = tmp.first;
    field_tmp = tmp.second;

    // Check if this move can be played by the rules of the column, and if the
    // field is not filled yet.
    if (!ticket.can_be_played(column_tmp, field_tmp)) continue;

    double proba = calculate_probability(field_tmp, dices);

    field_for_play = field_tmp;
    column_for_play = column_tmp;
  }

  return std::make_pair(column_for_play, field_for_play);
}

// Function that decides next move.
std::pair<Columns, Fields> BotPlayer::decide_next_move(
    std::vector<Dice>& dices) const {
  Fields field_for_play = Fields::None;
  Columns column_for_play = Columns::None;

  // Starting probability should be 0.99, because if bot already has something
  // to play probability for that move is 1 so he decides to play safe move.
  double probability_tolerance = 0.99;

  // Until bot decide what he can play, try to find move.
  while (field_for_play == Fields::None and column_for_play == Columns::None) {
    // Find the best possible move for current probability.
    std::pair<Columns, Fields> answer =
        find_best_move(dices, probability_tolerance);

    // Answer from the best move function.
    column_for_play = answer.first;
    field_for_play = answer.second;

    // If bot has no move to play we decrease required probability
    // and we give the bot a chance to find other move.
    if (field_for_play == Fields::None or column_for_play == Columns::None) {
      std::cout << "Bot hasn't decide yet what he can play" << std::endl;

      // Should decrease.
      probability_tolerance -= 0.1;
    }
  }

  return std::make_pair(column_for_play, field_for_play);
}

// Whole logic of bot next move is here.
void BotPlayer::play_next_move() {
  std::vector<Dice> dices = throw_dices(std::cin);

  // Which move should bot attempt to play.
  std::pair<Columns, Fields> next_move = decide_next_move(dices);

  // Select dices based on next move attempt.

  //// At the end we must delete played field from priority moves.
}

// Calculate binomial coefficients for given arguments.
int binomialCoeff(int n, int k) {
  int C[n + 1][k + 1];
  int i, j;

  // Calculate value of Binomial Coefficient
  // in bottom up manner.
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= std::min(i, k); j++) {
      // Base Cases
      if (j == 0 || j == i) C[i][j] = 1;

      // Calculate value using previously
      // stored values.
      else
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  return C[n][k];
}

/* **********************************************************
 * Calculate probability to get something based on dices.
 *
 * ->For the upper fields it is okay to have 3 or more of the same because in
 * that way bot will reach 60+ points in upper part of the column and get 30
 * extra points.
 *
 * ->For maximum it is okay if we can reach sum above 25.
 * ->For minimum it is okay if we can reach sum less then 8.
 *
 * ->For lower fields it is okay if we can fulfill the condition.
 * ***********************************************************/

// Calculate probability to get at least 3 of the same.
double probability_for_one(std::vector<Dice>& dices) {
  int num_of_wanted = 0;
  int num_of_rest = dices.size();

  // Calculate current situation.
  for (const auto& dice : dices) {
    if (dice.get_value() == 1) {
      num_of_wanted++;
      num_of_rest--;
    }
  }

  // If we already have wanted number of dices, probability to get it is 1.
  if (num_of_wanted >= 3) {
    return 1.0;
  }

  // Calculate probability to get 3 or more in next move.
  int dices_needed = 3 - num_of_wanted;
  double probability = 0.0;

  for (int i = dices_needed; i <= num_of_rest; i++) {
    probability += binomialCoeff(num_of_rest, i) * pow((1.0 / 6.0), i) *
                   pow((5.0 / 6.0), num_of_rest - i);
  }

  return probability;
}

// Calculate probability to get at least 3 of the same.
double probability_for_two(std::vector<Dice>& dices) {
  int num_of_wanted = 0;
  int num_of_rest = dices.size();

  // Calculate current situation.
  for (const auto& dice : dices) {
    if (dice.get_value() == 2) {
      num_of_wanted++;
      num_of_rest--;
    }
  }

  // If we already have wanted number of dices, probability to get it is 1.
  if (num_of_wanted >= 3) {
    return 1.0;
  }

  // Calculate probability to get 3 or more in next move.
  int dices_needed = 3 - num_of_wanted;
  double probability = 0.0;

  for (int i = dices_needed; i <= num_of_rest; i++) {
    probability += binomialCoeff(num_of_rest, i) * pow((1.0 / 6.0), i) *
                   pow((5.0 / 6.0), num_of_rest - i);
  }

  return probability;
}

// Calculate probability to get at least 3 of the same.
double probability_for_three(std::vector<Dice>& dices) {
  int num_of_wanted = 0;
  int num_of_rest = dices.size();

  // Calculate current situation.
  for (const auto& dice : dices) {
    if (dice.get_value() == 3) {
      num_of_wanted++;
      num_of_rest--;
    }
  }

  // If we already have wanted number of dices, probability to get it is 1.
  if (num_of_wanted >= 3) {
    return 1.0;
  }

  // Calculate probability to get 3 or more in next move.
  int dices_needed = 3 - num_of_wanted;
  double probability = 0.0;

  for (int i = dices_needed; i <= num_of_rest; i++) {
    probability += binomialCoeff(num_of_rest, i) * pow((1.0 / 6.0), i) *
                   pow((5.0 / 6.0), num_of_rest - i);
  }

  return probability;
}

// Calculate probability to get at least 3 of the same.
double probability_for_four(std::vector<Dice>& dices) {
  int num_of_wanted = 0;
  int num_of_rest = dices.size();

  // Calculate current situation.
  for (const auto& dice : dices) {
    if (dice.get_value() == 4) {
      num_of_wanted++;
      num_of_rest--;
    }
  }

  // If we already have wanted number of dices, probability to get it is 1.
  if (num_of_wanted >= 3) {
    return 1.0;
  }

  // Calculate probability to get 3 or more in next move.
  int dices_needed = 3 - num_of_wanted;
  double probability = 0.0;

  for (int i = dices_needed; i <= num_of_rest; i++) {
    probability += binomialCoeff(num_of_rest, i) * pow((1.0 / 6.0), i) *
                   pow((5.0 / 6.0), num_of_rest - i);
  }

  return probability;
}

// Calculate probability to get at least 3 of the same.
double probability_for_five(std::vector<Dice>& dices) {
  int num_of_wanted = 0;
  int num_of_rest = dices.size();

  // Calculate current situation.
  for (const auto& dice : dices) {
    if (dice.get_value() == 5) {
      num_of_wanted++;
      num_of_rest--;
    }
  }

  // If we already have wanted number of dices, probability to get it is 1.
  if (num_of_wanted >= 3) {
    return 1.0;
  }

  // Calculate probability to get 3 or more in next move.
  int dices_needed = 3 - num_of_wanted;
  double probability = 0.0;

  for (int i = dices_needed; i <= num_of_rest; i++) {
    probability += binomialCoeff(num_of_rest, i) * pow((1.0 / 6.0), i) *
                   pow((5.0 / 6.0), num_of_rest - i);
  }

  return probability;
}

// Calculate probability to get at least 3 of the same.
double probability_for_six(std::vector<Dice>& dices) {
  int num_of_wanted = 0;
  int num_of_rest = dices.size();

  // Calculate current situation.
  for (const auto& dice : dices) {
    if (dice.get_value() == 6) {
      num_of_wanted++;
      num_of_rest--;
    }
  }

  // If we already have wanted number of dices, probability to get it is 1.
  if (num_of_wanted >= 3) {
    return 1.0;
  }

  // Calculate probability to get 3 or more in next move.
  int dices_needed = 3 - num_of_wanted;
  double probability = 0.0;

  for (int i = dices_needed; i <= num_of_rest; i++) {
    probability += binomialCoeff(num_of_rest, i) * pow((1.0 / 6.0), i) *
                   pow((5.0 / 6.0), num_of_rest - i);
  }

  return probability;
}

double probability_for_max(std::vector<Dice>& dices) {
  // We aim to play with 5 and 6 only as long as we can
  // at the end of the move if we don't have sum above 25 we will decide what to
  // play with the dices we currently have.
  int sum = 0;
  int num_of_rest = dices.size();

  // Calculate current situation.
  for (const auto& dice : dices) {
    if (dice.get_value() == 6) {
      num_of_rest--;
      sum += 6;
    }

    if (dice.get_value() == 5) {
      num_of_rest--;
      sum += 5;
    }
  }

  // If we already have wanted sum of dices, probability to get it is 1.
  if (sum >= 25) {
    return 1.0;
  }

  // Calculate probability to reach sum above 25 with the rest of the dices.
  double probability = 0.0;

  for (int i = 0; i <= num_of_rest; i++) {
    // Probability to get 5 is 1/6.
    // Probability to get 6 is 1/6.
    // Probability to get all 5 from the rest is (1/6)^num_of_rest.
    // Probability to get all 6 from the rest is (1/6)^(num_of_rest -
    // num_of_fives) at the end probability to reach sum of 25 is equal to
    // probability of getting all 5, or some 5 and some 6, or all 6.
    probability += pow((1.0 / 6.0), num_of_rest - i) * pow((1.0 / 6.0), i) *
                   binomialCoeff(num_of_rest, i);
  }

  return probability;
}

// It is okay that we get minimum less then 8.
double probability_for_min(std::vector<Dice>& dices) {
  // We aim to play minimum with only 1 and 2 as long as we can
  // when we don't have other choice we will decide what we play with dices that
  // we currently have.
  int sum = 0;
  int num_of_rest = dices.size();

  // Calculate current situation.
  for (const auto& dice : dices) {
    if (dice.get_value() == 1) {
      num_of_rest--;
      sum += 1;
    }

    if (dice.get_value() == 2) {
      num_of_rest--;
      sum += 2;
    }
  }

  // If we already have wanted sum of dices, probability to get it is 1.
  if (sum <= 8) {
    return 1.0;
  }

  // Calculate probability to reach sum less then 8 with the rest of the dices.
  double probability = 0.0;

  for (int i = 0; i <= num_of_rest; i++) {
    // The formula have been explained earlier in the code when we describe how
    // we calculate probability to get some dices for maximum.
    probability += pow((1.0 / 6.0), num_of_rest - i) * pow((1.0 / 6.0), i) *
                   binomialCoeff(num_of_rest, i);
  }

  return probability;
}

double probability_for_straight(std::vector<Dice>& dices) {
  std::set<Dice> straight_set;

  for (const auto& dice : dices) {
    straight_set.insert(dice);
  }

  // If we already have straight probability to get straight is 1.0
  // straight must have 5 dices and it will be in range [1,5] or [2,6]
  // so the distance between first and last dice value must be 4.
  if (straight_set.size() == 5) {
    if (straight_set.cend()->get_value() - straight_set.cbegin()->get_value() ==
        4)
      return 1.0;
  }

  // Calculate probability to get straight with the rest of the dices.
  unsigned num_of_rest = dices.size() - straight_set.size();
  double probability = pow((1.0 / 6.0), num_of_rest);

  return probability;
}

double probability_for_tok(std::vector<Dice>& dices) {}

double probability_for_full(std::vector<Dice>& dices) {}

double probability_for_poker(std::vector<Dice>& dices) {}

double probability_for_yamb(std::vector<Dice>& dices) {}

// Calculates probability based on field that can be play and dices that bot
// currently has.
double BotPlayer::calculate_probability(Fields field,
                                        std::vector<Dice>& dices) const {
  switch (field) {
    case Fields::Number_1:
      return probability_for_one(dices);
    case Fields::Number_2:
      return probability_for_two(dices);
    case Fields::Number_3:
      return probability_for_three(dices);
    case Fields::Number_4:
      return probability_for_four(dices);
    case Fields::Number_5:
      return probability_for_five(dices);
    case Fields::Number_6:
      return probability_for_six(dices);
    case Fields::Maximum:
      return probability_for_max(dices);
    case Fields::Minimum:
      return probability_for_min(dices);
    case Fields::Straight:
      return probability_for_straight(dices);
    case Fields::ThreeOfAKind:
      return probability_for_tok(dices);
    case Fields::Full:
      return probability_for_full(dices);
    case Fields::Poker:
      return probability_for_poker(dices);
    case Fields::Yamb:
      return probability_for_yamb(dices);
    case Fields::None:
      break;
  }
}
