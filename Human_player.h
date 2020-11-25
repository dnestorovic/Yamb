#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"
#include "Ticket.h"

class HumanPlayer : Player{

public:

    HumanPlayer(){
        ticket = Ticket();
    }

    // TODO istream should be replaced with socket when server implements that
    std::vector<Dice> throw_dices(std::istream &s) override;
    std::vector<Dice> select_dices(std::vector<Dice> dices, std::vector<int> positions) override;
    // FIXME function should have one more argument for place where we write
    void write_on_ticket(std::vector<Dice> dices) override ;

private:
    Ticket ticket;

};


#endif
