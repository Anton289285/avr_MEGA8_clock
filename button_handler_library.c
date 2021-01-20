#include "button_handler_library.h"


void button_menu_handler(unsigned char *link_to_some_seconds,
                        unsigned char *link_to_some_minuts,
                        unsigned char *link_to_some_hours,
                        unsigned char *link_to_some_array) {
    _delay_ms(debounce_delay);
    while ((PINC & menu_button) == 0) {

    };
    _delay_ms(debounce_delay);
    unsigned char counter = 0;
    *link_to_some_seconds = 0;
    link_to_some_array[2] = char_void;
    link_to_some_array[3] = char_void;
    TIMSK = TIMSK & 0b10111111;

    while ((PINC & menu_button) == menu_button) {
        if ((PINC & select_button) == select_button) continue;
        if ((PINC & select_button) == 0) {
            counter = 0;
            while (1) {
                _delay_ms(debounce_delay);
                if ((PINC & select_button) == select_button) {
                    inc_hours(link_to_some_hours);
                    translate_hours_to_segment(*link_to_some_hours,
                    link_to_some_array);
                    break;
                }
                else {
                    counter = counter + 1;
                    if (counter > 10) {
                        inc_hours(link_to_some_hours);
                        translate_hours_to_segment(*link_to_some_hours,
                        link_to_some_array);
                        _delay_ms(90);
                        continue;
                    }
            }

        };
    };
    };
    
//  Выход из часов в минуты    

    _delay_ms(debounce_delay);
    while ((PINC & menu_button) == 0) {

    };
    _delay_ms(debounce_delay);
    translate_minuts_to_segment(*link_to_some_minuts,
                                link_to_some_array);
    link_to_some_array[0] = char_void;
    link_to_some_array[1] = char_void;

    while ((PINC & menu_button) == menu_button) {
        if ((PINC & select_button) == select_button) continue;
        if ((PINC & select_button) == 0) {
            counter = 0;
            while (1) {
                _delay_ms(debounce_delay);
                if ((PINC & select_button) == select_button) {
                    inc_minuts(link_to_some_minuts);
                    translate_minuts_to_segment(*link_to_some_minuts,
                                                link_to_some_array);
                    break;
                }
                else {
                    counter = counter + 1;
                    if (counter > 10) {
                        inc_minuts(link_to_some_minuts);
                        translate_minuts_to_segment(*link_to_some_minuts,
                                                    link_to_some_array);
                        _delay_ms(90);
                        continue;
                    }
            }

        };
    };
    };
    _delay_ms(debounce_delay);
    while ((PINC & menu_button) == 0) {

    };
    _delay_ms(debounce_delay);
    TIMSK = TIMSK | 0b01000000;
    translate_hours_to_segment(*link_to_some_hours,
                                link_to_some_array);
}
