/* 
 * File:   mayday.h
 * Author: sig2
 * 
 * Description: Defines the structure of a mayday and the functions used to populate 
 * the structure from input file and return the time of a mayday.
 * 
 * Created December 2013
 */
#include "mytime.h"
#include <time.h>
#ifndef MAYDAY_H
#define	MAYDAY_H

typedef struct mday{
 
  time_t m_time; //numeric representation of time - seconds since epoch (time.h)
  char ais_id[30]; //Unique vessel identifier - used throughout the program
  int boat_minutes; //minutes a boat must spend attending this mayday
  int heli_minutes; //minutes a helicopter must spend attending this mayday
}mayday;

typedef mayday * mayday_ptr;

/*Function prototype for the function that populates a mayday structure from file*/
mayday_ptr read_mayday(char * mayday_file_name);

/*Function returns the time in numberic format*/
time_t get_mayday_time(mayday_ptr mayday_in);

#endif	/* MAYDAY_H */

