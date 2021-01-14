#include "init_library.h"


void port_setup(void) {
	
	DDRD = 0b11111111;
	DDRC = 0b00000000;
	PORTC = 0b00110000;

}

void counter_setup(void) {
	TIMSK = 0b00000000;
	TCCR0 = 0b00000010; //    clk/8
	TIMSK = TIMSK | 0b00000001;

	TCCR2 = 0b00000100; //
	ASSR  = 0b00001000; //
	TIMSK = TIMSK | 0b01000000;
	
}
	

