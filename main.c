/* 
 * File:   main.c
 * Author: sig2
 *
 * Created on 19 November 2013, 18:15
 */

#include <stdio.h>
#include <stdlib.h>
#include "rescue_assets.h"
#include "ships.h"
#include "mytime.h"
/*
 * 
 */
int main(int argc, char** argv) {

  
  printf("\n\n\t\t\tPERIL ON THE C!\n\n ");
  printf("Please enter the name of a rescue assets file : ");
  char ra_filename[30];
  scanf("%s", ra_filename);  
  make_asset_list(ra_filename);
  
  printf("Please enter the name of a ships file : ");
  char ships_filename[30];
  scanf("%s", ships_filename);  
  make_ship_list(ships_filename);
  
  time_ptr start_time = get_current_time();
  
  printf("Please enter the name of a ships file : ");
  char ships_filename2[30];
  scanf("%s", ships_filename2);  
  make_ship_list(ships_filename2);
  
  time_ptr new_time = get_current_time();
  
  show_time(start_time);
  show_time(new_time);
  
  printf("%.f", time_diff(new_time, start_time));
  
  
  return (EXIT_SUCCESS);
}

