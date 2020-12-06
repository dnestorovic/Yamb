#include <cstdlib>
#include <ctime>
#include "Dice.h"

// TODO explore the problem with srand and rand
void Dice::roll() {
    std::srand(time(NULL));
    this->value = std::rand() % 6+1;
}

// simple getter
int Dice::get_value() const {
    return this->value;
}

// we just simplify print of dice value
std::ostream& operator<<(std::ostream& out, Dice& value){
    return out << value.value;
}


bool Dice::operator==(const Dice& other) const{
    return this->get_value() == other.get_value();
}

bool Dice::operator!=(const Dice& other) const{
    return this->get_value() != other.get_value();
}

bool Dice::operator<(const Dice& other) const{
    return this->get_value() < other.get_value();
}

bool Dice::operator>(const Dice& other) const{
    return this->get_value() > other.get_value();
}
