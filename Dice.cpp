#include <cstdlib>
#include <time.h>
#include "Dice.h"

void Dice::roll() {
    std::srand(time(NULL));
    this->value = std::rand() % 6;
}

int Dice::get_value() const {
    return this->value;
}
