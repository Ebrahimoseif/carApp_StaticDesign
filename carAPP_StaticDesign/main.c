/*
 * carAPP_StaticDesign.c
 *
 * Created: 2020-02-17 10:24:13 AM
 * Author : EbrahimOseif
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include "Timer.h"
#include "DIO.h"
#include "PWM.h"
#include "ICU.h"

#include "car_sm.h"


extern struct DIO_Cfg_s dio;
extern struct DIO_Cfg_s pwm_io;
extern struct Pwm_Cfg_s pwm_cfg;



int main(void)
{
	 
	 Car_SM_Init();
	 
	 while(1){
		 
		 Car_SM_Update();
	 }
	 
	 
/*
		STEERING TEST 
		
		Steering_Init();
		while (1)
		{
Steering_SteerCar(CAR_FORWARD, 20);
_delay_ms(1000);
Steering_SteerCar(CAR_STOP, 20);

Steering_SteerCar(CAR_BACKWARD, 20);
_delay_ms(1000);	
Steering_SteerCar(CAR_STOP, 20);
 	
Steering_SteerCar(CAR_LEFT, 20);

_delay_ms(1000);
Steering_SteerCar(CAR_RIGHT, 20);
_delay_ms(1000);
Steering_SteerCar(CAR_STOP, 20);

}*/
		
		
		
		
	/* pwm test 
	Pwm_Init(&pwm_cfg);
	pwm_cfg.Channel = PWM_CH1A;
		Pwm_Init(&pwm_cfg);

	while(1){
		
		Pwm_Start(PWM_CH1B, 70 ,50);
		_delay_ms(1000);
		Pwm_Start(PWM_CH1A, 50 ,50);
			_delay_ms(1000);
	}
	*/

	/*

	dio test	
	 struct DIO_Cfg_s dio={
		 GPIOB, BIT4| BIT3, INPUT
		 };
		 DIO_init(&dio);

	 DIO_Cfg_s ddio={
		GPIOB, BIT6| BIT5|BIT7, OUTPUT
	};
		 DIO_init(&ddio);
	uint8_t data = 0;
			PORTD_DIR = 0xff;
			
	while(1){
		
		DIO_Write(GPIOB, BIT5,HIGH);
		_delay_ms(1000);
		DIO_Toggle(GPIOB, BIT6);
		_delay_ms(1000);
		
		DIO_Read(GPIOB,BIT2,&data);
		
		PORTD_DATA = data;
		if (data)
		{
						DIO_Write(GPIOB, BIT7,HIGH);

		}
	}*/
	
	
	
}
	
	/*uint8_t x;
	PORTB_DIR |= (1<<3);
	PORTB_DIR |= (1<<7)|(1<<6);
	Us_Init();
	Us_GetDistance(&x);
	//Car_SM_Init();
			
	while(1)
	{
		//Us_Trigger();
		//DIO_Write(GPIOB, PIN3, HIGH);
		PORTB_DATA |= (1<<3);
		_delay_ms(1);
		PORTB_DATA &= ~(1<<3);
		//DIO_Write(GPIOB, PIN3, LOW);
		_delay_ms(1);
		
		
			Us_GetDistance(&x);
if(x > 10)
{
	PORTB_DATA |= (1<<7);
	PORTB_DATA &= ~(1<<6);
	_delay_ms(10);
}
else
	{	
			PORTB_DATA |= (1<<6);
		PORTB_DATA &= ~(1<<7);
		_delay_ms(10);

}		//Car_SM_Update();

		
	}
	
}

/ *
ISR(INT2_vect)
{
		PORTA_DIR = 0xff;
		PORTA_DATA = 0xff;
		//DIO_Write(0, FULL_PORT, HIGH);
}
* /*/


