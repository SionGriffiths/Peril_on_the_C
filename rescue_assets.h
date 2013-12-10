/* 
 * File:   rescue_assets.h
 * Author: sig2
 * 
 * Description : Defines a rescue asset structure, specifies functions to read
 * data from file and populate the structure, return a list of assets and 
 * whether a resrouce is a helicopter. 
 *               
 * Created December 2013
 */
#include "navigation.h"
#include <stdbool.h>
#include "linked_list.h"

#ifndef RESCUE_ASSETS_H
#define	RESCUE_ASSETS_H

typedef struct r_asset {
  
  char callsign[50];
  char kind[2];
  char base[30];
  //location struct from navigation.h - holds 2 doubles representing lat/long.
  location loc;
  float speed;
  int max_deploy_time;
  int turn_around_time;
  
} rescue_asset;

typedef rescue_asset * r_asset_ptr;

list_ptr get_asset_list();
int make_asset_list(char * resource_file_name);
r_asset_ptr read_asset(FILE * resources_file);
bool is_helicopter(r_asset_ptr asset);

#endif /*RESCUE_ASSETS_H */