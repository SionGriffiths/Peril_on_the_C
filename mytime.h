/* 
 * File:   time.h
 * Author: sig2
 *
 * Created on 02 December 2013, 11:09
 */
#include <time.h>
#ifndef TIME_H
#define	TIME_H
/*
typedef struct timestr{
  int year;
  int month;
  int day;
  int hours;
  int minutes;
  int seconds;
}time;*/

/*struct tm is defined in time.h */
typedef struct tm timestr;

typedef timestr * time_ptr;

time_ptr read_time(FILE * file_in);
time_ptr get_current_time();
void set_current_time(time_ptr in_time);
void show_time(time_ptr in_time);
double time_diff(time_ptr old, time_ptr new);

#endif	/* TIME_H */

