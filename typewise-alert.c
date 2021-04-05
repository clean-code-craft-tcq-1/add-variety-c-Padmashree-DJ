#include "typewise-alert.h"
#include <stdio.h>

BreachLimits_tst BreachLimitArr[]={{0,35, PASSIVE_COOLING},{0,45,HI_ACTIVE_COOLING},{0,40,MED_ACTIVE_COOLING}}; 

/**
 ***************************************************************************************************
 * Function Name: inferBreach
 * 
 * Function Description: Infers the breach type of the value based on the lowerLimit and upperLimit .
 *
 * \param  Inputs:- double value
 *					double lowerLimit
 *					double upperLimit
 *					
 *		   Outputs:- None
 *         
 * \return  BreachType (ENUM)
 *          
 * \retval  NORMAL:- Input Value is within normal range given.
 *          TOO_LOW:- Input Value falls below lower limit given.
 *          TOO_HIGH:-Input Value is above upper limit given.
 ***************************************************************************************************
 */
BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

/**
 ***************************************************************************************************
 * Function Name: classifyTemperatureBreach
 * 
 * Function Description: Classifies the temperature breach based on cooling type and temeperature in degree celcius .
 *
 * \param  Inputs:- CoolingType coolingType
 *					double temperatureInC
 *					double upperLimit
 *					
 *		   Outputs:- None
 *         
 * \return  BreachType (ENUM)
 *          
 * \retval  NORMAL:- Input Value is within normal range given.
 *          TOO_LOW:- Input Value falls below lower limit given.
 *          TOO_HIGH:-Input Value is above upper limit given.
 ***************************************************************************************************
 */
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
  return inferBreach(temperatureInC, BreachLimitArr[coolingType].lowerLimit, BreachLimitArr[coolingType].upperLimit);
}

