//
#include "roll.h"

Roll::Roll(Die& d1, Die& d2) : die1(d1), die2(d2), rolled(false), value(0) {}

void Roll::roll_die()
{
    die1.roll();
    die2.roll();
    value = die1.rolled_value() + die2.rolled_value();

    rolled = true;
}

int Roll::roll_value() const
{
    return value;
}

std::ostream& operator<<(std::ostream& out, const Roll& roll) {
    out << "Die 1: " << roll.die1.rolled_value() << "\nDie 2: " << roll.die2.rolled_value()
        << "\nTotal: " << roll.value;
    return out;
}