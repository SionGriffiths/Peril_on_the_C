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
  double heading;
  double speed;
  struct shipstr * next;
}ship;

typedef ship * ship_ptr;

ship_ptr read_ship(FILE* ships_file);

void make_ship_list(char * ship_file_name);

void add_ship(ship_ptr to_add);

ship_ptr get_ship_head();

#endif	/* SHIPS_H */

