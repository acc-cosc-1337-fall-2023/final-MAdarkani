//
#ifndef DIE_H
#define DIE_H

#include <cstdlib>
#include <ctime>

class Die
{
public:
    Die();
    void roll();
    int rolled_value() const;

private:
    int roll_value;
    const int sides;
    int generate_random_num() const;
};

#endif