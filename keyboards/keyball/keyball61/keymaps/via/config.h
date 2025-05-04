/*
This is the c configuration file for the keymap

Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#endif

#define TAP_CODE_DELAY 5

// #define POINTING_DEVICE_AUTO_MOUSE_ENABLE

// It should be lower than the navigation layer to avoid taking precedence.
// #define AUTO_MOUSE_DEFAULT_LAYER 1

// Default value.
#define TAPPING_TERM 200

// Why not.
#define HOLD_ON_OTHER_KEY_PRESS

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// Example: Quick Shift hold after Space tap. 
#define QUICK_TAP_TERM 0

// Leave a quick tap for `TT`s keys.
#define QUICK_TAP_TERM_PER_KEY

// For `TT`s keys.
#define TAPPING_TOGGLE 2
