#ifndef MOTORS_H
#define MOTORS_H


#define RIGHT_ARM   2
#define LEFT_ARM    3 // inverted
#define RIGHT_BASE  4
#define LEFT_BASE   5
#define BALL_INTAKE 7
#define SHOOTER2    8
#define GRIP        9

void lower_arm(int power);

void move_arm(int up, int down, int power);

void move_base(int left, int right);

void move_intake(int state);

void shoot();

#endif
