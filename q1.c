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
int flag;

// Interrupt handler example for INT0
//
ISR(TIMER2_COMP_vect) {
   flag^=1;
}

// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//
//void my_function(void) {  // Put the open brace '{' here

  // asm("nop");          // Inline assembly example
//}

// ***********************************************************
// Main program
//
int main(void) {
	      DDRB=0x02;
	     TCNT2=0;
	     OCR2=156;
	     TCCR2|=(1<<CS22)|(1<<WGM21);
	     TIMSK|=(1<<OCIE2);
	     sei();

   while(1) {             // Infinite loop; define here the
   	if(flag)
   		PORTB=0x55 ;
   	else
   		PORTB=0xAA;
   		
//      my_function();      // system behaviour
   }

}


