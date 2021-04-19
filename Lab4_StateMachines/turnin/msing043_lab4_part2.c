/*	Author: msing043
 *	Assignment: Lab #4  Exercise #1
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum SM_1{Initial,Start,Reset,Add,Subtract,AddOne,SubtractOne}SM;
void timerTick() {
	switch(SM) {
	case Initial:
		SM=Start;
		break;
	case Start:
		if((PINA & 0x03)==0x03) {
                        SM=Reset;
                }
		else if((PINA & 0x01)==0x01) {
			SM=AddOne;
		}
		else if((PINA & 0x02)==0x02) {
                        SM=SubtractOne;
                }
		break;

	case Reset:
		if((PINA & 0x03)==0x03) {
			SM=Reset;
		}
		else{
			SM=Initial;
		}
		break;
		
	case Add:
		if((PINA & 0x01)==0x01) {
	        	SM=Add;
                }
                else{
        	        SM=Initial;
                }
                break;

	case AddOne:
		SM=Add;
		break;
			
	case Subtract:
                if((PINA & 0x02)==0x02) {
    	            SM=Subtract;
                }
                else{
     	           SM=Initial;
                    }
                break;
	
	case SubtractOne:
		SM=Subtract;
		break;
			
	default:
		SM=Initial;
		break;
	}
	switch(SM){
	case Initial:
	PORTC=0x07;
	break;

	case Start:
	break;

	case Add:
	break;

	case Subtract:
	break;

	case AddOne:
	if(PORTC<0x09){
        PORTC=PORTC+1;
	}
        break;
		
	case SubtractOne:
	if(PORTC>0x00){ 
        PORTC=PORTC-1;
	}
        break;
	
	case Reset:
	PORTC=0x00;
	break;
	
	default:
	PORTC=0x07;
	break;
	}
}
int main() {
    DDRA=0x00; PORTA=0xFF;
    DDRC=0xFF; PORTC=0x00;
    while (1) {
	timerTick();
   	 }
   	 return 1;
	}

