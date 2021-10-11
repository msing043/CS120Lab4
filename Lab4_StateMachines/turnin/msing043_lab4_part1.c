/*	Author: msing043
 *	Assignment: Lab #4  Exercise #1
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
enum StateMachine{Begin, Depressed, PressWait, Depressed, DepressedWait} SM;
void buttonMachine(){
switch (SM) {
	case Begin:
	SM=Pressed;
break;
case Press:
	if ((PINA&0x01)==0x01) {
		SM=Press;
		}
		else {
		SM=PressWait;
		}
                break;
case PressWait:
	if ((PINA&0x01)==0x01) {
        	 SM=Depressed;
                 }
                 else {
                 SM=PressWait;
                 }
                 break;
case Depressed:
	if((PINA&0x01)==0x01) {
		SM=Depressed;
		}
		else {
		SM=DepressedWait;
		}
		break;
case DepressedWait:
	if((PINA&0x01)==0x01){
		SM=Press;
		}
		else{
		SM=DepressedWait;
		}
		break;
default:
SM=Begin;
break;
}
switch (SM){
case Begin:
PORTB=0x01;
break;

case Press:
PORTB=0x02;
break;

case PressWait:
break;

case Depressed:
PORTB=0x01;
break;

case DepressedWait:
break;

default:
PORTB=0x01;
break;
	}
}
int main(){
   DDRA = 0x00; PORTA = 0xFF;
   DDRB = 0xFF; PORTB = 0x00;
    while (1) {
    buttonMachine();
	}
	return 1;
	}
