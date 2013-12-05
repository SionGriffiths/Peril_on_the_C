#include <stdio.h>
#include <stdlib.h>
#include "ships.h"
#include "navigation.h"
#include "mytime.h"
#include <time.h>


static time_ptr current_time = NULL;

time_ptr read_time(FILE * file_in) {

  int read_status;

  timestr* new_time;

  new_time = calloc(1, sizeof (timestr));

  //temp varibales here for conversion from file date format to date accepted by time.h
  int temp_month = 0;
  int temp_year = 0;

  read_status = fscanf(file_in, "%d %d %d %d %d %d",
          &new_time -> tm_mday,
          &temp_month,
          &temp_year,
          &new_time -> tm_hour,
          &new_time -> tm_min,
          &new_time -> tm_sec);

  new_time -> tm_year = (temp_year - 1900);
  new_time -> tm_mon = (temp_month - 1);

  if (read_status == EOF) {
    return NULL;
  } else {
    printf("Time read ok \n");
    return new_time;
  }


}

time_ptr get_current_time() {
  return current_time;
}

void set_current_time(time_ptr in_time) {
  current_time = in_time;
}

double time_diff(time_ptr old, time_ptr new) {
  time_t a = mktime(old);
  time_t b = mktime(new); 
  return (difftime(a, b))/60;
}

void show_time(time_ptr time_to_show) {
  printf("%d %d %d %d %d %d \n",
          time_to_show -> tm_year + 1900,
          time_to_show -> tm_mon,
          time_to_show -> tm_mday,
          time_to_show -> tm_hour,
          time_to_show -> tm_min,
          time_to_show -> tm_sec);
}


