#include "C_Maximum.h"


bool C_Maximum::valid_order(Fields type_of_current) const{

    /*********Rules*******************
     * -> Fields can be filled in any order if the value of current field is -1
     * *******************************/

    switch(type_of_current){
        case Fields::Number_1 :{
            return upper_column[0] == -1;
        }
        case Fields::Number_2:{
            return upper_column[1] == -1;
        }
        case Fields::Number_3: {
            return upper_column[2] == -1;
        }
        case Fields::Number_4: {
            return upper_column[3] == -1;
        }
        case Fields::Number_5:{
            return upper_column[4] == -1;
        }
        case Fields::Number_6:{
            return upper_column[5] == -1;
        }
        case Fields::Maximum:{
            return max == -1;
        }
        case Fields::Minimum:{
            return min == -1;
        }
        case Fields::Straight:{
            return straight == -1;
        }
        case Fields::Three_of_a_kind:{
            return  three_of_a_kind == -1;
        }
        case Fields::Full: {
            return full == -1;
        }
        case Fields::Poker:{
            return poker == -1;
        }
        case Fields::Yamb:{
            return yamb == -1;
        }
        default:{
            std::cerr << "This should never happen!";
            return false;
        }

    }


}