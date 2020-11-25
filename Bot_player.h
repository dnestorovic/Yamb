#ifndef BOT_PLAYER_H
#define BOT_PLAYER_H

#include "Player.h"
#include "Ticket.h"

class BotPlayer : Player{

public:

    BotPlayer(){
        ticket = Ticket();
    }

    // TODO
    std::vector<Dice> throw_dices(std::istream &s) override;
    std::vector<Dice> select_dices(std::vector<Dice> dices, std::vector<int> positions) override;
    void write_on_ticket(std::vector<Dice> dices) override ;


private:
    Ticket ticket;

};


#endif
