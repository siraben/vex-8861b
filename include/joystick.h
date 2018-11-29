#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

typedef struct joystick {
  // We're storing all the left and right button presses as a bitmap.
  uint8_t buttons; 

  struct left_analog {
      int8_t one;
      int8_t two;
      int8_t three;
      int8_t four;
  };
  struct right_analog {
      int8_t one;
      int8_t two;
      int8_t three;
      int8_t four;
  };
} joystick;

void update_joystick(joystick *joystick);

#endif
