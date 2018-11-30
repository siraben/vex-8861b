#ifndef RECORD_H
#define RECORD_H
// 0.04 seconds/sample
#define DATA_SIZE          300
#define SAMPLE_INTERVAL    15000/DATA_SIZE

#include "structs.h"

controller_state rec[DATA_SIZE];


void collect_data(const char *filename,
                  controller_group *left_group,
                  controller_group *right_group,
                  controller_group *extra_right,
                  controller_group *extra_left,
                  controller_group *joysticks,
                  int overwrite);
int load_file(const char *filename);

#endif
