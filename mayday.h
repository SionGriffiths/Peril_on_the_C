/* 
 * File:   mayday.h
 * Author: sig2
 *
 * Created on 04 December 2013, 20:56
 */

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

#endif	/* MAYDAY_H */

