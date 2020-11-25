#ifndef DICE_H
#define DICE_H

#include <iostream>

class Dice{
public:

    // if we create empty Dice, just set value as 1
    explicit Dice(int val = 1) : value(val){

        std::cout << "Dice created" << std::endl;

    }

    // friend function for print
    friend std::ostream& operator<<(std::ostream& out, Dice& value);

    // TODO roll function should be implement differently when server implement this func
    void roll();
    int get_value() const;

private:
    int value;
};

std::ostream& operator<<(std::ostream& out, Dice& value);


#endif
