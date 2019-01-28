// ***********************************************************
// Project:
// Author:
// Module description:
// ***********************************************************

#include <avr\io.h>              // Most basic include files
#include <avr\interrupt.h>       // Add the necessary ones
#include <avr\signal.h>          // here

// Define here the global static variables
//
int My_global;

// Interrupt handler example for INT0
//
ISR(ADC_vect) {
		 PORTB=ADCL;
		 PORTD=ADCH;
	 ADCSRA |= (1<<ADSC);

}

// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//
void my_function(void) {  // Put the open brace '{' here

   asm("nop");          // Inline assembly example
}

// ***********************************************************
// Main program
//
int main(void) {
	DDRB=0xFF;
	DDRD=0xFF;
	DDRC=0x00;
//	PORTC=0x01;
	ADMUX = (1<<REFS0);
	ADCSRA |=  (1<<ADPS1) | (1<<ADPS0);
	ADCSRA |= (1<<ADIE) | (1<<ADSC) | (1<<ADEN);
	
	sei();	

   while(1) {             // Infinite loop; define here the
    // my_function();      // system behaviour
   }

}

