#ifndef DICE_H
#define DICE_H

#include <iostream>

class Dice{
public:

    Dice(int val = 1) : value(val){

        std::cout << "Dice created" << std::endl;

    }

    void roll();
    int get_value() const;

private:
    int value;
};


#endif
