/* 
 * File:   rescue_handler.h
 * Author: sig2
 *
 * Description : Specifies functions that facilitate mayday response functionality 
 *               
 * Created December 2013
 */

#include "navigation.h"
#include "ships.h"
#include "rescue_assets.h"
#include <stdbool.h>
#include "mayday.h"
#include <limits.h>
#include "log_file_handler.h"

/*Returns number of minutes required for an asset to reach a ship*/
double get_response_time(ship_ptr ship, r_asset_ptr asset) {

  //great_circle returns the distance between 2 locations (navigation.h)
  double distance = great_circle(ship->loc, asset->loc);

  double time = distance / asset->speed;

  return time * 60;

}

/*Returns a boolean representing whether an asset can return safely from
 attending a ship*/
bool can_return(double time, mayday_ptr md_ship, r_asset_ptr asset) {

  time = time * 2; //Considering return journey too
  if (is_helicopter(asset)) {
    time += md_ship->heli_minutes; //Helicopter must spend fuel whilst attending
  }
  if (time > asset->max_deploy_time) {
    return false;
  } else {
    return true;
  }
}

/*Despatches rescue assets to ships following a mayday. Finds the boat and helicopter
 that are able to respond the fastest and return safely to base*/
void respond_to_mayday(ship_ptr to_rescue, mayday_ptr mayday_in) {

  char msg_buffer[1024];

  r_asset_ptr best_boat; //hold boat with best response time
  double best_boat_time = INT_MAX; //best response time, initially max int
  double boat_return_time = 0; //round trip duration for the rescue

  r_asset_ptr best_heli; //hold heli with best response time
  double best_heli_time = INT_MAX;
  double heli_return_time = 0;

  /*Initialise a node pointer for iterating through the asset list,
   * set to list head */
  node_ptr itar = get_asset_list()->head;


  while (itar != NULL) {

    /*Calculate time for this asset to respond*/
    double time = get_response_time(to_rescue, itar->node_data);

    if (can_return(time, mayday_in, itar->node_data)) {
      if (is_helicopter(itar->node_data)) {
        if (time < best_heli_time) { //if this helicopter will respond quickest..
          best_heli = itar->node_data;
          best_heli_time = time; //use it's time to compare with next iteration
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

    itar = itar->next; //iterator set to next node in list

  }

  /*Only dispatch assets if both a helicopter and boat can attend*/
  if ((best_boat == NULL) || (best_heli == NULL)) {
    sprintf(msg_buffer,"No assets currently able to respond to mayday\n");
    output_event(msg_buffer);
  } else {
    sprintf(msg_buffer, "Assets responding to mayday %s and %s \n", best_heli->callsign, best_boat->callsign);
    output_event(msg_buffer);

    /*Calculate when assets will reach target*/
    time_t heli_time = mayday_in->m_time + (best_heli_time * 60); 
    time_t boat_time = mayday_in->m_time + (best_boat_time * 60);

    sprintf(msg_buffer, "Helicopter %s due on scene at %s \nLifeboat %s due on scene at %s \n",
            best_heli->callsign, ctime(&heli_time), best_boat->callsign, ctime(&boat_time));
    output_event(msg_buffer);

    /*Calculate when assets will be next available for deployment*/
    heli_time = mayday_in->m_time + ((heli_return_time + best_heli->turn_around_time)*60);
    boat_time = mayday_in->m_time + ((boat_return_time + best_boat->turn_around_time)*60);

    sprintf(msg_buffer, "%s ready for redeployment at %s \n%s ready for redeployment at %s \n",
            best_heli->callsign, ctime(&heli_time), best_boat->callsign, ctime(&boat_time));
    output_event(msg_buffer);

  }
}











