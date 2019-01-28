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
ISR(TIMER2_COMP_vect) {

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
	DDRB=0xFF;
	//PORTB=0x00;
	TCNT2=0;
	OCR2=125;
	TCCR2=(1<<CS21) | (1<<WGM20) | (1<<WGM21) |(1<<COM20) | (1<<COM21);
	TIMSK=(1<<OCIE2);

   while(1) {             // Infinite loop; define here the
   	
      					//my_function();      // system behaviour
   }

}


