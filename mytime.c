/* 
 * File:   mytime.h
 * Author: sig2
 * Description :  Specifies utility functions related to time representation.
 * 
 * Created on December 2013
 */

#include <stdio.h>
#include <stdlib.h>
#include "ships.h"
#include "navigation.h"
#include "mytime.h"
#include <time.h>
#include "log_file_handler.h"

/*Current time requires file-wide scope,
 static to prevent global access*/
static time_t current_time;

/*Function creates, allocates memory for and populates a 
 struct tm (time.h) to represent a time. Data is read in from file.
 Converts struct tm to numerical time format that is returned*/
time_t read_time(FILE * file_in) {

  int read_status;
  char msg_buffer[1024]; //event message buffer
  struct tm new_time;


  /*temp varibales here for conversion from file date format to format
  accepted by struct tm (time.h)
   */
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
  
  time_t ret_value; //define a time_t(time.h) variable for returning
  
  if (read_status == EOF) {
    return ret_value; //will be null
  } else {
    printf("Time read ok \n");
    
    /*mktime is defined in time.h : converts a struct tm to numerical time format: time_t*/
    ret_value = mktime(&new_time); 

    sprintf(msg_buffer, "Time is %s \n", ctime(&ret_value)); //format a string for output
    output_event(msg_buffer);//send formatted string to output (log_file_handler.c)
    
    return ret_value; //return the time
  }


}


time_t get_current_time() {
  return current_time;
}

void set_current_time(time_t in_time) {
  current_time = in_time;
}

/*Function returns a double representing the difference in minutes between 2
 numeric-format time representation*/
double time_diff(time_t past, time_t now) {

  //difftime (defined in time.h) returns seconds - convert to minutes
  return (difftime(past, now)) / 60;
}




