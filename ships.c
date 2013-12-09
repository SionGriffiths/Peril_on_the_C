#include <stdio.h>
#include <stdlib.h>
#include "ships.h"
#include "navigation.h"
#include "mytime.h"
#include <string.h>
#include "log_file_handler.h"


static ship_ptr ship_head = NULL;

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


  ship_ptr head;
  ship_ptr in_ship;
  time_t in_time;

  ships_file = fopen(ship_file_name, "r");

  if (ships_file != NULL) {

    in_time = read_time(ships_file);
    set_current_time(in_time);
    head = read_ship(ships_file);
    add_ship(head);

    int count = 1;
    while ((in_ship = read_ship(ships_file)) != NULL) {
      add_ship(in_ship);
      count++;
    }
    printf("Read in %d ships OK \n", count);
    fprintf(get_log_file(), "Tracking %d ships..\n", count);
    fclose(ships_file);

  } else {
    printf("Could not read file \n");
    return 0;
  }
  return 1;
}

void add_ship(ship_ptr to_add) {

  ship_ptr iterate = ship_head;

  if (ship_head == NULL) {
    ship_head = to_add;

  } else if (ship_head -> next == NULL) {
    ship_head -> next = to_add;

  } else {
    while (iterate != NULL) {
      if (iterate -> next == NULL) {
        iterate -> next = to_add;

        break;
      }
      iterate = iterate -> next;
    }
  }
}

ship_ptr get_ship_head() {
  return ship_head;
}

ship_ptr find_ship_by_id(char * id) {

  ship_ptr itar = get_ship_head();

  while (itar != NULL) {
    if (strcmp(itar->ais_id, id) == 0) {
      return itar;
    }
    itar = itar -> next;
  }

  printf("no ship found \n");
  return NULL;
}