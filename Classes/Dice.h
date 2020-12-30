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

  friend uint8_t operator+(const Dice& a, const Dice& b) {
    return a.value + b.value;
  }
  friend uint8_t operator+(int a, const Dice& b) {
    return a + b.value;
  }
  friend uint8_t operator+(const Dice& a, int b) {
    return a.value + b;
  }

  uint8_t get_value() const;
  bool get_selected() const;
  void set_value(uint8_t);
  void set_selected(bool);
  void roll();

 private:
  uint8_t value;
  bool selected;
};

std::ostream& operator<<(std::ostream& out, Dice& value);

#endif
