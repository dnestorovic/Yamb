#ifndef DICE_H
#define DICE_H

#include <iostream>

class Dice {
 public:
  explicit Dice(uint8_t value = 0) : value(value), selected(false) {}

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
  uint8_t get_value() const;
  void set_value(uint8_t);
  void set_selected(bool);
  void roll();

 private:
  uint8_t value;
  bool selected;
};

std::ostream& operator<<(std::ostream& out, Dice& value);

#endif
