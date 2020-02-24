/*
 * car_sm.c
 *
 * Created: 2020-02-19 9:20:53 AM
 *  Author: EbrahimOseif
 */ 

/************************************************************************/
/*				 INCLUDES										        */
/************************************************************************/

#include <stdlib.h>
#include "car_sm.h"



/************************************************************************/
/*				 Global / Static Variables						       */
/************************************************************************/

static uint8_t gu8_State = Stop;
static uint8_t gu8_Distance = 0, gu8_Speed = 25;


/************************************************************************/
/*		         TIMER FUNCTIONS' implementation				        */
/************************************************************************/

/*
 * Fun----------: ERROR_STATUS Car_SM_Init(void);
 * Input--------: Nothing
 * Output-------: Nothing
 * Return-------: ERROR_STATUES
 * -------------- #E_Ok	->function operation is okay, no error
 * -------------- #E_Nok->function operation faild, error exists
 * Description--: Initiate the car state machine with state"forward at speed 80%",
 * -------------- And initiate steering and ultrasonic functions
*/
ERROR_STATUS Car_SM_Init(void)
{
	ERROR_STATUS u8_status = E_OK;
	
		/* initialize steering and Ultrasonic */
		u8_status = Steering_Init();
		u8_status = Us_Init();
	
	return u8_status;
}

/*
 * Fun----------: ERROR_STATUS Car_SM_Update(void);
 * Input--------: Nothing
 * Output-------: Nothing
 * Return-------: ERROR_STATUES
 * -------------- #E_Ok	->function operation is okay, no error
 * -------------- #E_Nok->function operation faild, error exists
 * Description--: changes car state according to the ultrasonic input
 * -------------- And represents the motors output for each state
*/



ERROR_STATUS Car_SM_Update(void)
{
	ERROR_STATUS u8_status = E_OK;

	while(1)
	{
		/* Read The Distance From The Ultrasonic Using swICU */
		
		u8_status =  Us_Trigger();
		
		 softwareDelayMs(1);
		
	    u8_status = Us_GetDistance(&gu8_Distance);
		
		
		/* Decide Which State To Move Our System Into */
		
		if(gu8_Distance < 30 )
			gu8_State = Back;
		
		else if((gu8_Distance >= 30) && (gu8_Distance <= 35))
		gu8_State = Right;
		
		else if(gu8_Distance >= 35 )
		gu8_State = Move;
		
		else
		gu8_State = Move;
		
		/* switch on the state calculated by distance */
		
		switch(gu8_State)
		{
			case Move:
					Steering_SteerCar(CAR_FORWARD, gu8_Speed);
					break;
			
			case Back:
					Steering_SteerCar(CAR_BACKWARD, gu8_Speed);
					break;
			
			case Right:
					Steering_SteerCar(CAR_RIGHT, gu8_Speed);
					break;
			
			case Left:
					Steering_SteerCar(CAR_LEFT, gu8_Speed);
					break;
			
			default:
					Steering_SteerCar(CAR_STOP, gu8_Speed);
			
		}
		softwareDelayMs(30);
	}
	
	return u8_status;
}