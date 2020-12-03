#ifndef C_FROMBOTTOM_H
#define C_FROMBOTTOM_H

#include "Column.h"

class C_FromBottom : Column{

public:

    C_FromBottom() = default;
    bool valid_order(Fields type) const override;


};


#endif