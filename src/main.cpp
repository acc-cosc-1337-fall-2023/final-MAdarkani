#include <iostream>
#include <cstdlib>
#include <ctime>
#include "die.h"
#include "shooter.h"
#include "roll.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main() 
{
	srand(time(0));

	Die die1;
	Die die2;
	Shooter shooter(die1, die2);

	Roll* roll = shooter.throw_die();

	ComeOutPhase come_out_phase;

	while (come_out_phase.get_outcome(roll) == RollOutcome::natural || come_out_phase.get_outcome(roll) == RollOutcome::craps)
	{
		std::cout << "Rolled "<< roll->roll_value() << " roll again\n";
		roll = shooter.throw_die();
	}

	std::cout << "Rolled "<< roll->roll_value() << " Start of point phase.\nRoll until "<< roll->roll_value() << " or a 7 is rolled.\n";


	int point = roll->roll_value();

	roll = shooter.throw_die();

	PointPhase point_phase(point);

	while (point_phase.get_outcome(roll) == RollOutcome::point || point_phase.get_outcome(roll) == RollOutcome::nopoint)
	{
		std::cout << "Rolled "<< roll->roll_value() << " roll again\n";
		roll = shooter.throw_die();		
	}

    std::cout << "Rolled " << roll->roll_value() << " end of point phase\n";

    std::cout << shooter;
	return 0;
}