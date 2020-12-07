#include <cstdlib>
#include <ctime>
#include "Dice.h"
#include <QDebug>

// TODO explore the problem with srand and rand
int Dice::roll() {
    return std::rand() % 6+1;
}

void Dice::set_value(int value){
    this->value=value;
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
