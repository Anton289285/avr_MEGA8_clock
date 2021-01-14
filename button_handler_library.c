#include <avr/io.h>
#include <util/delay.h>
#include <button_handler.h>



void button_1_handler(unsigned char *link_to_some_seconds,  unsigned char *link_to_some_minuts, unsigned char *link_to_some_hours) {
//1
    TIMSK = TIMSK & 0b10111111;
    _delay_ms(bounce_delay);
//2
/*
    while ((PINC & menu_button) == 0b00000000) {
        
        }
    *link_to_some_minuts = 00;
    *link_to_some_hours = 11;
*/
