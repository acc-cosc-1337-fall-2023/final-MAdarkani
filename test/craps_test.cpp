#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include <iostream>

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}


TEST_CASE("Die rolls return a value from 1 to 6") {
	Die die;

	for (int i=0; i<10; i++)
	{
		die.roll();
		int rolledValue = die.rolled_value();
		
		REQUIRE(rolledValue >= 1);
		REQUIRE(rolledValue <= 6);
	}
}


TEST_CASE("testing die roll with Roll class") {
	Die die1;
	Die die2;

	Roll roll(die1, die2);

	for (int i=0; i<10; i++)
	{
		roll.roll_die();
		
		int rolledValue = roll.roll_value();
		
		REQUIRE(rolledValue >= 2);
		REQUIRE(rolledValue <= 12);
	}
}


TEST_CASE("Test Shooter returns a Roll and roll values are between 2 and 12") {
    Die die1;
    Die die2;
    Shooter shooter(die1, die2);

    Roll* roll;
    for (int i = 0; i < 10; i++) {
		roll = shooter.throw_die();
        int roll_value = roll->roll_value();

        REQUIRE(roll != nullptr);
        REQUIRE(roll_value >= 2);
        REQUIRE(roll_value <= 12);
    }
}

TEST_CASE("Test ComeOutPhase get_outcome") {
    Die die1;
    Die die2;
    Shooter shooter(die1, die2);
    ComeOutPhase comeOutPhase;

    Roll* naturalRoll = shooter.throw_die();
    int naturalValues[] = {7, 11};
    naturalRoll->set_rolled_value(naturalValues[rand() % 2]);
    REQUIRE(comeOutPhase.get_outcome(naturalRoll) == RollOutcome::natural);

    Roll* crapsRoll = shooter.throw_die();
    int crapsValues[] = {2, 3, 12};
    crapsRoll->set_rolled_value(crapsValues[rand() % 3]);
    REQUIRE(comeOutPhase.get_outcome(crapsRoll) == RollOutcome::craps);

    Roll* pointRoll = shooter.throw_die();
    int pointValues[] = {4, 5, 6, 8, 9, 10};
    pointRoll->set_rolled_value(pointValues[rand() % 6]);
    REQUIRE(comeOutPhase.get_outcome(pointRoll) == RollOutcome::point);

}


TEST_CASE("Test PointPhase get_outcome") {
    Die die1;
    Die die2;
    Shooter shooter(die1, die2);

    PointPhase pointPhase(8);
    Roll* pointRoll = shooter.throw_die();
    pointRoll->set_rolled_value(8);
    REQUIRE(pointPhase.get_outcome(pointRoll) == RollOutcome::point);

    Roll* sevenOutRoll = shooter.throw_die();
    sevenOutRoll->set_rolled_value(7);
    REQUIRE(pointPhase.get_outcome(sevenOutRoll) == RollOutcome::seven_out);

    Roll* noPointRoll = shooter.throw_die();
    int noPointValues[] = {2, 3, 4, 5, 6, 9, 10, 11, 12};
    noPointRoll->set_rolled_value(noPointValues[rand() % 9]);
    REQUIRE(pointPhase.get_outcome(noPointRoll) == RollOutcome::nopoint);
}
