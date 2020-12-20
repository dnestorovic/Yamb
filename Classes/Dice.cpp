#include <cstdlib>
#include <ctime>
#include "Dice.h"

// TODO explore the problem with srand and rand

// simple getter
int Dice::get_value() const {
    return this->value;
}

void Dice::set_value(int value){
    this->value=value;
}

bool Dice::get_selected() const{
    return this->selected;
}

void Dice::set_selected(bool selected){
    this->selected=selected;
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
