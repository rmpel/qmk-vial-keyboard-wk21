# Build Options
#   change yes to no to disable
#
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow (use RGB_MATRIX instead)
AUDIO_ENABLE = no           # Audio output

# Custom matrix implementation
CUSTOM_MATRIX = lite        # Use lite custom matrix (we provide matrix_scan_custom)

# Source files
SRC += shift_register.c     # 74HC595 shift register driver
SRC += matrix.c             # Custom matrix scanning with shift register
SRC += keyboard.c           # RGB matrix LED configuration

# Vial support will be enabled in keymap-specific rules.mk
