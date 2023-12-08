//
#include "shooter.h"

Shooter::Shooter(Die& d1, Die& d2) : die1(d1), die2(d2) {}

Roll* Shooter::throw_die()
{

    Roll* roll = new Roll(die1, die2);
    roll->roll_die();
    rolls.push_back(roll);
    return roll;
}

std::ostream& operator<<(std::ostream& out, const Shooter& shooter)
{
    for (const auto& roll : shooter.rolls)
    {
        out << *roll << "\n";
    }
    return out;
}

Shooter::~Shooter()
{
    for (const auto& roll : rolls)
    {
        delete roll;
    }
    rolls.clear();
}
