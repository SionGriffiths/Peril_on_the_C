/* 
 * File:   resource.h
 * Author: sig2
 *
 * Created on 01 December 2013, 17:58
 */
#include "navigation.h"

#ifndef RESCUE_ASSETS_H
#define	RESCUE_ASSETS_H

typedef struct r_asset {
  
  char callsign[50];
  //YOU'D THINK THIS WOULDN'T NEED TO BE AN ARRAY OF CHAR TO HOLD 1 FUCKING LETTER.
  //YOU'D BE WRONG. 
  char kind[2];
  char base[30];
  //location struct from navigation.h - holds 2 doubles representing lat/long.
  location loc;
  float speed;
  int max_deploy_time;
  int turn_around_time;
  struct r_asset * next;

} rescue_asset;

typedef rescue_asset * r_asset_ptr;




void add_asset(r_asset_ptr);
r_asset_ptr get_r_asset_head();
void make_asset_list(char * resource_file_name);
r_asset_ptr read_asset(FILE * resources_file);

#endif /*RESCUE_ASSETS_H */