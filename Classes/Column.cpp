#include <numeric>

#include "Column.h"

bool Column::check_if_filled(Column_part part) const{

    // which part of the column we want to check
    switch(part){
        case Column_part::Upper:{
            // check if any upper field have value -1
            for(auto& field : upper_column){
                if(field.get_field_value() == -1){
                    std::cerr << "Some fields are empty" << std::endl;
                    return false;
                }

            }

            return true;

        }
        case Column_part::Middle:{
            // check if min or max field have -1 value return false
            return !(min == -1 or max == -1);

        }
        case Column_part::Lower:{

            // if any of the lower fields have -1 value return false
            return !(straight == -1 or three_of_a_kind == -1
                                    or full == -1
                                    or poker == -1
                                    or yamb == -1);

        }
    }
}

int Column::calculate_upper_sum() const{

    // if the last field has been filed
    if(check_if_filled(Column_part::Upper)){
        int sum = std::accumulate(upper_column.begin(), upper_column.end(), 0);

        // this is a rule for upper sums
        if(sum >= 60)
            sum += 30;

        return sum;
    } else{
        std::cerr << "To calculate sum of upper part of column, please fill all fields"
                  << " from upper part of column" << std::endl;

        return -1;
    }
}

// function that calculates middle sum
int Column::calculate_middle_sum() const{
    if(upper_column[0] != -1 && check_if_filled(Column_part::Middle)){
        return upper_column[0] * (max - min);
    } else {
        std::cerr << "To calculate sum of middle part of column, please fill all fields"
                  << " from the middle part of column" << std::endl;

        return -1;
    }
}

int Column::calculate_lower_sum() const{
    if(check_if_filled(Column_part::Lower)){
        return straight + three_of_a_kind + full + poker + yamb;;
    }else{
        std::cerr << "To calculate sum of lower part of column, please fill all fields"
                  << " from the lower part of column" << std::endl;

        return -1;
    }
}

std::tuple<int, int, int> Column::calculate_sum() const {
    int upper_sum = calculate_upper_sum();
    int middle_sum = calculate_middle_sum();
    int lower_sum = calculate_lower_sum();

    return std::make_tuple(upper_sum, middle_sum, lower_sum);
}

void Column::write_in_column(std::vector<Dice>& dices ,Fields type, int number_of_throws){

    switch(type){
        case Fields::Number_1:{
            upper_column[0].calculate_field_value(dices);
            break;
        }
        case Fields::Number_2:{
            upper_column[1].calculate_field_value(dices);
            break;
        }
        case Fields::Number_3:{
            upper_column[2].calculate_field_value(dices);
            break;
        }
        case Fields::Number_4:{
            upper_column[3].calculate_field_value(dices);
            break;
        }
        case Fields::Number_5:{
            upper_column[4].calculate_field_value(dices);
            break;
        }
        case Fields::Number_6:{
            upper_column[5].calculate_field_value(dices);
            break;
        }
        case Fields::Maximum:{
            max.calculate_field_value(dices);
            break;
        }
        case Fields::Minimum:{
            min.calculate_field_value(dices);
            break;
        }
        case Fields::Straight:{
            straight.calculate_field_value(dices, number_of_throws);
            break;
        }
        case Fields::ThreeOfAKind:{
            three_of_a_kind.calculate_field_value(dices);
            break;
        }
        case Fields::Full:{
            full.calculate_field_value(dices);
            break;
        }
        case Fields::Poker:{
            poker.calculate_field_value(dices);
            break;
        }
        case Fields::Yamb:{
            yamb.calculate_field_value(dices);
            break;
        }
        default:
            std::cerr << "This should never happen" << std::endl;
    }
}

std::vector<int> Column::get_column() const {
    std::vector<int> ticket_vals;

    ticket_vals.push_back(upper_column[0].get_field_value());
    ticket_vals.push_back(upper_column[1].get_field_value());
    ticket_vals.push_back(upper_column[2].get_field_value());
    ticket_vals.push_back(upper_column[3].get_field_value());
    ticket_vals.push_back(upper_column[4].get_field_value());
    ticket_vals.push_back(upper_column[5].get_field_value());

    ticket_vals.push_back(max.get_field_value());
    ticket_vals.push_back(min.get_field_value());

    ticket_vals.push_back(straight.get_field_value());
    ticket_vals.push_back(three_of_a_kind.get_field_value());
    ticket_vals.push_back(full.get_field_value());
    ticket_vals.push_back(poker.get_field_value());
    ticket_vals.push_back(yamb.get_field_value());

    return ticket_vals;
}

Column::Column() {}

bool Column::column_full_filled() const {

    return upper_column[0] != -1 and upper_column[1] != -1 and
           upper_column[2] != -1 and upper_column[3] != -1 and
           upper_column[4] != -1 and upper_column[5] != -1 and
           max != -1 and min != -1 and straight != -1 and
           three_of_a_kind != -1 and full != -1 and poker != -1 and
           yamb != -1;
}

