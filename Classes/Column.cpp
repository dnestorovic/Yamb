#include "Column.h"

bool Column::check_if_filled(Column_part part) const{

    // which part of the column we want to check
    switch(part){
        case Column_part::Upper:{
            // check if any upper field have value -1
            for(const auto& field : upper_column){

                if(field.get_field_value() == -1){
                    std::cout << "Nisu popunjena sva polja" << std::endl;
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

        //FIXME
        //return std::accumulate(upper_column.cbegin(), upper_column.cend(), 0);
        // should use accumulate but for now let just use loop
        int sum = 0;
        for(const auto& x : upper_column){
            sum = x + sum;
        }

        // this is a rule for upper sums
        if(sum >= 60)
            sum += 30;

        return sum;

    } else{
        std::cout << "To calculate sum of upper part of column, please fill all fields"
                  << " from upper part of column" << std::endl;

        return -1;
    }

}

// function that calculates middle sum
int Column::calculate_middle_sum() const{

    if(check_if_filled(Column_part::Middle)){
        // this is a rule for calculating middle sums
        // FIXME change getter with override operator * for MinMax and F_Number
        return (max - min) * upper_column[0].get_field_value();
    }else{
        std::cout << "To calculate sum of middle part of column, please fill all fields"
                  << " from the middle part of column" << std::endl;

        return -1;
    }


}



int Column::calculate_lower_sum() const{

    if(check_if_filled(Column_part::Lower)){

        int sum = 0;
        sum = straight + sum;
        sum = three_of_a_kind + sum;
        sum = full + sum;
        sum = poker + sum;
        sum = yamb + sum;

        return sum;


    }else{
        std::cout << "To calculate sum of lower part of column, please fill all fields"
                  << " from the lower part of column" << std::endl;

        return -1;
    }

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
        case Fields::Three_of_a_kind:{
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
            std::cout << "This should never happen" << std::endl;
    }

}

std::vector<int> Column::get_column() const{

    std::vector<int> result;

    result.push_back(upper_column[0].get_field_value());
    result.push_back(upper_column[1].get_field_value());
    result.push_back(upper_column[2].get_field_value());
    result.push_back(upper_column[3].get_field_value());
    result.push_back(upper_column[4].get_field_value());
    result.push_back(upper_column[5].get_field_value());

    result.push_back(max.get_field_value());
    result.push_back(min.get_field_value());

    result.push_back(straight.get_field_value());
    result.push_back(three_of_a_kind.get_field_value());
    result.push_back(full.get_field_value());
    result.push_back(poker.get_field_value());
    result.push_back(yamb.get_field_value());


    return result;
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

