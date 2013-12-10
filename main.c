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
  char msg_buffer[1024];
  printf("\n\n\t\t\tPERIL ON THE C!\n\n ");

  char ra_filename[30];


  do {
    printf("Please enter the name of a rescue assets file : ");

    scanf("%s", ra_filename);
  } while (make_asset_list(ra_filename) == 1);


  char ships_filename[30];

  do {
    printf("Please enter the name of a ships file : ");
    scanf("%s", ships_filename);
  } while (make_ship_list(ships_filename) == 1);

  time_t start_time = get_current_time();

  char mayday_filename[30];

  printf("Please enter the name of a mayday file : ");
  scanf("%s", mayday_filename);
  mayday_ptr mayday1 = read_mayday(mayday_filename);

  time_t m_time = mayday1 -> m_time;

  sprintf(msg_buffer, "Mayday received from %s at %s \n", mayday1->ais_id, ctime(&m_time));
  output_event(msg_buffer);
  double timediff;
  timediff = time_diff(m_time, start_time);



  ship_ptr to_rescue = find_ship_by_id(mayday1->ais_id);


  if (to_rescue != NULL) {
    update_ship(to_rescue, timediff);
    check_position(to_rescue);
    respond_to_mayday(to_rescue, mayday1);
  } else {
    sprintf(msg_buffer, "Vessel %s, is untracked on our system : unable to respond \n", mayday1->ais_id);
    output_event(msg_buffer);
  }





  return (EXIT_SUCCESS);
}

