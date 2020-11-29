#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include <vector>
#include "Dice.h"

// class that acts like an interface
class Player{
public:

    virtual std::vector<Dice> throw_dices(std::istream &s) = 0;
    virtual std::vector<Dice> select_dices(std::vector<Dice> dices, std::vector<int> pos) = 0;
    virtual void write_on_ticket(std::vector<Dice> dices) = 0;

protected:
    // just to make easier arithmetic later
    int number_of_dices = 6;

private:

};


#endif