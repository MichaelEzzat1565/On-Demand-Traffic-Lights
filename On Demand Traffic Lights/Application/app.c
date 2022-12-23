/*
 * app.c
 *
 * Created: 12/2/2022 12:54:47 PM
 *  Author: Michael Ezzat Tanyous
 */ 


#include "app.h"

// Global variable wil be used in the module
EN_Mode_t Mode_State = NORMAL;   // enum variable will be used to determine if the mode is normal or pedesterian
EN_CarsLEDsState_t cars_LEDs_State;  // enum variable will be used to detertmine if cars' green led is on or off

/******************** functions' implementations *****************************/
/* 1.this function will initialize sys. peripherals , LEDs ,
Button , Timer and External Interrupt */
void APP_init(void)
{
	// 1.initialize LEDs' pins
	LED_init(LED_CarsGreen_PIN, LED_CarsGreen_PORT);
	LED_init(LED_CarsYellow_PIN, LED_CarsYellow_PORT);
	LED_init(LED_CarsRed_PIN, LED_CarsRed_PORT);
	LED_init(LED_PedsGreen_PIN, LED_PedsGreen_PORT);
	LED_init(LED_PedsYellow_PIN, LED_PedsYellow_PORT);
	LED_init(LED_PedsRed_PIN, LED_PedsRed_PORT);
	//2.initialize Buutton pin
	BUTTON_init(BUTTON_1_PIN, BUTTON_1_PORT);
	/* 3. Enable global interrupt -> setting bit 7 in the status register SREG to 1*/
	sei();
	/* 4. choose the External Interrupt sense - Sense on rising Edge */
	MCUCR |= (1<<0) | (1<<1);
	/* 5.Enable External Interrupt INT0*/
	GICR |=(1<<6);
	//6.set timer configurations
  	Timer0_init(Normal_Mode);	
	
}

/* 1. This is system's app function ,it will be used to make normal mode is the default mode
      of the system 
   2. And if the External Interrupt flag is set if the user pressed the button it will change the 
      mode to pedestrian mode
   3. In the normal mode pedestrian's red LED will be on always and cars' LEDs will on for five seconds
      starting from the green LED to blinking the yellow and finaly the red LED will be on for five seconds before
      the yellow LED back to blink then going back to the green ...etc
   4. In pedestrian mode there are two states : 
          A. If pressed the button when Cars' green LED was off then cars' red LED and pedestrian green LED will be on 
             for five second so the pedestrians can cross the road
          B. If pressed the button when cars' green LED was on the the two yellow LED will blink for five secend before 
             cars' red LED and pedesterian green LED to be on for five secend so he can cross the road
   5. At the end of the two states of pedestrian mode the two yellow LEDs will be blink for five second
      then pedestrian green LED will be of before going back to the normal mode */
void APP_start(void)
{
   switch(Mode_State)
   {
	   case NORMAL:
	                   /*******************  Normal Mode  *********************/
		   LED_on(LED_PedsRed_PIN, LED_PedsRed_PORT);  // Pedestrian's red LED on
           Timer0_start(CLK_1024);    // start the timre by setting the prescaler
           LED_on(LED_CarsGreen_PIN, LED_CarsGreen_PORT);  // cars' green LED on for five seconds
		   if(Mode_State == PEDESTERIAN)   // check if a pedestrian pressed the button
		   {
			   break; // if pressed break the case to go to the pedestrian mode
		   }
           Timer0_Delay_NormalMode(5000 , CLK_1024);  // daelay 5000ms
           Timer0_stop();  // Timer stop
		   if(Mode_State == PEDESTERIAN)  // check if a pedestrian pressed the button
		   {
			   break;   // if pressed break the case to go to the pedestrian mode 
		   }
	       LED_5SEC_BLINK(LED_CarsYellow_PIN, LED_CarsYellow_PORT, &Mode_State);  // blink cars' yellow LED for five sec.
		   LED_off(LED_CarsGreen_PIN, LED_CarsGreen_PORT); // turn of cars' green LED
	       Timer0_start(CLK_1024);  // start the timre by setting the prescaler
	       LED_on(LED_CarsRed_PIN, LED_CarsRed_PORT);  //turn on cars' red LED
		   if(Mode_State == PEDESTERIAN)   // check if a pedestrian pressed the button
		   {
			   break;   // if pressed break the case to go to the pedestrian mode 
		   }
	       Timer0_Delay_NormalMode(5000 , CLK_1024);  //daelay 5000ms
	       Timer0_stop();  // Timer stop
		   if(Mode_State == PEDESTERIAN)  // check if a pedestrian pressed the button
		   {
			   break;  // if pressed break the case to go to the pedestrian mode
		   }
		   LED_5SEC_BLINK(LED_CarsYellow_PIN, LED_CarsYellow_PORT, &Mode_State);  // blink cars' yellow LED
		   LED_off(LED_CarsRed_PIN, LED_CarsRed_PORT); // turn of cars' red LED
		   break;  // break the case to start the normal mode from the begining
	case PEDESTERIAN:
	                        /******************* Pedestrian Mode ******************/
	     if(cars_LEDs_State == GREEN_OFF)   // first case : cars' green LED is Off
		 {
			  LED_off(LED_PedsRed_PIN, LED_PedsRed_PORT);  // turn of pedesterian's red LED
			  Timer0_start(CLK_1024);   // start the timer by setting the pre
			  LED_on(LED_CarsRed_PIN, LED_CarsRed_PORT);  // turn on cars' red LED
			  LED_on(LED_PedsGreen_PIN, LED_PedsGreen_PORT);  // turn on pedestrian's green LED
			  Timer0_Delay_NormalMode(5000 , CLK_1024);  // delay 5000 ms
			  Timer0_stop(); //stop the timer		  
			  LED_off(LED_CarsRed_PIN, LED_CarsRed_PORT);  // turn of cars' red LED
			  yellowLEDsblink();   // blink the two yellow LED for 5 sec.
			  LED_off(LED_PedsGreen_PIN, LED_PedsGreen_PORT);  //turn of pedestrian's green LED
			  Mode_State = NORMAL;  // change the mode to the normal mode
		 }
		 else if (cars_LEDs_State == GREEN_ON)  // second case : cars' green LED is on
		 {
             LED_on(LED_CarsGreen_PIN, LED_CarsGreen_PORT); // cars' green LED is still on
			 LED_off(LED_CarsRed_PIN, LED_CarsRed_PORT);  // turn off cars' red LED
			 yellowLEDsblink();  // blink the two yellow LEDs for five sec. while cars' green LED is on
			 LED_off(LED_PedsRed_PIN, LED_PedsRed_PORT);  // turn off pedestrian's red LED
			 LED_off(LED_CarsGreen_PIN, LED_CarsGreen_PORT);  // turn off cars' green LED
			 Timer0_start(CLK_1024);  // start the timer by setting the prescaler
			 LED_on(LED_CarsRed_PIN, LED_CarsRed_PORT);  // turn of cars' red LED
			 LED_on(LED_PedsGreen_PIN, LED_PedsGreen_PORT); // turn on pedestrian's green LED
			 Timer0_Delay_NormalMode(5000 , CLK_1024); // delay 5000 ms
			 Timer0_stop();  // stop the timer
			 yellowLEDsblink();  // blink the two yellow LEDs for 5 sec.
			 LED_off(LED_PedsGreen_PIN, LED_PedsGreen_PORT); // turn off pedestrian's green LED
			 LED_off(LED_CarsRed_PIN, LED_CarsRed_PORT);  // turn off cars' red LED
			 Mode_State = NORMAL;  // change the mode to the normal mode
		 }		 
	     break;  // break the case to chane the mode to the normal mode
   }	     
}

// Interrupt handelling if a pedesterian pressed the button
ISR(EXT_INT_0)
{
	Mode_State = PEDESTERIAN;  // change the mode to pedestrian mode
	readCarsLEDsState(&cars_LEDs_State);  // read cars' green LED is on or off
}

/* this function to blink an LED for 5 sec. , and while blinking it check if there is any 
   pedestrian pressed the button , if pressed it end the function to change the mode 
   to the pedestrian mode */
void LED_5SEC_BLINK(uint8_t ledPin ,uint8_t ledPort, EN_Mode_t* Mode_State)
{
	for(uint16_t i = 0; i < 10; i++) // 10 iter. (500 ms * 10 = 5 sec.) 500ms on and 500ms off
	{
		Timer0_start(CLK_1024);  // start the timer by setting the prescaler
		LED_toggle(ledPin, ledPort);  // toggle the LED
		Timer0_Delay_NormalMode(500 , CLK_1024); // daelay 500ms
		Timer0_stop();   // Timer stop
		if(*Mode_State == PEDESTERIAN) // check if a pedestrian pressed the button
		{
			LED_off(ledPin, ledPort);  // if pressed turn of the blinking LED
			return;  // end the function to get into the pedestrian mode
		}
	}
}

// this function to read cars' green LED state
void readCarsLEDsState(EN_CarsLEDsState_t* Cars_Green_LED)
{
	if((READ_BIT(PINA, PIN0) == 0)) // if the LED is off
	{
	   cars_LEDs_State = GREEN_OFF;  // put GREEN_OFF in the global enum variable
	}
	else if((READ_BIT(PINA, PIN0) == 1))  // if the LED is on
	{
	   cars_LEDs_State = GREEN_ON;  // put GREEN_ON in the global enum variable
	}
}

//this function is to blink the two yellow LEDs together at the same time for 5 sec.
void yellowLEDsblink(void)
{
	for(uint16_t i = 0; i < 10; i++)  // 10 iter. (500 ms * 10 = 5 sec.) 500ms on and 500ms off
	{
	   Timer0_start(CLK_1024);  // start the timer by setting the prescaler
	   LED_toggle(LED_CarsYellow_PIN, LED_CarsYellow_PORT);    // toggle cars' LED
	   LED_toggle(LED_PedsYellow_PIN, LED_PedsYellow_PORT);    // toggle pedestrains LED
	   Timer0_Delay_NormalMode(500 , CLK_1024); // 500 ms delay
	   Timer0_stop();  // stop the timer
	}
}

