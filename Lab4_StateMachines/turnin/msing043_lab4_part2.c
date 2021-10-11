/*	Author: msing043
 *	Assignment: Lab #4  Exercise #1
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum stateMachine{Begin,Standby,Initializer,Reset,Addition,Subtraction}SM;
void buttonMachine() {
	switch(SM) {
	case Begin:
		PORTC=0x07;
		SM=Initializer;
		break;
	case Standby:
		SM=Initializer;
		break;
			
	case Initializer:
		if((PINA&0x03)==0x03) {
                        SM=Reset;
                }
		else if((PINA&0x01)==0x01) {
			SM=Addition;
		}
		else if((PINA&0x02)==0x02) {
                        SM=Subtraction;
                }
		else if(PINA==0){
			SM=Standby;
		}
		break;

	case Reset:
		if((PINA & 0x03)==0x03) {
			SM=Reset;
		}
		else{
			SM=Standby;
		}
		break;
		
	case Addition:
		if((PINA & 0x01)==0x01) {
	        	SM=Addition;
                }
                else{
        	        SM=Standby;
                }
                break;
			
	case Subtraction:
                if((PINA & 0x02)==0x02) {
    	            SM=Subtraction;
                }
                else{
     	           SM=Standby;
                    }
                break;
	default:
		SM=Begin;
		break;
	}
	
	
	switch(SM){
	case Begin:
	PORTC=0x07;
	break;
			
	case Standby:
	break;

	case Initializer:
	break;

	case Addition:
	if(PORTC<0x09){
        PORTC=PORTC+1;
	}
        break;	
			
	case Subtraction:
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
	buttonMachine();
   	 }
   	 return 1;
	}

