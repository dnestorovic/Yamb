#ifndef INC_14_JAMB_TICKET_H
#define INC_14_JAMB_TICKET_H

#include <tuple>

#include "Column.h"
#include "C_FromUpToDown.h"
#include "C_Free.h"
#include "C_FromBottom.h"
#include "C_Hand.h"
#include "C_FromMiddle.h"
#include "C_ToMiddle.h"
#include "C_Announcement.h"
#include "C_AnnouncementRespond.h"
#include "C_Checkout.h"
#include "C_Maximum.h"

class Ticket {
public:
    Ticket();

    Ticket(bool *announcement_ptr, Fields *field_announced_ptr, int *number_of_filled_columns){
        // each column must be aware if some player announced something
        from_up_to_down = C_FromUpToDown(announcement_ptr, field_announced_ptr, number_of_filled_columns);
        free = C_Free(announcement_ptr, field_announced_ptr, number_of_filled_columns);
        from_bottom = C_FromBottom(announcement_ptr, field_announced_ptr, number_of_filled_columns);
        hand = C_Hand(announcement_ptr, field_announced_ptr, number_of_filled_columns);
        from_middle = C_FromMiddle(announcement_ptr, field_announced_ptr, number_of_filled_columns);
        to_middle = C_ToMiddle(announcement_ptr, field_announced_ptr, number_of_filled_columns);
        announcement = C_Announcement(announcement_ptr, field_announced_ptr, number_of_filled_columns);
        respond = C_AnnouncementRespond(announcement_ptr, field_announced_ptr, number_of_filled_columns);
        checkout = C_Checkout(announcement_ptr, field_announced_ptr, number_of_filled_columns);
        maximum = C_Maximum(announcement_ptr, field_announced_ptr, number_of_filled_columns);

        announce = announcement_ptr;
        field_announced = field_announced_ptr;
    }

    std::vector<std::vector<int>> get_ticket_value();

    std::tuple<int, int, int> calculate_column_sum(Columns col);

    // getters for columns
    C_FromUpToDown& getFromUpToDown();
    C_Free& getFree();
    C_FromBottom& getFromBottom();
    C_Hand& getHand();
    C_FromMiddle& getFromMiddle();
    C_ToMiddle& getToMiddle();
    C_Announcement& getAnnouncement();
    C_AnnouncementRespond& getRespond();
    C_Checkout& getCheckout();
    C_Maximum& getMaximum();

    bool can_be_played(Columns, Fields) const;

private:
    C_FromUpToDown from_up_to_down;
    C_Free free;
    C_FromBottom from_bottom;
    C_Hand hand;
    C_FromMiddle from_middle;
    C_ToMiddle to_middle;
    C_Announcement announcement;
    C_AnnouncementRespond respond;
    C_Checkout checkout;
    C_Maximum maximum;

    int result;

    bool *announce;
    Fields *field_announced;
};

#endif
