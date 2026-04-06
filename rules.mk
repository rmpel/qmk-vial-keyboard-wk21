# Build Options
#   change yes to no to disable
#
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow (use RGB_MATRIX instead)
AUDIO_ENABLE = no           # Audio output

# Include keyboard.c for LED configuration
SRC += keyboard.c

# Vial support will be enabled in keymap-specific rules.mk
