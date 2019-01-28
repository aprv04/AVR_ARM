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
        flag^=1;
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
		DDRD=0x10;
		PORTD=0x04;
      GICR=(1<<INT0);
      sei();
   while(1) {             // Infinite loop; define here the
     // my_function();      // system behaviour
        if(flag)
        		PORTD=0x04;
        else
        		PORTD=0x14;
   }

}

