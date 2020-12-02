#ifndef C_FREE_H
#define C_FREE_H

#include "Column.h"

class C_Free : public Column{
public:

    C_Free() = default;
    bool valid_order(Fields type_of_current) const override ;


private:

};



#endif