#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
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