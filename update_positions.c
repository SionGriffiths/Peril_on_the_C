/* 
 * File:   update_positions.c
 * Author: sig2
 *
 * Created on 04 December 2013, 18:54
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ships.h"
#include <stdbool.h>

double deg_to_rad(double angle_in) {
  return (angle_in * M_PI) / 180;
}

double update_lat(ship_ptr ship_in, double minutes) {

  double old_lat = ship_in->loc.lat;
  double speed = ship_in->speed;
  double course = deg_to_rad(ship_in->heading);

  double new_lat = old_lat + (speed * cos(course) * minutes) / 3600;

  return new_lat;
}

double update_long(ship_ptr ship_in, double minutes) {

  double old_long = ship_in -> loc.lng;
  double speed = ship_in ->speed;
  double course = deg_to_rad(ship_in->heading);
  double lat_rad = deg_to_rad(ship_in->loc.lat);

  double new_long = old_long + (speed * sin(course) * minutes / cos(lat_rad)) / 3600;

  printf("Speed : %lf \n", ship_in-> speed);
  printf("Ship is %s \n", ship_in -> ais_id);
  return new_long;
}

ship_ptr update_ship(ship_ptr ship_in, double minutes) {
  double temp_lat = update_lat(ship_in, minutes);
  double temp_long = update_long(ship_in, minutes);

  ship_in ->loc.lat = temp_lat;
  ship_in ->loc.lng = temp_long;

  return ship_in;
}

bool check_position(ship_ptr to_check) {
  bool in_range = true;
  if ((to_check->loc.lat < 51.667) || (to_check->loc.lat > 52.883)) {
    in_range = false;
    printf("Ship latitude out of range \n");
  } else if ((to_check->loc.lng < -6.667) || (to_check->loc.lng > -3.833)) {
    in_range = false;
    printf("Ship longitude out of range \n");
  } else {
    printf("Ship position ok \n");
  }
  return in_range;
}
