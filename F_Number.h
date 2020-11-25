#ifndef F_NUMBER_H
#define F_NUMBER_H

#include "Field.h"

class F_Number : Field{

public:

    /* ctor argument "value" defines type of field
     * initial field value is -1 because that value suggests that we didn't fill field yet
     * that initial field value will be used to define whatever the filed is filled or not
     * */
    explicit F_Number(int value):expected_value(value),
                                 field_value(-1)
    {}

    // functions that we need to implement from parent class
    void calculate_field_value(const std::vector<Dice>& selected_dices) override;


    // FIXME (can be replaced)
    // we can override operator * for MinMax and F_Number to eliminate this function
    // getter function
    int get_field_value() const;



    // defines way we compare field value with simple integers
    bool operator==(int other) const;
    bool operator!=(int other) const;

    // defines how we add two fields or field with simple int
    // FIXME this should be used for std::accumulate function but it signals error
    // for now it is used in simple for loop
    int operator+(const F_Number& other) const;
    int operator+(int other) const;

private:
    // this function should be private because we use it only in this class
    bool valid_input(const std::vector<Dice>& input) const override;


    // for every upper field we have expected value that defines field type for number fields
    int expected_value;
    // here we store value of the field of column
    int field_value;

};



#endif
