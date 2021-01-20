#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>


#ifndef COMMON_LIBRARY
	#define COMMON_LIBRARY
	#include "common_library.h"
#endif


#define menu_button 0b00010000
#define select_button 0b00100000
#define bounce_delay 30


void button_menu_handler(unsigned char *link_to_some_seconds,
                        unsigned char *link_to_some_minuts,
                        unsigned char *link_to_some_hours,
                        unsigned char *link_to_some_array); 
