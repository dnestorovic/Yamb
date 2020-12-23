#include "Ticket.h"

Ticket::Ticket() {}

std::vector<std::vector<int>> Ticket::get_ticket_value(){

    int number_of_columns = 6;
    int number_of_fields = 13;

    std::vector<std::vector<int>> status;

    // resizing matrix to number_of_fields x number_of_columns
    status.resize(number_of_fields);


    for(int i = 0; i < number_of_fields; i++){

        int from_up_value = from_up_to_down.get_column()[i];
        int free_value = free.get_column()[i];
        int from_bottom_value = from_bottom.get_column()[i];
        int announcement_value = announcement.get_column()[i];
        int hand_value = hand.get_column()[i];
        int respond_value = respond.get_column()[i];
        int from_middle_value = from_middle.get_column()[i];
        int to_middle_value = to_middle.get_column()[i];

        status[i].push_back(from_up_value);
        status[i].push_back(free_value);
        status[i].push_back(from_bottom_value);
        status[i].push_back(announcement_value);
        status[i].push_back(hand_value);
        status[i].push_back(respond_value);
        status[i].push_back(from_middle_value);
        status[i].push_back(to_middle_value);

    }

    return status;

}

C_FromUpToDown &Ticket::getFromUpToDown() {
    return from_up_to_down;
}

C_Free &Ticket::getFree() {
    return free;
}

C_FromBottom &Ticket::getFromBottom() {
    return from_bottom;
}

C_Hand &Ticket::getHand() {
    return hand;
}

C_FromMiddle &Ticket::getFromMiddle() {
    return from_middle;
}

C_ToMiddle &Ticket::getToMiddle() {
    return to_middle;
}

C_Announcement &Ticket::getAnnouncement() {
    return announcement;
}

C_AnnouncementRespond &Ticket::getRespond() {
    return respond;
}
