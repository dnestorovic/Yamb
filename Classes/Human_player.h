#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"
#include "Ticket.h"

class HumanPlayer
    : public Player
{
public:
    HumanPlayer() = default;

    explicit HumanPlayer(bool *announcementPtr, Fields *fieldAnnouncedPtr, int *number_of_filled_columns)
                        : Player(announcementPtr, fieldAnnouncedPtr, number_of_filled_columns)
    {}

    // TODO istream should be replaced with socket when server implements that
    std::vector<Dice> throw_dices(std::istream &s) override;
    std::vector<Dice> select_dices(std::vector<Dice> dices, std::vector<int> positions) override;
    bool write_on_ticket(std::vector<Dice> dices, Fields field, Columns column, int number_of_throws) override;

    bool announce(Fields field) override;
    void respond_announce() override;
};

#endif
