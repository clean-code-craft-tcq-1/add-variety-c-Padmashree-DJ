#include "typewise-alert.h"
#include <stdio.h>

BreachLimits_tst BreachLimitArr[]={{0,35, PASSIVE_COOLING},{0,45,HI_ACTIVE_COOLING},{0,40,MED_ACTIVE_COOLING}}; 

Successtype (*AlertTargetFunc[])(BreachType breachType)={	sendToController,sendToEmail, sendToConsole};

Successtype (*EmailMessage[])(const char* recepient)={NormalMessage,TooLowmessage,Toohighmessage};

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
  return inferBreach(temperatureInC, BreachLimitArr[coolingType].lowerLimit, BreachLimitArr[coolingType].upperLimit);
}



Successtype checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{
   BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
   Successtype CheckAndAlertSuccess =(*AlertTargetFunc[alertTarget])(breachType);
   return CheckAndAlertSuccess;
}

Successtype sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  return SentToController;
}

Successtype sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  Successtype SendToEmailSuccess=(*EmailMessage[breachType])(recepient);
  return SendToEmailSuccess;
}

Successtype sendToConsole(BreachType breachType) {
  printf("the temperature is %x \n", breachType);
  return SentToConsole;
}

Successtype TooLowmessage (const char* recepient)
{
	printf("To: %s\n", recepient);
    printf("Hi, the temperature is too low\n");
    return SentToEmail_TooLow;
}

Successtype Toohighmessage (const char* recepient)
{
	printf("To: %s\n", recepient);
    printf("Hi, the temperature is too high\n");
    return SentToEmail_TooHigh;
}

Successtype NormalMessage (const char* recepient)
{
	printf("To: %s\n", recepient);
    printf("Hi, the temperature is normal\n");
    return SentToEmail_Normal;
}
	

