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
#include "rescue_handler.h"
#include "linked_list.h"

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

  time_t start_time = get_current_time();

  char mayday_filename[30];

  printf("Please enter the name of a mayday file : ");
  scanf("%s", mayday_filename);
  mayday_ptr mayday1 = read_mayday(mayday_filename);
  
  time_t m_time = mayday1 -> m_time;
  fprintf(get_log_file(), "Mayday received at %s \n", ctime(&m_time));
  printf("Mayday received at %s \n", ctime(&m_time));

  double timediff;
  timediff = time_diff(m_time, start_time);



  ship_ptr to_rescue = find_ship_by_id(mayday1->ais_id);
  

  if (to_rescue != NULL) {
    update_ship(to_rescue, timediff);
    fprintf(get_log_file(), "Ship in peril is %s \n", to_rescue->ais_id);
    check_position(to_rescue);
    respond_to_mayday(to_rescue, mayday1);
  } else {
    printf("Ship untracked, not responding to mayday");
    fprintf(get_log_file(), "Call from untracked vessel; not responding to mayday \n");
  }




  end_logging();
  return (EXIT_SUCCESS);
}

