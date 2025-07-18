#ifdef OLED_ENABLE

static void render_status(void) {
	// Host Keyboard Layer Status
	switch (get_highest_layer(layer_state)) {
		case _QWERTY:
			oled_write_ln_P(PSTR("QWERT"), false);
			break;
		case _NUMEROS:
			oled_write_ln_P(PSTR("NUMER"), false);
			break;
		case _SIMBOLOS:
			oled_write_ln_P(PSTR("SIMBS"), false);
			break;
        case _MOVIMIENTO:
			oled_write_ln_P(PSTR("MOVIM"), false);
			break;
        case _RATON:
			oled_write_ln_P(PSTR("RATON"), false);
			break;
		case _MEDIA:
			oled_write_ln_P(PSTR("MEDIA"), false);
			break;
		case _FUNCT:
			oled_write_ln_P(PSTR("FUNCT"), false);
			break;
		case _ADJUST:
			oled_write_ln_P(PSTR("AJUST"), false);
			break;
		default:
			oled_write_ln_P(PSTR("-----"), false);
			break;
	}
	// Mod status
	uint8_t mod = get_mods() | get_oneshot_mods();
	oled_write_ln_P(mod & MOD_MASK_CTRL ? PSTR("CTRL ") : PSTR("-----"), false);
	oled_write_ln_P(mod & MOD_MASK_ALT ? PSTR("ALT  ") : PSTR("-----"), false);
	oled_write_ln_P(mod & MOD_MASK_GUI ? PSTR("OS   ") : PSTR("-----"), false);
	oled_write_ln_P(mod & MOD_MASK_SHIFT ? PSTR("MAYS ") : PSTR("-----"), false);

	// host keyboard led status
	led_t led_state = host_keyboard_led_state();
	oled_write_ln_P(led_state.num_lock ? PSTR("NUMLK") : PSTR("-----"), false);
	oled_write_ln_P(led_state.caps_lock ? PSTR("CAPSL") : PSTR("-----"), false);
	oled_write_ln_P(led_state.scroll_lock ? PSTR("SCRLL") : PSTR("-----"), false);
}

static void render_logo(void) {
	static const char PROGMEM qmk_logo[] = {
		0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
		0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
		0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
	};

	oled_write_ln_P(qmk_logo, false);
}


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	if (is_keyboard_left()) {
		return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
	}
	return OLED_ROTATION_270;
}

bool oled_task_user(void) {
	if (!is_keyboard_left()) {
		render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
	} else {
		render_logo();  // Renders a static logo
		//oled_scroll_left();  // Turns on scrolling
	}
	return false;
}
#endif
