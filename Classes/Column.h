#ifndef INC_14_JAMB_COLUMN_H
#define INC_14_JAMB_COLUMN_H

#include <utility>

#include "MinMax.h"
#include "Straight.h"
#include "Three_of_a_kind.h"
#include "Full.h"
#include "Poker.h"
#include "Field.h"
#include "Yamb.h"

enum class Column_part {
    Upper, Middle, Lower
};

enum class Columns {
    From_Up, Free, From_Bottom, Announcement, Hand, AnnouncementRespond,
    From_Middle, To_Middle, Checkout, Maximum, None
};

// class that acts like an interface
class Column {
public:
    Column();

    Column(bool *announcement_ptr, Fields *field_announced_ptr, int *number_of_filled_columns) {
        // initialize upper part of column
        for(int i = 0; i < 6; i++) {
            F_Number tmp(i + 1);
            upper_column.push_back(tmp);
        }

        // initialize middle part of column
        min = MinMax();
        max = MinMax();

        //initialize bottom part of column
        straight = Straight();
        three_of_a_kind = ThreeOfAKind();
        full = Full();
        poker = Poker();
        yamb = Yamb();

        announce = announcement_ptr;
        field_announced = field_announced_ptr;

        number_of_filled_columns = number_of_filled_columns;
    }

    // function that should be override
    virtual bool valid_order(Fields type) const = 0;

    // function that stores value to field in column
    void write_in_column(std::vector<Dice>& dices ,Fields type, int number_of_throws);

    // function that returns status of the column
    std::vector<int> get_column() const;

    int calculate_upper_sum() const;
    int calculate_middle_sum() const;
    int calculate_lower_sum() const;
    bool check_if_filled(Column_part part) const;
    bool column_full_filled() const;

    static Columns col_to_enum(int8_t col)
    {
        Columns column;

        switch (col)
        {
            case 0:
                column = Columns::From_Up;
                break;
            case 1:
                column = Columns::Free;
                break;
            case 2:
                column = Columns::From_Bottom;
                break;
            case 3:
                column = Columns::Announcement;
                break;
            case 4:
                column = Columns::Hand;
                break;
            case 5:
                column = Columns::AnnouncementRespond;
                break;
            case 6:
                column = Columns::From_Middle;
                break;
            case 7:
                column = Columns::To_Middle;
                break;
            case 8:
                column = Columns::Checkout;
                break;
            case 9:
                column = Columns::Maximum;
                break;
            default:
                std::cerr << "Failed enum conversion" << std::endl;
        }

        return column;
    }

protected:
    // every field has it's own logic if it is correctly filled
    std::vector<F_Number> upper_column;
    MinMax max;
    MinMax min;
    Straight straight;
    ThreeOfAKind three_of_a_kind;
    Full full;
    Poker poker;
    Yamb yamb;

    bool *announce;
    Fields *field_announced;
    int *number_of_filled_columns;
};

#endif
