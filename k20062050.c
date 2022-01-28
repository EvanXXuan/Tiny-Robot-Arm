#include "librobot.h"

#include <stdio.h>

void init_button_sensor(void){
	/* --------------- Begin Answer to Task 1a Here ------------ */
	DDRD = 0b10000000;
	PORTD = 0b11111111;
	/* --------------- End Answer to Task 1a Here -------------- */
	return;
}

int read_button_sensor(void){
	int pressed;
	/* --------------- Begin Answer to Task 1b Here ------------ */
	if(PIND & 0b10000000)
		pressed = 1;
	else
		pressed = 0;
	/* --------------- End Answer to Task 1b Here -------------- */
	return pressed;
}

float read_knob_sensor(int knob){
	float reading = 0; /* Sensor reading, normalised
						  (i.e., scaled) to be between 
						  zero and one. */
	/* --------------- Begin Answer to Task 2 Here ------------ */
	if(knob == 1){
		ADMUX = 0b01100001;//read ADC 1
	}
	else{
		ADMUX = 0b01100000;//read ADC 0
	}
	ADCSRA |= (1<<ADSC);//start conversion
	while(ADCSRA & (1<<ADSC))//wait until conversion is done
		;
	reading = ADCH/255.0;// transfer to value between 0~1
	/* --------------- End Answer to Task 2 Here -------------- */
	return reading;
}


void init_arm_motors(void) {
	/* --------------- Begin Answer to Task 3 Here ------------ */
	
	DDRB = (1<<PB1)|(1<<PB2);// PB1 and PB2 is set as output
	TCCR1A |= (1 << COM1A1)|(1 << COM1B1);// set none-inverting mode
	TCCR1A |= (1 << WGM11);
	TCCR1B |= (1 << WGM12)|(1 << WGM13);// set fast PWM Mode use ICR1 as TOP
	TCCR1B |= (1 << CS11);//starts PWM with prescaler 8
	
	ICR1 = 39999;//TOP 
	/* --------------- End Answer to Task 3 Here -------------- */
	return;
}


