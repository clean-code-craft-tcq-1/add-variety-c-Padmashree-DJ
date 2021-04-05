#include "typewise-alert.h"
#include <stdio.h>

Successtype (*AlertTargetFunc[])(BreachType breachType)={	sendToController,sendToEmail, sendToConsole};

/**
 ***************************************************************************************************
 * Function Name: checkAndAlert 
 * 
 * Function Description: Checks the temperature breach based on cooling type and temeperature in degree celcius and alerts to all the target devices.
 *
 * \param  Inputs:- AlertTarget alertTarget
 *					BatteryCharacter batteryChar
 *					double temperatureInC
 *					
 *		   Outputs:- None
 *         
 * \return  Successtype  (ENUM) 
 *          
 * \retval  CheckAndAlertSuccess:- Succcess parameter which points to Successtype ENUM based on alert target.
 ***************************************************************************************************
 */

Successtype checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{
   BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
   Successtype CheckAndAlertSuccess =(*AlertTargetFunc[alertTarget])(breachType);
   return CheckAndAlertSuccess;
}

/**
 ***************************************************************************************************
 * Function Name: sendToController 
 * 
 * Function Description: SentToController is called in the context of checkAndAlert() based on the breachtype and input alertTarget.
 *
 * \param  Inputs:- BreachType breachType
 *					
 *		   Outputs:- None
 *         
 * \return  Successtype  (ENUM) 
 *          
 * \retval  SentToController:- Which depicts that checkAndAlert() function successfully alerted the tartget device,Controller.
 ***************************************************************************************************
 */

Successtype sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  return SentToController;
}

/**
 ***************************************************************************************************
 * Function Name: sendToEmail 
 * 
 * Function Description: sendToEmail is called in the context of checkAndAlert() based on the breachtype and input alertTarget.
 *
 * \param  Inputs:- BreachType breachType
 *					
 *		   Outputs:- None
 *         
 * \return  Successtype  (ENUM) 
 *          
 * \retval  SendToEmailSuccess:- Which depicts that checkAndAlert() function successfully alerted the tartget device,Email.
 ***************************************************************************************************
 */
Successtype sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  Successtype SendToEmailSuccess=(*EmailMessage[breachType])(recepient);
  return SendToEmailSuccess;
}

/**
 ***************************************************************************************************
 * Function Name: sendToConsole 
 * 
 * Function Description: sendToConsole is called in the context of checkAndAlert() based on the breachtype and input alertTarget.
 *
 * \param  Inputs:- BreachType breachType
 *					
 *		   Outputs:- None
 *         
 * \return  Successtype  (ENUM) 
 *          
 * \retval  SentToConsole:- Which depicts that checkAndAlert() function successfully alerted the tartget device,the Console.
 ***************************************************************************************************
 */
Successtype sendToConsole(BreachType breachType) {
  printf("the temperature is %x \n", breachType);
  return SentToConsole;
}

