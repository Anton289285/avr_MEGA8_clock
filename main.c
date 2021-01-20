#include <avr/io.h>
#include <avr/interrupt.h>


#ifndef COMMON_LIBRARY
	#define COMMON_LIBRARY
	#include "common_library.h"
#endif

#ifndef INIT_LIBRARY
	#define INIT_LIBRARY
	#include "init_library.h"
#endif

#ifndef BUTTON_HANDLER_LIBRARY
    #define BUTTON_HANDLER_LIBRARY
    #include "button_handler_library.h"
#endif
	
unsigned char seconds = 0;
unsigned char minuts = 33;
unsigned char hours = 11;
unsigned char sev_segm_digit[4];
unsigned char global_counter = 0;
unsigned char dot_digit; 
unsigned char *link_to_array_digit = &sev_segm_digit[0];
unsigned char *link_to_seconds = &seconds;
unsigned char *link_to_minuts = &minuts;
unsigned char *link_to_hours = &hours;
unsigned char *link_to_dot_digit = &dot_digit;

ISR(TIMER0_OVF_vect) {
	static int counter = 0;

	switch(counter) {
		case 0: {   
                    PORTD = 0b11111110;
                    DDRC = DDRC & 0b000000000;
                    DDRC = 0b00000000 | (0b00001000 >> 0);
                    PORTC = PORTC & 0b00110000;
                    PORTC = PORTC | (0b00001000 >> 0);
                    PORTD = sev_segm_digit[0];
                    counter = counter + 1; break;}
		case 1: {
                    PORTD = 0b11111110;
                    DDRC = DDRC & 0b000000000;
                    DDRC = 0b00000000 | (0b00001000 >> 1);
                    PORTC = PORTC & 0b00110000;
                    PORTC = PORTC | (0b00001000 >> 1);
                    PORTD = sev_segm_digit[1] & ~((seconds<<5) & 0b00100000);
                    counter = counter + 1; break;}
		case 2: {
                    PORTD = 0b11111110;
                    DDRC = DDRC & 0b000000000;
                    DDRC = 0b00000000 | (0b00001000 >> 2);
                    PORTC = PORTC & 0b00110000;
                    PORTC = PORTC | (0b00001000 >> 2);
                    PORTD = sev_segm_digit[2];
                    counter = counter + 1; break;}
		case 3: {
                    PORTD = 0b11111110;
                    DDRC = DDRC & 0b000000000;
                    DDRC = 0b00000000 | (0b00001000 >> 3);
                    PORTC = PORTC & 0b00110000;
                    PORTC = PORTC | (0b00001000 >> 3);
                    PORTD = sev_segm_digit[3];
                    counter = 0; break;}
}
}

ISR(TIMER2_OVF_vect) {

    inc_seconds(link_to_seconds);
    if (seconds == 0){
        inc_minuts(link_to_minuts);
        translate_minuts_to_segment(minuts, link_to_array_digit);
        if (minuts == 0) { 
            inc_hours(link_to_hours);
            translate_hours_to_segment(hours, link_to_array_digit);
        }
    }
	dot_digit = (~(seconds << 5)) | 0b11011111;

}

void main(void) {
	
	port_setup();
	counter_setup();
    translate_minuts_to_segment(minuts, link_to_array_digit);
    translate_hours_to_segment(hours, link_to_array_digit);
	sei();

	while (1) {
        if ((PINC & menu_button) == 0b00000000) {
            button_menu_handler(link_to_seconds, link_to_minuts,
                                link_to_hours, link_to_array_digit);
        }
	};
};
