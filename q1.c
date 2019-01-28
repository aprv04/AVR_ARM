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
void uart_init(void)
{
	UBRRL=0x33;
	UCSRB=(1<<TXEN) | (1<<RXEN);
	UCSRC=(1<<UCSZ0) | (1<<UCSZ1) | (1<<URSEL);
	
}
void uart_send(unsigned char c)
{
	while(!(UCSRA & (1<<UDRE)));
	UDR=c;
}
int main(void) {
     uart_init() ;
     unsigned char c;
   while(1) {             // Infinite loop; define here the
     // my_function();      // system behaviour
     while(!(UCSRA & (1<<RXC)));
     c=UDR;
     c+=1;
     uart_send(c);
   }
    return 0;
}

