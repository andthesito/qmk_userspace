/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
//Split keyboard 
#define EE_HANDS
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE

//Tapping
#define ONESHOT_TAP_TOGGLE 2
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 120
//#define TAPPING_TERM 175
#undef HOLD_ON_OTHER_KEY_PRESS

// OLED Display
#define OLED_FONT_H "neuromancer.c"

// LEDS
#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_TYPING_HEATMAP // Sets the default mode, if none has been set
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
								 // #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
#   define RGB_MATRIX_SLEEP // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#   define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#	undef RGB_MATRIX_MAXIMUM_BRIGHTNESS 
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 50 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash. 
#   define RGB_MATRIX_HUE_STEP 8
#   define RGB_MATRIX_SAT_STEP 8
#   define RGB_MATRIX_VAL_STEP 8
#   define RGB_MATRIX_SPD_STEP 10

/* Enable the animations you want/need.  You may need to enable only a small number of these because       *
 * they take up a lot of space.  Enable and confirm that you can still successfully compile your firmware. */
// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
//#    define ENABLE_RGB_MATRIX_ALPHAS_MODS
//#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
//#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
//#    define ENABLE_RGB_MATRIX_BREATHING
//#    define ENABLE_RGB_MATRIX_BAND_SAT
//#    define ENABLE_RGB_MATRIX_BAND_VAL
//#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
//#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
//#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
//#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
//#    define ENABLE_RGB_MATRIX_CYCLE_ALL
//#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
//#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
//#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
//#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
//#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
//#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
//#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
//#    define ENABLE_RGB_MATRIX_DUAL_BEACON
//#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
//#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
//#    define ENABLE_RGB_MATRIX_RAINDROPS
//#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
//#    define ENABLE_RGB_MATRIX_HUE_BREATHING
//#    define ENABLE_RGB_MATRIX_HUE_PENDULUM
//#    define ENABLE_RGB_MATRIX_HUE_WAVE
//#    define ENABLE_RGB_MATRIX_PIXEL_RAIN
//#    define ENABLE_RGB_MATRIX_PIXEL_FLOW
//#    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
//// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
//#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
//// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
//#    define ENABLE_RGB_MATRIX_SPLASH
//#    define ENABLE_RGB_MATRIX_MULTISPLASH
//#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
//#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

#ifdef MOUSEKEY_ENABLE
// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64
#endif

#define NO_MUSIC_MODE
