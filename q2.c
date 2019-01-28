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
volatile int flag;

// Interrupt handler example for INT0
//
ISR(INT0_vect) {
   // TCNT2=0;
    OCR2=125;
}
ISR(INT1_vect) {
   // TCNT2=0;
    OCR2=250 ;
}
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
	TCCR2=(1<<CS21)|(1<<WGM21);
	TCNT2=0;
	OCR2=250;
	TIMSK=(1<<OCIE2);
	GICR=(1<<INT0)|(1<<INT1);
	sei();
	DDRB=0xFF;
	DDRD=0x00;
	PORTD=0xFF;
	

   while(1) {             // Infinite loop; define here the
 				if(flag)
 					PORTB=0x55;
 				else
 					PORTB=0xAA;
 //   my_function();      // system behaviour
   }

}


