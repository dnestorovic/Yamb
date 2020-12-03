#ifndef C_FROMMIDDLE_H
#define C_FROMMIDDLE_H

#include "Column.h"

class C_FromMiddle : Column{

public:

    C_FromMiddle() = default;

    bool valid_order(Fields type_of_current) const override ;

};

#endif