#include <stdio.h>
#include <stdlib.h>
#include "ships.h"
#include "navigation.h"
#include "time.h"


ship_ptr ship_head;

ship_ptr read_ship(FILE* ships_file) {

  int read_status;
  ship * in_ship;

  in_ship = calloc(1, sizeof (ship));


  read_status = fscanf(ships_file, "%s%f%f%f%f",
          in_ship->ais_id,
          &in_ship->loc.lat,
          &in_ship->loc.lng,
          &in_ship->heading,
          &in_ship->speed);

  if (read_status == EOF) {
    return NULL;
  } else {
    return in_ship;
  }
}

void make_ship_list(char * ship_file_name){
  
  FILE * ships_file;
  
  ship_ptr head;
  ship_ptr in_ship;
  time_ptr new_time;
  
  ships_file = fopen(ship_file_name, "r");
  
  
  
}