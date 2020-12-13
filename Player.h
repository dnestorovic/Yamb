#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include <vector>
#include "Dice.h"
#include "Column.h"
#include "Ticket.h"

// class that acts like an interface
class Player{
public:

    Player(){
        ticket = Ticket();
        announcement = false;
        field_announced = Fields::None;
    }

    virtual std::vector<Dice> throw_dices(std::istream &s) = 0;
    virtual std::vector<Dice> select_dices(std::vector<Dice> dices, std::vector<int> pos) = 0;
    virtual bool write_on_ticket(std::vector<Dice>& dices, Fields field, Columns column) = 0;

    virtual void announce(Fields field) = 0;


    Ticket ticket;
    int player_id;

    bool announcement;
    Fields field_announced;

protected:
    // just to make easier arithmetic later
    int number_of_dices = 6;



private:

};


#endif
