#ifndef MINMAX_H
#define MINMAX_H

#include "F_Number.h"
#include "Field.h"

class MinMax : public Field {
 public:
    // Constructor and override functions.
    MinMax() { field_value = -1; }

  void calculate_field_value(const std::vector<Dice>& selected_dices) override;

 private:
  // This function should be private because we need it just in this class.
  bool valid_input(const std::vector<Dice>& input) const override;
};

#endif
