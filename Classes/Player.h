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

    Player(bool *announcement_ptr, Fields *field_announced_ptr){

        ticket = Ticket(announcement_ptr, field_announced_ptr);
        announcement = announcement_ptr;
        field_announced = field_announced_ptr;
    }

    Player() {}


    virtual std::vector<Dice> throw_dices(std::istream &s) = 0;
    virtual std::vector<Dice> select_dices(std::vector<Dice> dices, std::vector<int> pos) = 0;
    virtual bool write_on_ticket(std::vector<Dice>& dices, Fields field, Columns column) = 0;

    virtual bool announce(Fields field) = 0;
    virtual void respond_announce() = 0;

    // getter for ticket
    Ticket& get_ticket(){
        return ticket;
    }


protected:
    // just to make easier arithmetic later
    int number_of_dices = 6;

    int player_id;

    Fields *field_announced;
    bool *announcement;

private:

    Ticket ticket;

};


#endif
