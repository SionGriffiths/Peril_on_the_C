/* 
 * File:   mayday.h
 * Author: sig2
 *
 * Created on 04 December 2013, 20:56
 */
#include "mytime.h"
#include <time.h>
#ifndef MAYDAY_H
#define	MAYDAY_H

typedef struct mday{
  int day;
  int month;
  int year;
  int hours;
  int minutes;
  int seconds;
  char ais_id[30];
  int boat_minutes;
  int heli_minutes;
}mayday;

typedef mayday * mayday_ptr;

mayday_ptr read_mayday(char * mayday_file_name);
time_ptr get_mayday_time(mayday_ptr mayday_in);

#endif	/* MAYDAY_H */

