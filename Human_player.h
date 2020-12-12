#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"
#include "Ticket.h"

class HumanPlayer : public Player{

public:

    // TODO istream should be replaced with socket when server implements that
    std::vector<Dice> throw_dices(std::istream &s) override;
    std::vector<Dice> select_dices(std::vector<Dice> dices, std::vector<int> positions) override;
    bool write_on_ticket(std::vector<Dice>& dices, Fields field, Columns column) override ;

private:

};


#endif
