/*	Author: msing043
 *	Assignment: Lab #4  Exercise #1
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
enum SM_1{Initial, Pressed, PressWait, Depressed, DepressedWait} SM;
void timerTick(){
switch (SM) {
	case Initial:
	SM=Pressed;
break;
case Pressed:
	if ((PINA & 0x01) == 0x01) {
		SM=Pressed;
		}
		else {
		SM=PressWait;
		}
                break;
case PressWait:
	if ((PINA & 0x01) == 0x01) {
        	 SM=Depressed;
                 }
                 else {
                 SM=PressWait;
                 }
                 break;
case Depressed:
	if((PINA & 0x01)== 0x01) {
		SM=Depressed;
		}
		else {
		SM=DepressedWait;
		}
		break;
case DepressedWait:
	if((PINA & 0x01)==0x01){
		SM=Pressed;
		}
		else{
		SM=DepressedWait;
		}
		break;
default:
SM=Initial;
break;
}
switch (SM){
case Initial:
PORTB=0x01;
break;

case Pressed:
PORTB=0x01;
break;

case PressWait:
break;

case Depressed:
PORTB=0x02;
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
    timerTick();
	}
	return 1;
	}
