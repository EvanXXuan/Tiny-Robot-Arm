#include<avr/io.h>

int main(){
	DDRD = 0xFF;
	PORTD = 0x00;
	
	DDRC = 0x00;
	
	ADMUX = (1<<REFS0);
	ADMUX |= (1<<ADLAR);
	ADMUX |= (1<<MUX0);
	
	ADCSRA = (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	ADCSRA |= (1<<ADEN);
	
	while(1){
		
		ADCSRA |= (1<<ADSC);
		while(ADCSRA & (1<<ADSC))
			;
		PORTD = ADCH;
		
		
	}
	
	return 0;
	
}