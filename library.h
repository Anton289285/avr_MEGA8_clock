#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#define menu_button 0b00010000
#define select_button 0b00100000
#define debounce_delay 30




// Переопределение цифр:

#define char_void 0b11111111
#define char_one 0b01111011
#define char_two 0b10101000
#define char_three 0b01101000
#define char_four 0b01110010
#define char_five 0b01100100
#define char_six 0b00100100
#define char_seven 0b01111001
#define char_eight 0b00100000
#define char_nine 0b01100000
#define char_zero 0b00100001
/*
0 - dot
1 - G
2 - F
3 - E
4 - D
5 - C
6 - B
7 - A
*/



void inc_seconds(unsigned char *some_seconds); 
void inc_minuts(unsigned char *some_minuts); 
void inc_hours(unsigned char *some_hours); 
void translate_hours_to_segment(unsigned char some_hours,
            unsigned char *some_sev_segm_digit);
void translate_minuts_to_segment(unsigned char some_minuts,
            unsigned char *some_sev_segm_digit);
void button_1_handler(unsigned char *link_to_some_seconds,
                        unsigned char *link_to_some_minuts,
                        unsigned char *link_to_some_hours,
                        unsigned char *link_to_some_array); 
