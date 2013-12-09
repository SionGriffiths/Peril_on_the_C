/* 
 * File:   mayday.c
 * Author: sig2
 *
 * Created on 04 December 2013, 20:56
 */

#include <stdio.h>
#include <stdlib.h>
#include "mayday.h"
#include "mytime.h"
#include <time.h>

mayday_ptr read_mayday(char * mayday_file_name) {

  FILE * mayday_file;
  int read_status;
  mayday * mayday_in;
  struct tm temp_time;

  mayday_file = fopen(mayday_file_name, "r");

  if (mayday_file != NULL) {

    mayday_in = calloc(1, sizeof (mayday));


    int temp_month = 0;
    int temp_year = 0;
    read_status = fscanf(mayday_file, "%d%d%d%d%d%d%s%d%d",
            &temp_time.tm_mday,
            &temp_month,
            &temp_year,
            &temp_time.tm_hour,
            &temp_time.tm_min,
            &temp_time.tm_sec,
            mayday_in->ais_id,
            &mayday_in->boat_minutes,
            &mayday_in->heli_minutes);

    temp_time.tm_mon = temp_month - 1;
    temp_time.tm_year = temp_year - 1900;
    temp_time.tm_isdst = 0;
    mayday_in->m_time = mktime(&temp_time);

    if (read_status == EOF) {
      fclose(mayday_file);
      return NULL;
    } else if (read_status != 9) {
      printf("Mayday file looks incorrect or corrupt \n");
    } else {
      printf("Mayday read OK \n");
      return mayday_in;
    }

  }
  fclose(mayday_file);
  return NULL;
}

time_t get_mayday_time(mayday_ptr mayday_in) {

  time_t mayday_time = mayday_in->m_time;
  
  return mayday_time;
}



