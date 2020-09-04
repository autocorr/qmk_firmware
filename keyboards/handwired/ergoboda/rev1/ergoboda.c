#include "ergoboda.h"

#define _RLED F5
#define _GLED F6
#define _BLED B5

void matrix_init_kb(void) {
	setPinOutput(_RLED);
	setPinOutput(_GLED);
	setPinOutput(_BLED);
	matrix_init_user();
};

void led_set_kb(uint8_t usb_led) {
    led_set_user(usb_led);
}
