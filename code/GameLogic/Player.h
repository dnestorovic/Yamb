#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>

#include "Column.h"
#include "Dice.h"
#include "Ticket.h"

// Class that acts like an interface.
class Player {
 public:
  Player() = default;

  Player(bool *announcement_ptr, Fields *field_announced_ptr,
         int *num_of_filled_columns) {
    announcement = announcement_ptr;
    field_announced = field_announced_ptr;
    number_of_filled_columns = num_of_filled_columns;
  }

  virtual std::vector<Dice> throw_dices(std::istream &s) = 0;
  virtual std::vector<Dice> select_dices(std::vector<Dice> dices,
                                         std::vector<int> pos) = 0;
  virtual bool write_on_ticket(std::vector<Dice> dices, Fields field,
                               Columns column, int number_of_throws) = 0;

  virtual bool announce(Fields field) = 0;
  virtual void respond_announce() = 0;

  Ticket &get_ticket() { return ticket; }

  // Setter for pointer data.
  void set_pointer_data(Fields *Field_announced, bool *Announcement,
                        int *Number_of_filled) {
    field_announced = Field_announced;
    announcement = Announcement;
    number_of_filled_columns = Number_of_filled;

    ticket = Ticket(announcement, field_announced, number_of_filled_columns);
  }

 protected:
  int number_of_dices = 6;
  int player_id = -1;

  Fields *field_announced;
  bool *announcement;
  int *number_of_filled_columns;

 private:
  Ticket ticket;
};

#endif
