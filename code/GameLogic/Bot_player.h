#ifndef BOT_PLAYER_H
#define BOT_PLAYER_H

#include <list>

#include "Player.h"
#include "Ticket.h"

class BotPlayer : Player {
 public:
  BotPlayer(bool *announcementPtr, Fields *fieldAnnouncedPtr,
            int *number_of_throws)
      : Player(announcementPtr, fieldAnnouncedPtr, number_of_throws) {
    calculate_priority();
  }

  // Main function for this class.
  // Defines bot's next move.
  void play_next_move();

  // Functions that bot overrides from player class.
  std::vector<Dice> throw_dices(std::istream &s) override;
  std::vector<Dice> select_dices(std::vector<Dice> dices,
                                 std::vector<int> positions) override;
  bool write_on_ticket(std::vector<Dice> dices, Fields field, Columns column,
                       int number_of_throws) override;

  bool announce(Fields field) override;
  void respond_announce() override;

 private:
  Ticket ticket;

  // Some fields are heavier to get so there must be priority.
  std::list<std::pair<int, int>> priority_for_play;

  // Calculate priority of the fields.
  void calculate_priority();
  std::pair<Columns, Fields> convert_priority_to_enum(
      std::pair<int, int>) const;

  // Intern functions for bot logic that just helps in main functions
  // implementation.
  std::pair<Columns, Fields> find_best_move(std::vector<Dice> &dices,
                                            double probability_tolerance) const;
  std::pair<Columns, Fields> decide_next_move(std::vector<Dice> &dices) const;
  double calculate_probability(Fields field, std::vector<Dice> &dices) const;
};

#endif
