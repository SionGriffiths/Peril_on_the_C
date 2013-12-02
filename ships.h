/* 
 * File:   ships.h
 * Author: sig2
 *
 * Created on 02 December 2013, 11:28
 */
#include "navigation.h"

#ifndef SHIPS_H
#define	SHIPS_H

typedef struct shipstr{
  char ais_id[30];
  location loc;
  float heading;
  float speed;
  struct shipstr * next;
}ship;

typedef ship * ship_ptr;

#endif	/* SHIPS_H */

