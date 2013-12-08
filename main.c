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
#include "mayday.h"
#include <time.h>
#include "update_positions.h"
#include "log_file_handler.h"

/*
 * 
 */
int main(int argc, char** argv) {
  start_logging();

  printf("\n\n\t\t\tPERIL ON THE C!\n\n ");

  char ra_filename[30];


  do {
    printf("Please enter the name of a rescue assets file : ");

    scanf("%s", ra_filename);
  } while (make_asset_list(ra_filename) == 0);


  char ships_filename[30];

  do {
    printf("Please enter the name of a ships file : ");
    scanf("%s", ships_filename);
  } while (make_ship_list(ships_filename) == 0);
  
  time_ptr start_time = get_current_time();

  char mayday_filename[30];

  printf("Please enter the name of a mayday file : ");
  scanf("%s", mayday_filename);
  mayday_ptr mayday1 = read_mayday(mayday_filename);
  time_ptr mayday1_time = get_mayday_time(mayday1);

  show_time(mayday1_time);

  double timediff;
  timediff = time_diff(mayday1_time, start_time);

  printf("difference is %f minutes \n", timediff);

  ship_ptr to_rescue = find_ship_by_id(mayday1->ais_id);

  printf("to_rescue coord :\n %f \n %f \n", to_rescue->loc.lat, to_rescue->loc.lng);
  update_ship(to_rescue, timediff);
  printf("to_rescue coord :\n %f \n %f \n", to_rescue->loc.lat, to_rescue->loc.lng);
  check_position(to_rescue);





  end_logging();
  return (EXIT_SUCCESS);
}

