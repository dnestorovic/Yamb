#ifndef INC_14_JAMB_TICKET_H
#define INC_14_JAMB_TICKET_H

#include <tuple>

#include "../NetworkCommon/common.h"
#include "C_Announcement.h"
#include "C_Checkout.h"
#include "C_Free.h"
#include "C_FromBottom.h"
#include "C_FromMiddle.h"
#include "C_FromUp.h"
#include "C_Hand.h"
#include "C_Maximum.h"
#include "C_Respond.h"
#include "C_ToMiddle.h"
#include "Column.h"
#include "Field.h"

class Ticket {
 public:
  Ticket();

  Ticket(bool* announcement_ptr, Fields* field_announced_ptr,
         int* number_of_filled_columns_ptr) {
    // each column must be aware if some player announced something
    from_up = C_FromUp(announcement_ptr, field_announced_ptr,
                       number_of_filled_columns_ptr);
    free = C_Free(announcement_ptr, field_announced_ptr,
                  number_of_filled_columns_ptr);
    from_bottom = C_FromBottom(announcement_ptr, field_announced_ptr,
                               number_of_filled_columns_ptr);
    hand = C_Hand(announcement_ptr, field_announced_ptr,
                  number_of_filled_columns_ptr);
    from_middle = C_FromMiddle(announcement_ptr, field_announced_ptr,
                               number_of_filled_columns_ptr);
    to_middle = C_ToMiddle(announcement_ptr, field_announced_ptr,
                           number_of_filled_columns_ptr);
    announcement = C_Announcement(announcement_ptr, field_announced_ptr,
                                  number_of_filled_columns_ptr);
    respond = C_Respond(announcement_ptr, field_announced_ptr,
                        number_of_filled_columns_ptr);
    checkout = C_Checkout(announcement_ptr, field_announced_ptr,
                          number_of_filled_columns_ptr);
    maximum = C_Maximum(announcement_ptr, field_announced_ptr,
                        number_of_filled_columns_ptr);

    announce = announcement_ptr;
    field_announced = field_announced_ptr;
    number_of_filled_columns = number_of_filled_columns_ptr;
  }

  bool can_be_played(Columns, Fields) const;
  std::vector<std::vector<int>> get_ticket_value();
  std::tuple<int, int, int> calculate_column_sum(Columns col);

  // getters for columns
  C_FromUp& getFromUpToDown();
  C_Free& getFree();
  C_FromBottom& getFromBottom();
  C_Hand& getHand();
  C_FromMiddle& getFromMiddle();
  C_ToMiddle& getToMiddle();
  C_Announcement& getAnnouncement();
  C_Respond& getRespond();
  C_Checkout& getCheckout();
  C_Maximum& getMaximum();

  bool is_full() const;
  score_t calculate_score() const;

 private:
  C_FromUp from_up;
  C_Free free;
  C_FromBottom from_bottom;
  C_Hand hand;
  C_FromMiddle from_middle;
  C_ToMiddle to_middle;
  C_Announcement announcement;
  C_Respond respond;
  C_Checkout checkout;
  C_Maximum maximum;

  bool* announce;
  Fields* field_announced;

  int* number_of_filled_columns;
};

#endif
