// Copyright (c) 2021 Mike "KemoNine" Crosson
// SPDX-License-Identifier: Apache-2.0
#include QMK_KEYBOARD_H
/* // Language imports */
/* #include "keymap_german.h" */
#include "struckmb.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#   ifdef ARTSENIO_ENABLE
    [_ARTSENIO] = LAYOUT_wrapper( _AB1_4_, _AB2_4_),
    [_ARTS_NUM] = LAYOUT_wrapper( _AN1_4_, _AN2_4_),
    [_ARTS_SYM] = LAYOUT_wrapper( _AS1_4_, _AS2_4_),
    [_ARTS_PAR] = LAYOUT_wrapper( _AP1_4_, _AP2_4_),
    [_ARTS_NAV] = LAYOUT_wrapper( _AA1_4_, _AA2_4_),
    [_ARTS_MSE] = LAYOUT_wrapper( _AM1_4_, _AM2_4_),
#   endif // ARTSENIO_ENABLE
};

#ifdef OLED_ENABLE
bool boot_logo_cleared = false;
#ifdef ARDUX_BOOT_LOGO
uint32_t boot_logo_timer = 0;
static const char PROGMEM boot_logo[] = {
    /**/ 128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,255,255,  3,  3,115,115, 51, 19, 19,  3,  3,  3,  3,  3,  3,  3,  1,  1,  1,  0,  0,  0,  0,  0,  1,  1,  1, 19,  3,  3,127,255,
    /**/ 255,  0,  0,  0,  0,  0,224, 56, 12,  6,  6,140,152,240,  0,  0,  0, 48,120,200,134,  2,  0,128,192, 96,  0,  0,  0,  0,  0,  3,  1,  0,  0,  0,  0,  0,127, 14,  6,  3,  1,  1,  0, 63,  0,  0,  0,  0,  0,  0,  1,  3,  3,  7, 12, 24, 48, 24, 12,  6,  2,  0,
    /**/   0,  0,  0,  0,  0, 60,230,130,  2,  2,198, 60,  0,  0,  0,  0,  0,  0,  0,240, 32, 64,128,  0,  0,  0, 56,224,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1, 15, 57,  1,131,130,134,  4, 12,  8,  0,  0,  0,  0,  7, 24, 96,129,  2,  4,  8, 16, 35, 92,224,  0,
    /**/   0,  0,  0,  4,  2,  2,  3,  1, 31,241,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  2,  0,  0,  0,  0,  0,  0,  0,240,  0,  0,  0,128,  0,  0,  0,  0,  1,  7,192, 96, 48, 16, 16, 48, 96,192,  0,  0,  1,  1,227, 30,  2,  2,  2,  2,  0,  0,  0,
    /**/ 255,  0,  0,  0,255,127, 30,  0,128,  0,  0,  7, 12, 24,240,  0,  0,  2, 19, 16, 16, 16, 28, 23, 16, 16,  0,  0,  0,  0,  0,  0, 31,  0,  0,  0,  0,  0,  0,  0,  1,  3,  2,  2,  2,  3,  1,  0,  0,224, 48, 24, 12,  6,  2,  2,  6,  4,236, 56,  0,  0,  0,  0,
    /**/ 128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7, 12, 24, 16, 16, 24,  8, 12,  6,  3,  0,  0,  0,  0,  0,255,254,  0,  0,252,248,248,240,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,224,
    /**/ 255,255,  0,  0,227,227,227,227,227, 99, 34,128,192,224,224,224,224,224,224,112,112, 32,  2,130,  2, 34,227,227,  0,  0,255,255,255,255,  0,  0,255,255,255,255,255,254,248,225,131, 19,115,243,241,249,248,252,252,254,255,255,255,252,248,225,192,  0, 63, 55,
    /**/ 255,255,252,252,252,252,252,252,252,252,252,252,252,252,252,225,195,143, 31, 31, 63, 63, 63, 63, 63, 63,159,143,199,224,248,255,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,
};
static void render_logo(void) {
    oled_write_raw_P(boot_logo, sizeof(boot_logo));
}
#endif

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
#   ifdef ARDUX_BOOT_LOGO
    boot_logo_timer = timer_read32();
    render_logo();
#   endif // ARDUX_BOOT_LOGO
    return OLED_ROTATION_270;
}

#ifdef ARDUX_OLED_ICON
static const char PROGMEM icon_logo[] = {
    0,  0,128,240,248, 28, 12, 12, 28,252,252, 12, 12, 28,248,240, 56, 28, 12,252,252, 12,236,252, 28, 12, 12, 12, 28,120,112,  0,
    0,240,255, 63, 12, 12, 12, 12, 12,255,255,  6, 14, 31,123,241,192,  0,  0,255,255,  0,241,243,199,134,134,134,206,252,248,  0,
    0,241,249,156,140,140,140, 12,252,253,121,224,128,  0,240,249, 29, 12,252,253, 13, 12, 12,253,253, 29, 13, 13, 29,249,240,  0,
    0,127,127, 97, 97, 97, 97, 96,127,127,  0,  1,  7, 30,127,127, 96, 96,127,127, 96, 96,  0, 31, 63,112, 96, 96,112, 63, 31,  0,
};
static void render_icon(void) {
    oled_write_raw_P(icon_logo, sizeof(icon_logo));
}
#endif // ARDUX_OLED_ICON

static void render_status(void) {
#   ifdef ARDUX_OLED_ICON
    oled_set_cursor(0, 5);
#   else
    oled_set_cursor(0, 1);
    oled_write(" ARTS", false);
    oled_write(" ENIO\n\n", false);
#   endif // ARDUX_OLED_ICON
    switch (get_highest_layer(layer_state)) {
        case _ARTSENIO:
            for (int i=0; i<9; i++) oled_write("     ", false);
            break;
        case _ARTS_NUM:
            oled_write(" Num ", false);
            oled_write(" /Fn ", false);
            for (int i=0; i<2; i++) oled_write("     ", false);
            oled_write("8|421", false);
            oled_write("F | N", false);
            oled_write("421|8", false);
            for (int i=0; i<2; i++) oled_write("     ", false);
            break;
        case _ARTS_SYM:
            oled_write(" Sym ", false);
            oled_write(" bol ", false);
            oled_write("     ", false);
            oled_write("  ^  ", false);
            oled_write(" ` | ", false);
            oled_write("\\ # &", false);
            oled_write("+ - ?", false);
            oled_write(" = $ ", false);
            oled_write("  ~  ", false);
            break;
        case _ARTS_PAR:
            oled_write(" Par ", false);
            oled_write(" ens ", false);
            oled_write("     ", false);
            oled_write("     ", false);
            oled_write(" < > ", false);
            oled_write("{ ( )", false);
            oled_write("} [ ]", false);
            oled_write("     ", false);
            oled_write("     ", false);
            break;
        case _ARTS_NAV:
            oled_write(" Nav ", false);
            for (int i=0; i<3; i++) oled_write("     ", false);
            oled_write("^ <T>", false);
            oled_write("| H^E", false);
            oled_write("v <v>", false);
            for (int i=0; i<2; i++) oled_write("     ", false);
            break;
        case _ARTS_MSE:
            oled_write(" Mou ", false);
            oled_write("  se ", false);
            oled_write("     ", false);
            oled_write("   3 ", false);
            oled_write("^ 4 5", false);
            oled_write("| 2^1", false);
            oled_write("v <v>", false);
            for (int i=0; i<2; i++) oled_write("     ", false);
            break;
        /* case LAYER_ID_CUSTOM: */
        /*     oled_write(" Cus ", false); */
        /*     oled_write(" tom ", false); */
        /*     break; */
        default:
            oled_write(" ??? ", false);
            oled_write(" ??? ", false);
            for (int i=0; i<6; i++) oled_write("     ", false);
            break;
    }

    // Write the modifier state
    oled_write("-----", false);
    bool capsLock = host_keyboard_led_state().caps_lock || is_caps_word_on();
    if (capsLock) oled_write("CAPSL", true);
    else {
        uint8_t osms = get_oneshot_mods();
        uint8_t mods = get_mods() | osms;
        oled_write((mods & MOD_MASK_SHIFT  ) ? "S" : " ", (osms & MOD_MASK_SHIFT  ));
        oled_write((mods & MOD_MASK_CTRL   ) ? "C" : " ", (osms & MOD_MASK_CTRL   ));
        if (mods & MOD_BIT(KC_RALT)) oled_write("R", (osms & MOD_BIT(KC_RALT))); else
            oled_write((mods & MOD_MASK_ALT) ? "A" : " ", (osms & MOD_MASK_ALT    ));
        oled_write((mods & MOD_MASK_GUI    ) ? "M" : " ", (osms & MOD_MASK_GUI    ));
        oled_write(" ", false);
    }
}

bool oled_task_keymap(void) {
    // Don't do anything if the display is off
    if (!is_oled_on()) {
        return false;
    }

#   ifdef ARDUX_BOOT_LOGO
    if(!boot_logo_cleared) {
        if (timer_elapsed32(boot_logo_timer) < 2000) {
            render_logo();
            return false;
        }
        oled_clear();
        boot_logo_cleared = true;
    }
#   endif // ARDUX_BOOT_LOGO

#   ifdef ARDUX_OLED_ICON
    render_icon();
#   endif // ARDUX_OLED_ICON
    render_status();
    /* oled_render(); */

    return false;
}
#endif // OLED_ENABLE
