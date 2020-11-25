#include <iostream>
#include <vector>

#include "Game.h"
#include "C_FromUpToDown.h"

int main(){

    HumanPlayer h1 = HumanPlayer();
    std::vector<int> pos = {1, 3, 4};

    std::vector<Dice> sd = h1.select_dices(h1.throw_dices(std::cin), pos);

    for(auto x : sd){
        cout << x;
    }

    C_FromUpToDown column = C_FromUpToDown();

    std::cout << column.calculate_upper_sum();

    return 0;
}