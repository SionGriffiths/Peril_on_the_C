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

  char msg_buffer[1024];
  r_asset_ptr best_boat;
  double best_boat_time = INT_MAX;
  double boat_return_time = 0;
  r_asset_ptr best_heli;
  double best_heli_time = INT_MAX;
  double heli_return_time = 0;

  node_ptr itar = get_asset_list()->head;


  while (itar != NULL) {
    double time = get_response_time(to_rescue, itar->node_data);

    if (can_return(time, mayday_in, itar->node_data)) {
      if (is_helicopter(itar->node_data)) {
        if (time < best_heli_time) {
          best_heli = itar->node_data;
          best_heli_time = time;
          heli_return_time = (time * 2) + mayday_in->heli_minutes;
        }
      } else {
        if (time < best_boat_time) {
          best_boat = itar->node_data;
          best_boat_time = time;
          boat_return_time = (time * 2) + mayday_in->boat_minutes;
        }
      }
    }

    itar = itar->next;

  }

  if (best_boat == NULL) {
    printf("No boats able to respond \n");
  }
  if (best_heli == NULL) {
    printf("No helicopters able to respond \n");
  }


  sprintf(msg_buffer, "Assets responding to mayday %s and %s \n", best_heli->callsign, best_boat->callsign);
  output_event(msg_buffer);

  time_t heli_time = mayday_in->m_time + (best_heli_time * 60);
  time_t boat_time = mayday_in->m_time + (best_boat_time * 60);

  sprintf(msg_buffer, "Helicopter %s due on scene at %s \nLifeboat %s due on scene at %s \n",
          best_heli->callsign, ctime(&heli_time), best_boat->callsign, ctime(&boat_time));
  output_event(msg_buffer);

  heli_time = mayday_in->m_time + ((heli_return_time + best_heli->turn_around_time)*60);
  boat_time = mayday_in->m_time + ((boat_return_time + best_boat->turn_around_time)*60);

  sprintf(msg_buffer, "%s ready for redeployment at %s \n%s ready for redeployment at %s \n",
          best_heli->callsign, ctime(&heli_time), best_boat->callsign, ctime(&boat_time));
  output_event(msg_buffer);

}












