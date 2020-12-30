#ifndef THREE_OF_A_KIND_H
#define THREE_OF_A_KIND_H

#include "Field.h"

class ThreeOfAKind : public Field {

public:
    ThreeOfAKind(){
        field_value = -1;
    }

    bool valid_input(const std::vector<Dice>& input) const override;
    void calculate_field_value(const std::vector<Dice>& selected_dices) override;
};

#endif
