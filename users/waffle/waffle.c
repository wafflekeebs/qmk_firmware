/* Copyright 2021 @waffle#0007
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "waffle.h"
#include "quantum.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LWRSPC:
            return TAPPING_TERM - 30;
        case RSEBSP:
            return TAPPING_TERM - 30;
        default:
            return TAPPING_TERM;
    }
}

#ifdef UNICODEMAP_ENABLE
const uint32_t PROGMEM unicode_map[] = {
    [SIDE] = 0x30C4,
    [UPAR] = 0x16CF,
    [HAS] = 0x262D,
    [STAR] = 0x2605,
    [VIB] = 0x0950,
};
#endif

#ifdef ENCODER_ENABLE
/*__attribute__ ((weak)) bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (IS_LAYER_ON(_ADJUST)) { ((clockwise == true) ? rgblight_increase_sat() : rgblight_decrease_sat());
        } else if (IS_LAYER_ON(_RAISE)) { tap_code((clockwise == true) ? KC_MNXT : KC_MPRV);
        } else if (IS_LAYER_ON(_LOWER)) { tap_code((clockwise == true) ? KC_WWW_FORWARD : KC_WWW_BACK);
        } else { tap_code((clockwise == true) ? KC_VOLU : KC_VOLD); }
    } else if (index == 1) {
        if (IS_LAYER_ON(_ADJUST)) { ((clockwise == true) ? rgblight_increase_hue() : rgblight_decrease_hue());
        } else if (IS_LAYER_ON(_RAISE)) { tap_code16((clockwise == true) ? C(KC_TAB) : S(C(KC_TAB)));
        } else if (IS_LAYER_ON(_LOWER)) { tap_code16((clockwise == true) ? C(KC_RGHT) : C(KC_LEFT));
        } else { tap_code16((clockwise == true) ? C(KC_Y) : C(KC_Z)); }
    }
    return true;
}*/
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) { tap_code_delay(KC_VOLU, 20); }
        else { tap_code_delay(KC_VOLD, 20); }
    } else if (index == 1) {
        if (clockwise) { tap_code_delay(KC_VOLU, 20); }
        else { tap_code_delay(KC_VOLD, 20); }
    }
    return true;
}
#endif

#ifdef PIMORONI_TRACKBALL
uint8_t white = 0;
uint8_t red = 255;
uint8_t green = 0;
uint8_t blue = 0;

void ball_increase_hue(void){
    if (red != 255 && green != 255 && blue != 255) { red = 255; }
    if (red == 255 && green < 255 && blue == 0) { green += 15; }
    else if (green == 255 && blue == 0 && red > 0) { red -= 15; }
    else if (red == 0 && blue < 255 && green == 255 ) { blue += 15; }
    else if (blue == 255 && green > 0 && red == 0) { green -= 15; }
    else if (green == 0 && blue == 255 && red < 255) { red += 15; }
    else if (green == 0 && blue > 0 && red == 255) { blue -= 15; }
    trackball_set_rgbw (red,green,blue,white);
}

void decrease_color(void){
    if (green > 0) { green -= 15; }
    if (red > 0) { red -= 15; }
    if (blue > 0) { blue -= 15; }
    trackball_set_rgbw (red,green,blue,white);
}

void cycle_white(void){
    if (white < 255) { white += 15;}
    else { white = 0; }
    trackball_set_rgbw (red,green,blue,white);
}
#endif

#ifdef OLED_DRIVER_ENABLE
__attribute__ ((weak)) void suspend_power_down_user(void) { oled_off(); }
#endif

#ifdef BOOTLOADER_nanoboot
void bootloader_jump(void) {
    /*nanoBoot sets up 2 registers (r2,r3), copies then clears the MCUSR register,
    disables the watchdog timer and then checks the EXTRF. It'll only continue in the
    bootloader if the flag is set, otherwise it'll boot the application (jmp 0) when
    using the reset vector (0x7E00). This code jumps past the reset vector straight into
    the bootloader skipping the EXTRF check, so prior setup is required.
    This code is mostly from  from tmk_core/common/avr/bootloader.c*/
    cli();
    UDCON  = 1;
    USBCON = (1 << FRZCLK);
    UCSR1B = 0;
    _delay_ms(5);
    EIMSK  = 0;
    PCICR  = 0;
    SPCR   = 0;
    ACSR   = 0;
    EECR   = 0;
    ADCSRA = 0;
    TIMSK0 = 0;
    TIMSK1 = 0;
    TIMSK3 = 0;
    TIMSK4 = 0;
    UCSR1B = 0;
    TWCR   = 0;
    DDRB   = 0;
    DDRC   = 0;
    DDRD   = 0;
    DDRE   = 0;
    DDRF   = 0;
    TWCR   = 0;
    PORTB  = 0;
    PORTC  = 0;
    PORTD  = 0;
    PORTE  = 0;
    PORTF  = 0;
    asm volatile("clr r2");      // clear register (rZERO in bootloader)
    asm volatile("clr r3");      // clear register (rONE in bootloader)
    asm volatile("inc r3");      // increment register
    asm volatile("jmp 0x7e6a");  // jump to bootloader skipping some setup and extrf check.
}
#endif
