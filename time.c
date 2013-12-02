#include <stdio.h>
#include <stdlib.h>
#include "ships.h"
#include "navigation.h"
#include "time.h"


time_ptr current_time = NULL;

time_ptr read_time(FILE * file_in) {
  
  int read_status;

  time* new_time;

  new_time = calloc(1, sizeof (time));

  read_status = fscanf(file_in, "%d%d%d%d%d%d",
          &new_time -> day,
          &new_time -> month,
          &new_time -> year,
          &new_time -> hours,
          &new_time -> minutes,
          &new_time -> seconds);

  if (read_status == EOF) {
    return NULL;
  } else {
    return new_time;
  }


}

time_ptr get_current_time() {
  return current_time;
}

void set_current_time(time_ptr in_time) {
  current_time = in_time;
}
