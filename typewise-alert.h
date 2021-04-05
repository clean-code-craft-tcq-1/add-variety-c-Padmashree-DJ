#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

typedef struct
{
	double lowerLimit;
	double upperLimit;
	CoolingType coolingTypeIdentifier;
}BreachLimits_tst;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL,
  TO_CONSOLE
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

typedef enum {

	SentToController,
	SentToEmail_Normal,
	SentToEmail_TooLow,
	SentToEmail_TooHigh,
	SentToConsole
} Successtype;
	
Successtype checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

Successtype sendToController(BreachType breachType);
Successtype sendToEmail(BreachType breachType);
Successtype sendToConsole(BreachType breachType);
Successtype TooLowmessage (const char* recepient);
Successtype Toohighmessage (const char* recepient);
Successtype NormalMessage (const char* recepient);