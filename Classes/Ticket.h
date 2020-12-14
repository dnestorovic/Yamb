#ifndef INC_14_JAMB_TICKET_H
#define INC_14_JAMB_TICKET_H

#include "Classes/C_FromUpToDown.h"
#include "Classes/C_Free.h"
#include "Classes/C_FromBottom.h"
#include "Classes/C_Hand.h"
#include "Classes/C_FromMiddle.h"
#include "Classes/C_ToMiddle.h"
#include "Classes/C_Announcement.h"
#include "C_AnnouncementRespond.h"

class Ticket{
public:

    Ticket(bool *announcement_ptr, Fields *field_announced_ptr){

        // each column must be aware if some player announced something
        from_up_to_down = C_FromUpToDown(announcement_ptr, field_announced_ptr);
        free = C_Free(announcement_ptr, field_announced_ptr);
        from_bottom = C_FromBottom(announcement_ptr, field_announced_ptr);
        hand = C_Hand(announcement_ptr, field_announced_ptr);
        from_middle = C_FromMiddle(announcement_ptr, field_announced_ptr);
        to_middle = C_ToMiddle(announcement_ptr, field_announced_ptr);
        announcement = C_Announcement(announcement_ptr, field_announced_ptr);
        respond = C_AnnouncementRespond(announcement_ptr, field_announced_ptr);


        upper_sum = -1;
        middle_sum = -1;
        lower_sum = -1;

        result = -1;

        announce = announcement_ptr;
        field_announced = field_announced_ptr;

    }

    Ticket();

    std::vector<std::vector<int>> get_ticket();


    C_FromUpToDown from_up_to_down;
    C_Free free;
    C_FromBottom from_bottom;
    C_Hand hand;
    C_FromMiddle from_middle;
    C_ToMiddle to_middle;
    C_Announcement announcement;
    C_AnnouncementRespond respond;

    int upper_sum;
    int middle_sum;
    int lower_sum;

    int result;

    bool *announce;
    Fields *field_announced;

};

#endif
