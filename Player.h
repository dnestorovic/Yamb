#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include <vector>
#include "Dice.h"

class Player{
public:

    virtual std::vector<Dice> throw_dices(std::iostream &s) = 0;
    virtual std::vector<Dice> select_dices(std::vector<Dice> dices, std::vector<Dice> pos) = 0;
    virtual void write_on_ticket(std::vector<Dice> dices) = 0;

private:

};


#endif
