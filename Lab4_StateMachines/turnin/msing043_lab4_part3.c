#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
enum States {Start,Initial,PressPound,PressY, Unlock, Lock}SM;
void timerTick(){
	switch(SM) {
		case Start:
			SM=Initial;
			break;

		case Initial:
			if((PINA & 0x07)==0x04) {
				SM=PressPound;
			}
			else if ((PINA & 0x87)==0x80) {
				SM=Lock;
			}
			else {
				SM=Initial;
			}
			break;

		case PressPound:
			if((PINA & 0x07)==0x04) {
                                SM=PressPound;
                        }
                        else {
                                SM=Unlock;
                        }
                        break;
	     case PressY:
                        if ((PINA & 0x07)==0x02) {
                                SM=Unlock;
                        }
                        else if(PINA ==0x00) {
                                SM=Unlock;
                        }
                        else {
                                SM=Initial;
                        }
                        break;
		case Unlock:
                        if ((PINA & 0x07)==0x02) {
                                SM=PressY;
                        }
                        else {
                                SM=Initial;
                        }
                        break;
		case Lock:
			if ((PINA & 0x87) == 0x80) {
                                SM=Lock;
                        }
                        else{
                                SM=Initial;
                        }
                        break;
	}
	switch(SM) {
		case Start:
			PORTB=0x00;
			break;

		case Initial:
			break;

		case PressPound:
			break;

		case PressY:
			break;

		case Unlock:
			PORTB=0x01;
			break;

		case Lock:
			PORTB=0x00;
			break;

	}
}

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    while (1) {
	timerTick();
   	 }
         return 1;
	 }
