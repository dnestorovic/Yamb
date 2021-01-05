#ifndef F_NUMBER_H
#define F_NUMBER_H

#include "Field.h"

class F_Number : public Field {
 public:
  /* Ctor argument "value" defines type of field.
   * Initial field value is -1 because that value suggests that we didn't fill
   * field yet that initial field value will be used to define whatever the
   * filed is filled or not.
   * */
  explicit F_Number(int value) : expected_value(value) { field_value = -1; }

  // Functions that we need to implement from parent class.
  void calculate_field_value(const std::vector<Dice>& selected_dices) override;

 private:
  // This function should be private because we use it only in this class.
  bool valid_input(const std::vector<Dice>& input) const override;

  // For every upper field we have expected value that defines field type for
  // number fields.
  int expected_value;
};

#endif
