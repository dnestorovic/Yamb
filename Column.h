#ifndef INC_14_JAMB_COLUMN_H
#define INC_14_JAMB_COLUMN_H

// class that acts like an interface
class Column{
public:

    virtual bool valid_order(int current_field) const = 0;
    virtual int calculate_upper_sum() const = 0;
    virtual int calculate_middle_sum() const = 0;
    virtual int calculate_lower_sum() const = 0;


};

#endif
