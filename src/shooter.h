//
#ifndef SHOOTER_H
#define SHOOTER_H
#include "roll.h"
#include <vector>
#include <iostream>

class Shooter 
{
public:
    Shooter(Die& d1, Die& d2);
    Roll* throw_die();
    friend std::ostream& operator<<(std::ostream& out, const Shooter& shooter);
    ~Shooter();

private:
    Die& die1;
    Die& die2;
    std::vector<Roll*> rolls;
};


#endif