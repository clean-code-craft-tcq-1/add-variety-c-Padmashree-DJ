#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits for Low case") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits for high case") {
  REQUIRE(inferBreach(30, 0, 20) == TOO_HIGH);
}

TEST_CASE("infers the breach according to limits for normal case") {
  REQUIRE(inferBreach(12, 10, 20) == NORMAL);
}

TEST_CASE("infers the breach according to limits in HI_ACTIVE_COOLING for NORMAL case") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 40) == NORMAL);
}

TEST_CASE("infers the breach according to limits in PASSIVE_COOLING for TOO_LOW case") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -4) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits in MED_ACTIVE_COOLING for TOO_HIGH case") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 60) == TOO_HIGH);
}

TEST_CASE("Check and alert functionality check to controller in case of PASSIVE_COOLING:NORMAL") {
	 BatteryCharacter batterycharname= {PASSIVE_COOLING, "BMS"};
    REQUIRE( checkAndAlert(TO_CONTROLLER, batterycharname, 30)== SentToController);
}

TEST_CASE("Check and alert functionality check to email in case of PASSIVE_COOLING:NORMAL") {
	 BatteryCharacter batterycharname= {PASSIVE_COOLING, "BMS"};
     REQUIRE(checkAndAlert(TO_EMAIL, batterycharname, 30)==SentToEmail_Normal);
}

TEST_CASE("Check and alert functionality check to email in case of PASSIVE_COOLING:TOO_LOW") {
	 BatteryCharacter batterycharname= {PASSIVE_COOLING, "BMS"};
     REQUIRE(checkAndAlert(TO_EMAIL, batterycharname, -4)==SentToEmail_TooLow);
}

TEST_CASE("Check and alert functionality check to email in case of PASSIVE_COOLING:TOO_HIGH") {
	 BatteryCharacter batterycharname= {PASSIVE_COOLING, "BMS"};
     REQUIRE(checkAndAlert(TO_EMAIL, batterycharname, 50)==SentToEmail_TooHigh);
}

TEST_CASE("Check and alert functionality check to email in case of HI_ACTIVE_COOLING:NORMAL") {
	 BatteryCharacter batterycharname= {HI_ACTIVE_COOLING, "BMS"};
     REQUIRE(checkAndAlert(TO_CONSOLE, batterycharname, 30)==SentToConsole);
}

