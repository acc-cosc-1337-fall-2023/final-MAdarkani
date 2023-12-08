//
#ifndef ROLL_H
#define ROLL_H

#include "die.h"
#include <iostream>

class Roll
{
public:
    Roll (Die& d1, Die& d2);
    void roll_die();
    int roll_value() const;
    friend std::ostream& operator<<(std::ostream& out, const Roll& roll);
    void set_rolled_value(int value) {
        rolled = true;
        this->value = value;
    }
private:
    Die& die1;
    Die& die2;
    bool rolled;
    int value;
};


#endif