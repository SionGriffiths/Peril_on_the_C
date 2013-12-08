

#include "navigation.h"
#include "ships.h"
#include "rescue_assets.h"
#include <stdbool.h>
#include "mayday.h"
#include <limits.h>
#include "log_file_handler.h"

/*returns number of minutes required for an asset to reach a ship*/
double get_response_time(ship_ptr ship, r_asset_ptr asset) {
  double distance = great_circle(ship->loc, asset->loc);

  double time = distance / asset->speed;

  return time * 60;

}

bool can_return(double time, mayday_ptr md_ship, r_asset_ptr asset) {
  time = time * 2;
  if (is_helicopter(asset)) {
    time += md_ship->heli_minutes;
  }
  if (time > asset->max_deploy_time) {
    return false;
  } else {
    return true;
  }
}

void respond_to_mayday(ship_ptr to_rescue, mayday_ptr mayday_in) {

  r_asset_ptr best_boat;
  int best_boat_time = INT_MAX;
  r_asset_ptr best_heli;
  int best_heli_time = INT_MAX;
  
  r_asset_ptr itar = get_r_asset_head();
  
  
  while (itar != NULL) {
    double time = get_response_time(to_rescue, itar);

    if (can_return(time, mayday_in, itar)) {
      if (is_helicopter(itar)) {
        if (time < best_heli_time) {
          best_heli = itar;
          best_heli_time = time;
        }
      } else {
        if (time < best_boat_time) {
          best_boat = itar;
          best_boat_time = time;
        }
      }
    }

    itar = itar->next;

  }

  if(best_boat == NULL){
    printf("No boats able to respond");
  }
  if(best_heli == NULL){
    printf("No helicopters able to respond");
  }
  
  printf("Assets responding to mayday %s and %s", best_heli->callsign, best_boat->callsign);
  fprintf(get_log_file(), "Assets responding to mayday %s and %s", best_heli->callsign, best_boat->callsign);
  

}












