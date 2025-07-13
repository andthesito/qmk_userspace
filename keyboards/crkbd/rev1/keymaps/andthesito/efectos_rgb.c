#ifdef RGB_MATRIX_ENABLE
#include "colores_light.h"


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
	hsv_t hsv = {0, 0, 0};
	switch(get_highest_layer(layer_state|default_layer_state)) {
		case _NUMEROS:
			hsv = (hsv_t){HSV_GREEN_LIGHT};
			break;
		case _SIMBOLOS:
			hsv = (hsv_t){HSV_BLUE_LIGHT};
			break;
		case _FUNCT:
			hsv = (hsv_t){HSV_PURPLE_LIGHT};
			break;
		case _MEDIA:
			hsv = (hsv_t){HSV_TEAL_LIGHT};
			break;
		case _ADJUST:
			hsv = (hsv_t){HSV_RED_LIGHT};
			break;
		default:
			// Caps Lock indicator on alphanumeric flagged keys:
			if (host_keyboard_led_state().caps_lock) {
				hsv = (hsv_t){HSV_WHITE_LIGHT};
			}
			break;
	}

	rgb_t rgb = hsv_to_rgb(hsv);
	if(hsv.h != 0 || hsv.s != 0 || hsv.v != 0){
		rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
	}
	return false;
}
#endif
