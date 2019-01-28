; **********D********************************************
; BASIC .ASM template file for AVR
; ******************************************************

.include "C:\VMLAB\include\m8def.inc"

; Define here the variables
;
.def  temp  =r16

; Define here Reset and interrupt vectors, if any
;
reset:
   rjmp start
   reti      ; Addr $01
   reti      ; Addr $02
   reti      ; Addr $03
   reti      ; Addr $04
   reti      ; Addr $05
   reti      ; Addr $06        Use 'rjmp myVector'
   reti      ; Addr $07        to define a interrupt vector
   reti      ; Addr $08
   reti      ; Addr $09
   reti      ; Addr $0A
   reti      ; Addr $0B        This is just an example
   reti      ; Addr $0C        Not all MCUs have the same
   reti      ; Addr $0D        number of interrupt vectors
   reti      ; Addr $0E
   reti      ; Addr $0F
   reti      ; Addr $10

; Program starts here after Reset
;
start:
   nop       ; Initialize here ports, stack pointer,
   nop       ; cleanup RAM, etc.
   nop       ;
   nop       ;

				LDI r16,low(RAMEND)
				OUT SPL,r16
				LDI r16,high(RAMEND)
				OUT SPH,R16
				
				LDI r16,0x40
				OUT DDRD,r16
				
repeat:
 			   LDI r16,0x55
 			   OUT DDRD,R16
 			   call delay
 			
 				LDI R16,0xaa
 				OUT DDRD,R16
 				call delay
 				rjmp repeat
 				
delay:
				LDI R17,10
loop:			LDI R18,255
loop1:		LDI R19,255 	
loop2:		dec r19
				brne loop2
				dec r18
				brne loop1
				dec r17
				brne loop
				ret
								
