/* 
 * File:   time.h
 * Author: sig2
 *
 * Created on 02 December 2013, 11:09
 */

#ifndef TIME_H
#define	TIME_H

typedef struct timestr{
  int year;
  int month;
  int day;
  int hours;
  int minutes;
  int seconds;
}time;

typedef time * time_ptr;

time_ptr read_time(FILE * file_in);
time_ptr get_current_time();
void set_current_time(time_ptr in_time);

#endif	/* TIME_H */

