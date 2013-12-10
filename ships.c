#include <stdio.h>
#include <stdlib.h>
#include "ships.h"
#include "navigation.h"
#include "mytime.h"
#include <string.h>
#include "log_file_handler.h"
#include "linked_list.h"


//static ship_ptr ship_head = NULL;
static list_ptr ship_list;

ship_ptr read_ship(FILE* ships_file) {

  int read_status;
  ship * in_ship;

  in_ship = calloc(1, sizeof (ship));


  read_status = fscanf(ships_file, "%s%lf%lf%lf%lf",
          in_ship->ais_id,
          &in_ship->loc.lat,
          &in_ship->loc.lng,
          &in_ship->heading,
          &in_ship->speed);

  if (read_status == EOF) {
    return NULL;
  } else if (read_status != 5) {
    printf("Ship data looks incorrect or corrupt \n");
    return NULL;
  } else {
    return in_ship;
  }
}

int make_ship_list(char * ship_file_name) {

  FILE * ships_file;
  char msg_buffer[1024];
  init_list(&ship_list);


  ship_ptr in_ship;
  time_t in_time;

  ships_file = fopen(ship_file_name, "r");

  if (ships_file != NULL) {

    in_time = read_time(ships_file);
    set_current_time(in_time);

    int count = 0;
    while ((in_ship = read_ship(ships_file)) != NULL) {
      node_ptr link_ship;
      init_node(&link_ship, in_ship);
      add_to_list(&link_ship, &ship_list);
      count++;
    }
    
    printf("Read in %d ships OK \n", count);
    sprintf(msg_buffer, "Tracking %d ships..\n", count);
    output_event(msg_buffer);
    fclose(ships_file);

  } else {
    printf("Could not read file \n");
    return 0;
  }
  return 1;
}

list_ptr get_ship_list() {
  return ship_list;
}

ship_ptr find_ship_by_id(char * id) {
  
  node_ptr itar = ship_list->head;

  while (itar != NULL) {
    ship_ptr find_ship = (ship_ptr) itar ->node_data;
    if (strcmp(find_ship->ais_id, id) == 0) {
      return find_ship;
    }
    itar = itar -> next;
  }

  printf("no ship found \n");
  return NULL;
}