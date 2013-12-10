/* 
 * File:   mayday.c
 * Author: sig2
 * 
 * Description: Specifies functions to create and populate a mayday structure from file and return 
 * a mayday time in numeric format
 * 
 * Created December 2013
 */

#include <stdio.h>
#include <stdlib.h>
#include "mayday.h"
#include "mytime.h"
#include <time.h>


/*Creates a mayday structure, allocates memory and populates
 the structure with data from file*/
mayday_ptr read_mayday(char * mayday_file_name) {

  FILE * mayday_file;
  int read_status;
  mayday * mayday_in;
  struct tm temp_time; //time format structure (time.h)

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

    temp_time.tm_mon = temp_month - 1; //Months are represented numerically 0-11
    temp_time.tm_year = temp_year - 1900; //struct tm only counts years from 1900
    temp_time.tm_isdst = 0;
    mayday_in->m_time = mktime(&temp_time);

    if (read_status == EOF) {
      fclose(mayday_file);
      return NULL;
    } else if (read_status != 9) { //check correct amount of data has been read
      printf("Mayday file looks incorrect or corrupt \n");
    } else {
      printf("Mayday read OK \n");
      return mayday_in;
    }

  }
  fclose(mayday_file);
  return NULL;
}

/*Returns the time of a mayday in numeric format (time.h)*/
time_t get_mayday_time(mayday_ptr mayday_in) {

  time_t mayday_time = mayday_in->m_time;
  
  return mayday_time;
}



