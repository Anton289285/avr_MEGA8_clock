#include "library.h" 

void inc_seconds(unsigned char *some_seconds) {
	*some_seconds = *some_seconds + 1;
	if (*some_seconds >= 120) {
		*some_seconds = 0;
		};
}

void inc_minuts(unsigned char *some_minuts) {
	*some_minuts = *some_minuts + 1; 
	if ((*some_minuts) >= 60) {
		*some_minuts = 0;
	};
}

void inc_hours(unsigned char *some_hours) {
	*some_hours = *some_hours + 1;
	if (*some_hours >= 24) {
		*some_hours = 0;
	};
}

void translate_minuts_to_segment(unsigned char some_minuts,
            unsigned char *some_sev_segm_digit) {

	unsigned char minuts_low;
	unsigned char minuts_high;

    
	minuts_low = some_minuts % 10;
	minuts_high = some_minuts /10;

	switch(minuts_high) {
		case 0: some_sev_segm_digit[2] = char_zero; break;	
		case 1: some_sev_segm_digit[2] = char_one; break;	
		case 2: some_sev_segm_digit[2] = char_two; break;	
		case 3: some_sev_segm_digit[2] = char_three; break;	
		case 4: some_sev_segm_digit[2] = char_four; break;	
		case 5: some_sev_segm_digit[2] = char_five; break;	
		case 6: some_sev_segm_digit[2] = char_six; break;	
		case 7: some_sev_segm_digit[2] = char_seven; break;	
		case 8: some_sev_segm_digit[2] = char_eight; break;	
		case 9: some_sev_segm_digit[2] = char_nine; break;	
		}
	switch(minuts_low) {
		case 0: some_sev_segm_digit[3] = char_zero; break;	
		case 1: some_sev_segm_digit[3] = char_one; break;	
		case 2: some_sev_segm_digit[3] = char_two; break;	
		case 3: some_sev_segm_digit[3] = char_three; break;	
		case 4: some_sev_segm_digit[3] = char_four; break;	
		case 5: some_sev_segm_digit[3] = char_five; break;	
		case 6: some_sev_segm_digit[3] = char_six; break;	
		case 7: some_sev_segm_digit[3] = char_seven; break;	
		case 8: some_sev_segm_digit[3] = char_eight; break;	
		case 9: some_sev_segm_digit[3] = char_nine; break;	
		}
};

void translate_hours_to_segment(unsigned char some_hours,
            unsigned char *some_sev_segm_digit) {

            
	unsigned char hours_low;
	unsigned char hours_high;
    
	hours_low = some_hours % 10;
	hours_high = some_hours / 10;
    
	switch(hours_high) {
		case 0: some_sev_segm_digit[0] = char_zero; break;	
		case 1: some_sev_segm_digit[0] = char_one; break;	
		case 2: some_sev_segm_digit[0] = char_two; break;	
		case 3: some_sev_segm_digit[0] = char_three; break;	
		case 4: some_sev_segm_digit[0] = char_four; break;	
		case 5: some_sev_segm_digit[0] = char_five; break;	
		case 6: some_sev_segm_digit[0] = char_six; break;	
		case 7: some_sev_segm_digit[0] = char_seven; break;	
		case 8: some_sev_segm_digit[0] = char_eight; break;	
		case 9: some_sev_segm_digit[0] = char_nine; break;	
		}
	switch(hours_low) {
		case 0: some_sev_segm_digit[1] = char_zero; break;	
		case 1: some_sev_segm_digit[1] = char_one; break;	
		case 2: some_sev_segm_digit[1] = char_two; break;	
		case 3: some_sev_segm_digit[1] = char_three; break;	
		case 4: some_sev_segm_digit[1] = char_four; break;	
		case 5: some_sev_segm_digit[1] = char_five; break;	
		case 6: some_sev_segm_digit[1] = char_six; break;	
		case 7: some_sev_segm_digit[1] = char_seven; break;	
		case 8: some_sev_segm_digit[1] = char_eight; break;	
		case 9: some_sev_segm_digit[1] = char_nine; break;	
		}
};


void button_1_handler(unsigned char *link_to_some_seconds,
                        unsigned char *link_to_some_minuts,
                        unsigned char *link_to_some_hours,
                        unsigned char *link_to_some_array) {
//1
    _delay_ms(debounce_delay);
    while ((PINC & menu_button) == 0) {

    };
    _delay_ms(debounce_delay);
    unsigned char counter = 0;
    *link_to_some_seconds = 0;
    link_to_some_array[2] = char_void;
    link_to_some_array[3] = char_void;
    TIMSK = TIMSK & 0b10111111;
//2

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

