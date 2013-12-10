/* 
 * File:   mytime.h
 * Author: sig2
 * Description :  Defines utility functions related to time representation.
 * 
 * Created on December 2013
 */
#include <time.h>

#ifndef MYTIME_H
#define	MYTIME_H

/*Function prototype for the function that reads a time from file and 
 returns it in numeric format (time.h)*/
time_t read_time(FILE * file_in);

/*Function prototype for the function that returns the current time*/
time_t get_current_time();

/*Function prototype for the function that sets the current time*/
void set_current_time(time_t in_time);

/*Function prototype for the function that returns the difference between 2 times*/
double time_diff(time_t past, time_t now);

#endif	/* MYTIME_H */

