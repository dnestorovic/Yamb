#ifndef INC_14_JAMB_TICKET_H
#define INC_14_JAMB_TICKET_H

#include "Classes/C_FromUpToDown.h"
#include "Classes/C_Free.h"
#include "Classes/C_FromBottom.h"
#include "Classes/C_Hand.h"
#include "Classes/C_FromMiddle.h"
#include "Classes/C_ToMiddle.h"
#include "Classes/C_Announcement.h"

class Ticket{
public:

    Ticket(){

        from_up_to_down = C_FromUpToDown();
        free = C_Free();
        from_bottom = C_FromBottom();
        hand = C_Hand();
        from_middle = C_FromMiddle();
        to_middle = C_ToMiddle();
        announcement = C_Announcement();

        upper_sum = -1;
        middle_sum = -1;
        lower_sum = -1;

        result = -1;

    }

    std::vector<std::vector<int>> get_ticket();


    C_FromUpToDown from_up_to_down;
    C_Free free;
    C_FromBottom from_bottom;
    C_Hand hand;
    C_FromMiddle from_middle;
    C_ToMiddle to_middle;
    C_Announcement announcement;

    int upper_sum;
    int middle_sum;
    int lower_sum;

    int result;

};

#endif
