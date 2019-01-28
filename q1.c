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
SIGNAL(SIG_INTERRUPT0) {

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

		DDRB=(1<<3) | (1<<5);
		DDRD=0xFF;
		SPCR=(1<<SPE) | (1<<MSTR) | (1<<SPR0);
		while(1) {
			SPDR='F';
			while(!SPSR & (1<<SPIF));
			
			PORTD=SPDR;
		}
		return 0;

}





