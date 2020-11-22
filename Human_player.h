#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"
#include "Ticket.h"

class HumanPlayer : Player{

public:

    HumanPlayer(){
        ticket = Ticket();
    }

    std::vector<Dice> throw_dices(std::iostream &s) override;
    std::vector<Dice> select_dices(std::vector<Dice> dices, std::vector<Dice> positions) override;
    void write_on_ticket(std::vector<Dice> dices) override ;

private:
    Ticket ticket;

};


#endif
