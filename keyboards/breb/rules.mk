MCU = STM32F103
BOOTLOADER = stm32duino
BOOTMAGIC_ENABLE = lite
EXTRAKEY_ENABLE = yes
RGBLIGHT_ENABLE = yes
OLED_DRIVER_ENABLE = yes
ENCODER_ENABLE = yes
WPM_ENABLE = yes
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
