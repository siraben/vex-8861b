#include "main.h"

controller_state rec[DATA_SIZE] = {0};
void collect_data(const char *filename,
                  controller_group *left_group,
                  controller_group *right_group,
                  controller_group *extra_right,
                  controller_group *extra_left,
                  controller_group *joysticks,
                  int overwrite) {
  PROS_FILE *file;

  file = fopen(filename, "r");
  
  if (!file && !overwrite) {
    printf("COLLECT_DATA: File already exists.\n");
    return;
  }
  file = fopen(filename, "w");
  for (int i = 0; i < DATA_SIZE; i++) {

    rec[i].extra_left = *extra_left;
    rec[i].extra_right = *extra_right;
    rec[i].left_group = *left_group;
    rec[i].right_group = *right_group;
    rec[i].joysticks = *joysticks;
    printf("%3d: %4d, %4d, %4d, %4d, %d%d%d%d %d%d %d%d %d%d%d%d\n",
           i,
           joysticks->one,
           joysticks->two,
           joysticks->three,
           joysticks->four,
           left_group->u,
           left_group->r,
           left_group->d,
           left_group->l,
           extra_right->u,
           extra_right->d,
           extra_left->u,
           extra_left->d,
           right_group->u,
           right_group->r,
           right_group->l,
           right_group->d);    

    move_bot(left_group,
             right_group,
             extra_right,
             extra_left,
             joysticks);
    update_group(left_group);
    update_group(right_group);
    update_group(extra_right);
    update_group(extra_left);
    update_group(joysticks);

    delay(SAMPLE_INTERVAL);
  }
  /* fwrite(rec, sizeof *rec, DATA_SIZE, file); */
  /* fclose(file); */
}

int load_file(const char *filename) {
  PROS_FILE *file = fopen(filename, "r");
  size_t ret_code = fread(rec, sizeof *rec, DATA_SIZE, file);
  printf("%u\n", ret_code);
  printf("%u\n", sizeof *rec);
  if(ret_code == DATA_SIZE) {
    printf("Array read successfully.\n");
    return 0;
  }
  if (feof(file)) {
    printf("Error reading %s: unexpected end of file\n", filename);
  }
  return 1;
}
