#include "Ticket.h"

Ticket::Ticket() {}

// Calculate sum of all parts of the ticket.
std::tuple<int, int, int> Ticket::calculate_column_sum(Columns col) {
  std::tuple<int, int, int> col_sum;

  switch (col) {
    case Columns::FromUp:
      col_sum = from_up.calculate_sum();
      break;
    case Columns::Free:
      col_sum = free.calculate_sum();
      break;
    case Columns::FromBottom:
      col_sum = from_bottom.calculate_sum();
      break;
    case Columns::Announcement:
      col_sum = announcement.calculate_sum();
      break;
    case Columns::Hand:
      col_sum = hand.calculate_sum();
      break;
    case Columns::Respond:
      col_sum = respond.calculate_sum();
      break;
    case Columns::FromMiddle:
      col_sum = from_middle.calculate_sum();
      break;
    case Columns::ToMiddle:
      col_sum = to_middle.calculate_sum();
      break;
    case Columns::Checkout:
      col_sum = checkout.calculate_sum();
      break;
    case Columns::Maximum:
      col_sum = maximum.calculate_sum();
      break;
    default:
      break;
  }

  return col_sum;
}

// Get ticket state column by column.
std::vector<std::vector<int>> Ticket::get_ticket_value() {
  int number_of_fields = 13;

  std::vector<std::vector<int>> status;

  // Resizing matrix to number_of_fields x number_of_columns.
  status.resize(number_of_fields);

  // We iterate thought all fields and and we fill row by row using value of
  // that field in each column.
  for (int i = 0; i < number_of_fields; i++) {
    // Get value of i field from each column.
    int from_up_value = from_up.get_column()[i];
    int free_value = free.get_column()[i];
    int from_bottom_value = from_bottom.get_column()[i];
    int announcement_value = announcement.get_column()[i];
    int hand_value = hand.get_column()[i];
    int respond_value = respond.get_column()[i];
    int from_middle_value = from_middle.get_column()[i];
    int to_middle_value = to_middle.get_column()[i];
    int checkout_value = checkout.get_column()[i];
    int maximum_value = maximum.get_column()[i];

    // Fill matrix row with values we get previously.
    status[i].push_back(from_up_value);
    status[i].push_back(free_value);
    status[i].push_back(from_bottom_value);
    status[i].push_back(announcement_value);
    status[i].push_back(hand_value);
    status[i].push_back(respond_value);
    status[i].push_back(from_middle_value);
    status[i].push_back(to_middle_value);
    status[i].push_back(checkout_value);
    status[i].push_back(maximum_value);
  }

  return status;
}

// Basic getters
C_FromUp &Ticket::getFromUpToDown() { return from_up; }

C_Free &Ticket::getFree() { return free; }

C_FromBottom &Ticket::getFromBottom() { return from_bottom; }

C_Hand &Ticket::getHand() { return hand; }

C_FromMiddle &Ticket::getFromMiddle() { return from_middle; }

C_ToMiddle &Ticket::getToMiddle() { return to_middle; }

C_Announcement &Ticket::getAnnouncement() { return announcement; }

C_Respond &Ticket::getRespond() { return respond; }

C_Checkout &Ticket::getCheckout() { return checkout; }

C_Maximum &Ticket::getMaximum() { return maximum; }

// Check if something can be played.
bool Ticket::can_be_played(Columns column, Fields field) const {
  switch (column) {
    case Columns::FromUp:
      return from_up.valid_order(field);

    case Columns::Free:
      return free.valid_order(field);

    case Columns::FromBottom:
      return from_bottom.valid_order(field);

    case Columns::Hand:
      return hand.valid_order(field);

    case Columns::FromMiddle:
      return from_middle.valid_order(field);

    case Columns::ToMiddle:
      return to_middle.valid_order(field);

    case Columns::Announcement:
      return announcement.valid_order(field);

    case Columns::Respond:
      return respond.valid_order(field);

    case Columns::Checkout:
      return checkout.valid_order(field);

    case Columns::Maximum:
        return maximum.valid_order(field);

    case Columns::None:
      break;
  }

  return false;
}

// Ticket has 10 columns.
bool Ticket::is_full() const { return *number_of_filled_columns == 10; }

score_t Ticket::calculate_score() const {
  // First calculate three sums for each column and sum it all together.
  // Then, that value of whole column add to score.
  score_t score = 0;

  auto from_up_sum = from_up.calculate_sum();
  score += std::get<0>(from_up_sum) + std::get<1>(from_up_sum) +
           std::get<2>(from_up_sum);

  auto free_sum = free.calculate_sum();
  score +=
      std::get<0>(free_sum) + std::get<1>(free_sum) + std::get<2>(free_sum);

  auto from_bottom_sum = from_bottom.calculate_sum();
  score += std::get<0>(from_bottom_sum) + std::get<1>(from_bottom_sum) +
           std::get<2>(from_bottom_sum);

  auto hand_sum = hand.calculate_sum();
  score +=
      std::get<0>(hand_sum) + std::get<1>(hand_sum) + std::get<2>(hand_sum);

  auto from_middle_sum = from_middle.calculate_sum();
  score += std::get<0>(from_middle_sum) + std::get<1>(from_middle_sum) +
           std::get<2>(from_middle_sum);

  auto to_middle_sum = to_middle.calculate_sum();
  score += std::get<0>(to_middle_sum) + std::get<1>(to_middle_sum) +
           std::get<2>(to_middle_sum);

  auto announcement_sum = announcement.calculate_sum();
  score += std::get<0>(announcement_sum) + std::get<1>(announcement_sum) +
           std::get<2>(announcement_sum);

  auto respond_sum = respond.calculate_sum();
  score += std::get<0>(respond_sum) + std::get<1>(respond_sum) +
           std::get<2>(respond_sum);

  auto checkout_sum = checkout.calculate_sum();
  score += std::get<0>(checkout_sum) + std::get<1>(checkout_sum) +
           std::get<2>(checkout_sum);

  auto maximum_sum = maximum.calculate_sum();
  score += std::get<0>(maximum_sum) + std::get<1>(maximum_sum) +
           std::get<2>(maximum_sum);

  return score;
}