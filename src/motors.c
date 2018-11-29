#include "main.h"

// Fixed power.
void lower_arm(int power) {
  motorSet(LEFT_ARM, power);
  motorSet(RIGHT_ARM, -power);
}

// Fixed power.
void move_arm(int up, int down, int power) {
  if (up) {
    motorSet(LEFT_ARM, -power);
    motorSet(RIGHT_ARM, power);
  } else if (down) {
    motorSet(LEFT_ARM, power);
    motorSet(RIGHT_ARM, -power);
  } else {
    motorStop(LEFT_ARM);
    motorStop(RIGHT_ARM);
  }
}

void move_base(int left, int right) {
  motorSet(RIGHT_BASE, right);
  motorSet(LEFT_BASE, left);
}


void move_intake(int state) {
  motorSet(BALL_INTAKE, state ? 127 : 0);
}

void shoot(int state) {
  motorSet(SHOOTER2, state ? 127 : 0)
}
