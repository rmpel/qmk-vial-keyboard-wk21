# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow (use RGB_MATRIX instead)
AUDIO_ENABLE = no           # Audio output

# RGB Matrix configuration
RGB_MATRIX_ENABLE = yes     # Enable RGB matrix support
RGB_MATRIX_DRIVER = ws2812  # Use WS2812 driver for addressable LEDs

# Custom matrix implementation
CUSTOM_MATRIX = lite        # Use lite custom matrix (we provide matrix_scan_custom)

# Source files
SRC += shift_register.c     # 74HC595 shift register driver
SRC += matrix.c             # Custom matrix scanning with shift register
SRC += keyboard.c           # RGB matrix LED configuration

# Vial support will be enabled in keymap-specific rules.mk
