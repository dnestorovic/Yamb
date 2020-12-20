#ifndef DICE_H
#define DICE_H

#include <iostream>

class Dice {
 public:
  // if we create empty Dice, just set value as 1
  explicit Dice(int value = 1) : value(value), selected(false) {}

  // friend function for print
  friend std::ostream& operator<<(std::ostream& out, Dice& value);

  // operators
  bool operator==(const Dice& other) const;
  bool operator!=(const Dice& other) const;
  bool operator<(const Dice& other) const;
  bool operator>(const Dice& other) const;

  // TODO roll function should be implement differently when server implement
  // this func
  bool get_selected() const;
  int get_value() const;
  void set_value(int);
  void set_selected(bool);
  void roll();

 private:
  int value;
  bool selected;
};

std::ostream& operator<<(std::ostream& out, Dice& value);

#endif
