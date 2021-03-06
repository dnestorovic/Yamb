#include <numeric>
#include <iostream>
#include "C_FromUpToDown.h"

// valid order for this column is from the top to the bottom
bool C_FromUpToDown::valid_order(Fields type_of_current) const{

    /*********Rules*******************
     * ->First field can be filled if it wasn't filled previously
     * ->Other fields can be filled if they wasn't filled previously and the above
     * field was filled previously
     * ! Field has value -1 if it wasn't filled yet !
     * *******************************/

    switch(type_of_current){
        case Fields::Number_1 :{
            // if the first field wasn't filled, we can fill it
            return upper_column[0] == -1;
        }
        case Fields::Number_2:{
            return (upper_column[0] != -1 and upper_column[1] == -1);
        }
        case Fields::Number_3: {
            return upper_column[1] != -1 and upper_column[2] == -1;
        }
        case Fields::Number_4: {
            return upper_column[2] != -1 and upper_column[3] == -1;
        }
        case Fields::Number_5:{
            return upper_column[3] != -1 and upper_column[4] == -1;
        }
        case Fields::Number_6:{
            return upper_column[4] != -1 and upper_column[5] == -1;
        }
        case Fields::Maximum:{
            return upper_column[5] != -1 and max == -1;
        }
        case Fields::Minimum:{
            return max != -1 and min == -1;
        }
        case Fields::Straight:{
            return min != -1 and straight == -1;
        }
        case Fields::Three_of_a_kind:{
            return straight != -1 and three_of_a_kind == -1;
        }
        case Fields::Full: {
            return three_of_a_kind != -1 and full == -1;
        }
        case Fields::Poker:{
            return full != -1 and poker == -1;
        }
        case Fields::Yamb:{
            return poker != -1 and yamb == -1;
        }
        default:{
            std::cerr << "This should never happen";
            return false;
        }

    }

}
