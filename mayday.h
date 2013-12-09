/* 
 * File:   mayday.h
 * Author: sig2
 * Description: Defines the structure of a mayday and the functions used to populate 
 * these structures from input file.
 * Created on 04 December 2013, 20:56
 */
#include "mytime.h"
#include <time.h>
#ifndef MAYDAY_H
#define	MAYDAY_H

typedef struct mday{
 
  time_t m_time;
  char ais_id[30];
  int boat_minutes;
  int heli_minutes;
}mayday;

typedef mayday * mayday_ptr;

mayday_ptr read_mayday(char * mayday_file_name);
time_t get_mayday_time(mayday_ptr mayday_in);

#endif	/* MAYDAY_H */

