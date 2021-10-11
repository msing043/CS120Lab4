#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
enum Statemachine{Begin,Initializer,PressPound,YPressed, unlockDoor, lockDoor}SM;
void LockMachine(){
switch(SM) {
	case Begin:
		SM=Initializer;
		break;

	case Initializer:
		if((PINA&0x07)==0x04) {
			SM=PressPound;
		}
		else if ((PINA&0x87)==0x80) {
			SM=lockDoor;
		}
		else {
			SM=Initializer;
		}
		break;
		
	case PressPound:
		if((PINA&0x07)==0x04) {
                	SM=PressPound;
                }
                else {
                         SM=unlockDoor;
                }
                break;
	case YPressed:
		if ((PINA&0x07)==0x02) {
                         SM=unlockDoor;
                }
                else if(PINA==0x00) {
                         SM=unlockDoor;
		}
                else {
                         SM=Initializer;
                }
		break;
		
	case unlockDoor:
                if ((PINA&0x07)==0x02) {
                         SM=YPressed;
                }
                else {
                         SM=Initializer;
                }
                break;
	case lockDoor:
		if ((PINA&0x87)==0x80) {
                          SM=lockDoor;
                }
                else{
                          SM=Initializer;
                }
                break;
	default:
		SM=Begin;
		break;
	}
	switch(SM) {
	case Begin:
		PORTB=0x00;
		break;

	case Initializer:
		break;

	case PressPound:
		break;

	case YPressed:
		break;

	case unlockDoor:
		PORTB=0x01;
		break;

	case lockDoor:
		PORTB=0x00;
		break;
			
	default:
		PORTB=0x00;
		break;
		

	}
}

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    while (1) {
	LockMachine();
   	 }
         return 1;
	 }
