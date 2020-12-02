#include <iostream>
#include <vector>

#include "Game.h"
#include "C_FromUpToDown.h"
#include "Straight.h"
#include "Column.h"
#include "C_Free.h"

int main(){

    // DONE all classes have been tested
    // DONE valid_order for C_FromUpToDown tested
    // Done valid_order for C_Free tested

    C_Free k1 = C_Free();
    k1.upper_column[0] = 4;
    k1.upper_column[1] = 4;
    k1.upper_column[2] = 4;


    std::cout << k1.valid_order(Fields::Number_2);

    return 0;

}