#ifndef STRUCTS_H
#define STRUCTS_H

typedef enum controller_group_type
{
  joystick,
  button
} controller_group_type;

typedef struct controller_group {
  controller_group_type type;
  union {
    // Button
    struct {
      int id, u, l, r, d;
    };
    // Joystick
    struct {
      int one, two, three, four, accel_x, accel_y;
    };
  };
} controller_group;

typedef struct controller_state {
  controller_group left_group, right_group, extra_right, extra_left, joysticks;
} controller_state;

void update_group(controller_group *group);

controller_group *new_controller_group(int id, controller_group_type type);

controller_group *left_group, *right_group, *extra_right, *extra_left, *joysticks;

#endif
