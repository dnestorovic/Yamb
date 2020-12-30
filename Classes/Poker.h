#ifndef POKER_H
#define POKER_H

#include "Field.h"

class Poker : public Field {

public:
    Poker() {
        field_value = -1;
    }

    bool valid_input(const std::vector<Dice>& input) const override;
    void calculate_field_value(const std::vector<Dice>& selected_dices) override;
};

#endif
