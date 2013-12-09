/* 
 * File:   time.h
 * Author: sig2
 *
 * Created on 02 December 2013, 11:09
 */
#include <time.h>

#ifndef TIME_H
#define	TIME_H


time_t read_time(FILE * file_in);
time_t get_current_time();
void set_current_time(time_t in_time);
double time_diff(time_t past, time_t now);

#endif	/* TIME_H */

