#include <stdio.h>
#include <stdlib.h>
#include "ships.h"
#include "navigation.h"
#include "mytime.h"
#include <time.h>
#include "log_file_handler.h"


static time_t current_time;

time_t read_time(FILE * file_in) {

  int read_status;
  char msg_buffer[1024];
  struct tm new_time;

  
  //temp varibales here for conversion from file date format to date accepted by time.h
  int temp_month = 0;
  int temp_year = 0;

  read_status = fscanf(file_in, "%d %d %d %d %d %d",
          &new_time.tm_mday,
          &temp_month,
          &temp_year,
          &new_time.tm_hour,
          &new_time.tm_min,
          &new_time.tm_sec);

  new_time.tm_year = (temp_year - 1900);
  new_time.tm_mon = (temp_month - 1);
  new_time.tm_isdst = 0;
  time_t ret_value;
  if (read_status == EOF) {
    return ret_value;
  } else {
    printf("Time read ok \n");
    ret_value = mktime(&new_time);
    
    sprintf(msg_buffer, "Time is %s \n", ctime(&ret_value));
    output_event(msg_buffer);
    return ret_value;
  }


}

time_t get_current_time() {
  return current_time;
}

void set_current_time(time_t in_time) {
  current_time = in_time;
}

double time_diff(time_t past, time_t now) {
  
  return (difftime(past, now)) / 60;
}




