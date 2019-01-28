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
int flag1,flag2;

// Interrupt handler example for INT0
//
ISR(TIMER2_COMP_vect) {
				 flag1^=1;
				 flag2++;
				 if(flag2>3)
	  			 	flag2=0;
}

// It is recommended to use this coding style to
// follow better the mixed C-assembly code in the
// Program Memory window
//
//void my_function(void) {  // Put the open brace '{' here

 //  asm("nop");          // Inline assembly example
//}

// ***********************************************************
// Main program
//
int main(void) {
		TCNT2=0;
		OCR2=156;
		TCCR2=(1<<CS22) | (1<<WGM21) ;
		TIMSK=(1<<OCIE2);
		DDRB=0xFF;
		DDRD=0xFF;
		sei();

   while(1) {            // Infinite loop; define here the
     if(flag1)
     	PORTD=0xFF;
     	else
     	PORTD=0x00;
     	if(flag2<=1)
     		PORTB=0xFF;
      else
     		PORTB=0x00;
			
	}

}


