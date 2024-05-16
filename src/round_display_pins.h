#if defined(ARDUINO_SEEED_XIAO_M0)

#define TFT_CS 1  // Chip select
#define TFT_DC 3  // Data/command
#define TFT_BL 6  // Backlight control

#elif defined(ARDUINO_XIAO_ESP32C3)

#define TFT_CS D1  // Chip select
#define TFT_DC D3  // Data/command
#define TFT_BL D6  // Backlight control

#elif defined(ARDUINO_XIAO_ESP32S3)

#define TFT_CS D1  // Chip select
#define TFT_DC D3  // Data/command
#define TFT_BL D6  // Backlight control

#else

#error "xiao board not selected"

#endif