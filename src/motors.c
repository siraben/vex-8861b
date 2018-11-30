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
  motorSet(RIGHT_BASE, -right);
  motorSet(LEFT_BASE, -left);
}

void move_shooter(int forward, int reverse, int power) {
  if (forward) {
    motorSet(SHOOTER2, power);
  } else if (reverse) {
    motorSet(SHOOTER2, -power);
  } else {
    motorStop(SHOOTER2);
  }
  
}

void move_intake(int forward, int reverse, int power) {
  if (forward) {
    motorSet(BALL_INTAKE, power);
  } else if (reverse) {
    motorSet(BALL_INTAKE, -power);
  } else {
    motorStop(BALL_INTAKE);
  }
  
}


void move_bot(controller_group *left_group,
              controller_group *right_group,
              controller_group *extra_right,
              controller_group *extra_left,
              controller_group *joysticks) {
  move_arm(extra_right->u, extra_right->d, 127);
  move_base(-(joysticks->three), joysticks->two);
  move_shooter(left_group->u, left_group->d, 127);
  move_intake(left_group->l, left_group->r, 127);  
  // play_notes(left_group, right_group);
  
}
