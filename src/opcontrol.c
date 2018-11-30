#include "main.h"


void operatorControl() {
  printf("--------- BOOT SUCCESS ---------\n");
  // int data_test = 1;  
  /* printf("--- STARTING DATA COLLECTION ---\n");   */

  /* if (data_test) { */
  /*   collect_data("data.bin", */
  /*                left_group, */
  /*                right_group, */
  /*                extra_right, */
  /*                extra_left, */
  /*                joysticks, */
  /*                1); */
  /*   printf("------- PLAYING BACK DATA ------\n"); */
  /*   printf("--------- IN 3 SECONDS ---------\n"); */
  /*   /\* load_file("data.bin"); *\/ */
  /*   /\* for(int x = 0; x < 300*140; x++) { *\/ */
  /*   /\*   putchar(message[x]); *\/ */
  /*   /\* } *\/ */
  /*   delay(3000); */
  /*   for (int i = 0; i < DATA_SIZE; i++) { */
  /*     printf("%3d: %4d, %4d, %4d, %4d, %d%d%d%d %d%d %d%d %d%d%d%d\n", */
  /*            i, */
  /*            joysticks->one, */
  /*            joysticks->two, */
  /*            joysticks->three, */
  /*            joysticks->four, */
  /*            left_group->u, */
  /*            left_group->r, */
  /*            left_group->d, */
  /*            left_group->l, */
  /*            extra_right->u, */
  /*            extra_right->d, */
  /*            extra_left->u, */
  /*            extra_left->d, */
  /*            right_group->u, */
  /*            right_group->r, */
  /*            right_group->l, */
  /*            right_group->d); */
  /*     left_group = &rec[i].left_group; */
  /*     right_group = &rec[i].right_group; */
  /*     extra_right = &rec[i].extra_right; */
  /*     extra_left = &rec[i].extra_left; */
  /*     joysticks = &rec[i].joysticks; */

  /*     move_bot(left_group, */
  /*              right_group, */
  /*              extra_right, */
  /*              extra_left, */
  /*              joysticks); */
  /*     delay(SAMPLE_INTERVAL); */
  /*   } */
  /* } */

  printf("------- PLAYBACK FINISHED ------\n");
  printf("------- SWTCHING TO MANUAL -----\n");
  for (;;) {
    move_bot(left_group,
             right_group,
             extra_right,
             extra_left,
             joysticks);    
    /* printf("\r%4d, %4d, %4d, %4d, %d%d%d%d %d%d %d%d %d%d%d%d", */
    /*          joysticks->one, */
    /*          joysticks->two, */
    /*          joysticks->three, */
    /*          joysticks->four, */
    /*          left_group->u, */
    /*          left_group->r, */
    /*          left_group->d, */
    /*          left_group->l, */
    /*          extra_right->u, */
    /*          extra_right->d, */
    /*          extra_left->u, */
    /*          extra_left->d, */
    /*          right_group->u, */
    /*          right_group->r, */
    /*          right_group->l, */
    /*          right_group->d); */
    /* fflush(stdout); */
    update_group(left_group);
    update_group(right_group);
    update_group(extra_right);
    update_group(extra_left);
    update_group(joysticks);
    delay(20);
  }

}
