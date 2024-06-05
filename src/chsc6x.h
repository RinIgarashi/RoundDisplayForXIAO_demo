#include <Wire.h>

#define CHSC6X_I2C_ID 0x2e
#define CHSC6X_MAX_POINTS_NUM 1
#define CHSC6X_READ_POINT_LEN 5

void touch_begin(void) {
  Wire.begin();
  pinMode (TOUCH_INT, INPUT_PULLUP); 
}

bool chsc6x_is_pressed(void) {
  if (digitalRead(TOUCH_INT) != LOW) {
    delay(1);
    if (digitalRead(TOUCH_INT) != LOW) {
      return false;
    }
  }
  return true;
}

void chsc6x_get_xy(uint8_t *x, uint8_t *y) {
  uint8_t temp[CHSC6X_READ_POINT_LEN] = {0};
  uint8_t read_len = Wire.requestFrom(CHSC6X_I2C_ID, CHSC6X_READ_POINT_LEN);
  if (read_len == CHSC6X_READ_POINT_LEN) {
    Wire.readBytes(temp, read_len);
    if (temp[0] == 0x01) {
      *x = temp[2];
      *y = temp[4];
    }
  }
}