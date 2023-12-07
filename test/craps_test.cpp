#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"

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
