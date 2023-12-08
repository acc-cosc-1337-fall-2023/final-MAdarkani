//
#include "die.h"

Die::Die() : sides(6)
{
 
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

}

void Die::roll()
{
    roll_value = generate_random_num();
}

int Die::rolled_value() const
{
    return roll_value;
}

int Die::generate_random_num() const
{
    return rand() % sides +1;
}