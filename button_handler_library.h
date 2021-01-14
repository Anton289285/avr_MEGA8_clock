#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>


#define menu_button 0b00010000
#define select_button 0b00100000
#define bounce_delay 20


void button_1_handler(unsigned char *link_to_some_seconds,  unsigned char *link_to_some_minuts, unsigned char *link_to_some_hours); 

