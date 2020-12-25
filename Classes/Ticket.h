#ifndef INC_14_JAMB_TICKET_H
#define INC_14_JAMB_TICKET_H

#include "Classes/C_FromUpToDown.h"
#include "Classes/C_Free.h"
#include "Classes/C_FromBottom.h"
#include "Classes/C_Hand.h"
#include "Classes/C_FromMiddle.h"
#include "Classes/C_ToMiddle.h"
#include "Classes/C_Announcement.h"
#include "Classes/C_AnnouncementRespond.h"
#include "Classes/C_Checkout.h"
#include "Classes/C_Maximum.h"


class Ticket{
public:

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

        upper_sum = -1;
        middle_sum = -1;
        lower_sum = -1;

        result = -1;

        announce = announcement_ptr;
        field_announced = field_announced_ptr;

    }

    Ticket();

    std::vector<std::vector<int>> get_ticket_value();

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

    int upper_sum;
    int middle_sum;
    int lower_sum;

    int result;

    bool *announce;
    Fields *field_announced;

};

#endif
