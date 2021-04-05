#include "typewise-alert.h"
#include <stdio.h>

Successtype (*EmailMessage[])(const char* recepient)={NormalMessage,TooLowmessage,Toohighmessage};

/**
 ***************************************************************************************************
 * Function Name: TooLowmessage 
 * 
 * Function Description: TooLowmessage is called in the context of sendToEmail() based on the breachtype and input alertTarget.
 *
 * \param  Inputs:- const char* recepient
 *					
 *		   Outputs:- None
 *         
 * \return  Successtype  (ENUM) 
 *          
 * \retval  SentToEmail_TooLow:- Which depicts that sendToEmail() function successfully alerted the Too_low message to email.
 ***************************************************************************************************
 */
 
Successtype TooLowmessage (const char* recepient)
{
	printf("To: %s\n", recepient);
    printf("Hi, the temperature is too low\n");
    return SentToEmail_TooLow;
}

/**
 ***************************************************************************************************
 * Function Name: Toohighmessage 
 * 
 * Function Description: Toohighmessage is called in the context of sendToEmail() based on the breachtype and input alertTarget.
 *
 * \param  Inputs:- const char* recepient
 *					
 *		   Outputs:- None
 *         
 * \return  Successtype  (ENUM) 
 *          
 * \retval  SentToEmail_TooHigh:- Which depicts that sendToEmail() function successfully alerted the Too_high message to email.
 ***************************************************************************************************
 */
Successtype Toohighmessage (const char* recepient)
{
	printf("To: %s\n", recepient);
    printf("Hi, the temperature is too high\n");
    return SentToEmail_TooHigh;
}

/**
 ***************************************************************************************************
 * Function Name: NormalMessage 
 * 
 * Function Description: NormalMessage is called in the context of sendToEmail() based on the breachtype and input alertTarget.
 *
 * \param  Inputs:- const char* recepient
 *					
 *		   Outputs:- None
 *         
 * \return  Successtype  (ENUM) 
 *          
 * \retval  SentToEmail_Normal:- Which depicts that sendToEmail() function successfully alerted the Normal message to email.
 ***************************************************************************************************
 */
Successtype NormalMessage (const char* recepient)
{
	printf("To: %s\n", recepient);
    printf("Hi, the temperature is normal\n");
    return SentToEmail_Normal;
}
	

