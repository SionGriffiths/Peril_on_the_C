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

  mayday_file = fopen(mayday_file_name, "r");

  if (mayday_file != NULL) {

    mayday_in = calloc(1, sizeof (mayday));
    
    read_status = fscanf(mayday_file, "%d%d%d%d%d%d%s%d%d", 
            &mayday_in->day,
            &mayday_in->month,
            &mayday_in->year,
            &mayday_in->hours,
            &mayday_in->minutes,
            &mayday_in->seconds,
            mayday_in->ais_id,
            &mayday_in->boat_minutes,
            &mayday_in->heli_minutes);
    
    if(read_status == EOF){
      fclose(mayday_file);
      return NULL;
    }
    else if(read_status != 9){
      printf("Mayday file looks incorrect or corrupt \n");
    }
    else{
      printf("Mayday read OK \n");
      return mayday_in;
    }

  }
  fclose(mayday_file);
  return NULL;
}

time_ptr get_mayday_time(mayday_ptr mayday_in){
  
  time_ptr mayday_time = NULL;
  mayday_time = calloc(1, sizeof(timestr));
  
  mayday_time->tm_mday = mayday_in->day;
  mayday_time->tm_mon = (mayday_in->month)-1;
  mayday_time->tm_year = (mayday_in->year)-1900;
  //hour
  mayday_time->tm_hour = mayday_in->hours;
  //min
  mayday_time->tm_min = mayday_in->minutes;
  //sec
  mayday_time->tm_sec = mayday_in->seconds;
  
  return mayday_time;
}



