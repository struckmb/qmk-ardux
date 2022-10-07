BOOTLOADER = caterina

PINS_HAND_LEFT = -DDIRECT_PINS="{ { F7, F6, F5, F4 }, { B6, B2, B3, B1 } }"
OPT_DEFS += $(PINS_HAND_LEFT)

# Paintbrush hardware
ifneq (,$(findstring ardux/thepaintbrush,$(KEYBOARD)))
    # Elective features
    COMBO_ENABLE = yes
    ENCODER_ENABLE = no
    OLED_ENABLE = yes
    # Nonexistent features
    AUDIO_ENABLE = no
    BACKLIGHT_ENABLE = no
    RGB_MATRIX_ENABLE = no
    # Space savers
    NKRO_ENABLE = no
    VELOCIKEY_ENABLE = no
    WPM_ENABLE = no
endif
