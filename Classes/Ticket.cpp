#include "Ticket.h"

Ticket::Ticket() {}

std::vector<std::vector<int>> Ticket::get_ticket_value(){

    int number_of_fields = 13;

    std::vector<std::vector<int>> status;

    // resizing matrix to number_of_fields x number_of_columns
    status.resize(number_of_fields);

    // we iterate thought all fields and and we fill row by row using value of that field in each column
    for(int i = 0; i < number_of_fields; i++){
        // get value of i field from each column
        int from_up_value = from_up_to_down.get_column()[i];
        int free_value = free.get_column()[i];
        int from_bottom_value = from_bottom.get_column()[i];
        int announcement_value = announcement.get_column()[i];
        int hand_value = hand.get_column()[i];
        int respond_value = respond.get_column()[i];
        int from_middle_value = from_middle.get_column()[i];
        int to_middle_value = to_middle.get_column()[i];
        int checkout_value = checkout.get_column()[i];
        int maximum_value = maximum.get_column()[i];

        // fill matrix row with values we get previously
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

C_Checkout& Ticket::getCheckout() {
    return checkout;
}

C_Maximum& Ticket::getMaximum() {
    return maximum;
}

bool Ticket::can_be_played(Columns column, Fields field) const{
    switch(column){
        case Columns::From_Up:
            return from_up_to_down.valid_order(field);

        case Columns::Free:
            return free.valid_order(field);

        case Columns::From_Bottom:
            return from_bottom.valid_order(field);

        case Columns::Hand:
            return hand.valid_order(field);

        case Columns::From_Middle:
            return from_middle.valid_order(field);

        case Columns::To_Middle:
            return to_middle.valid_order(field);

        case Columns::Announcement:
            return announcement.valid_order(field);

        case Columns::AnnouncementRespond:
            return respond.valid_order(field);

        case Columns::Checkout:
            // TODO fill this once the column is done
            break;

        case Columns::Maximum:
            // TODO fill this once the column is done!
            break;

        case Columns::None:
            std::cerr << "This should never happen(Bot can_be_played)" << std::endl;
            break;
        default:
            std::cerr << "This should never happen(Default for bot can_be_played)" << std::endl;
    }
}
