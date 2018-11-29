#include "main.h"

void update_group(controller_group *group) {

  if (group->type == button) {
    int id = group->id;
    group->u= joystickGetDigital(1, id, JOY_UP);
    group->d = joystickGetDigital(1, id, JOY_DOWN);

    // These are the special button groups on the top of the controller that
    // can't have right and left buttons.
    if (id == 5 || id == 6) {
      group->r = 0;
      group->l = 0;
    } else {
      group->r = joystickGetDigital(1, id, JOY_RIGHT);
      group->l = joystickGetDigital(1, id, JOY_LEFT);
    }
  } else if (group->type == joystick) {
    group->one = joystickGetAnalog (1, 1);
    group->two = joystickGetAnalog (1, 2);
    group->three = joystickGetAnalog (1, 3);
    group->four = joystickGetAnalog (1, 4);
    group->accel_x = joystickGetAnalog (1, ACCEL_X);
    group->accel_y = joystickGetAnalog (1, ACCEL_Y);
  } else {
    print("update_group failed: Unknown group type!\n");
  }
}


controller_group *new_controller_group(int id, controller_group_type type) {
  controller_group *res = 0;
  res = (controller_group*) calloc (1, sizeof(controller_group));

  res->type = type;
  if (type == 1) {
    res->id = id;
  }
  return ((id < 5) || (id > 8)) && (res->type == button) ? 0 : res;
}
