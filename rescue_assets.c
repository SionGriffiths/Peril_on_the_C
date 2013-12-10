/* 
 * File:   rescue_assets.c
 * Author: sig2
 * 
 * Description : Specifies functions to create asset structures, populate those 
 * structures with data from file, return a list of asset and return asset type. 
 *               
 * Created December 2013
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "rescue_assets.h"
#include "linked_list.h"
#include "log_file_handler.h"
#include <string.h>


/*static to prevent global scope*/
static list_ptr asset_list;

/*Read a line of file input, create a structure, allocate memory and populate
 structure fields with data from file, returns an asset*/
r_asset_ptr read_asset(FILE * resources_file) {

  int read_status;
  rescue_asset * in_asset;

  //Dynamic allocation of memory for a rescue asset
  in_asset = calloc(1, sizeof (struct r_asset));


  //name, type, base, lat, long, speed, range, turn around time

  read_status = fscanf(resources_file, "%s%1s%s%lf%lf%f%d%d",
          in_asset -> callsign,
          in_asset -> kind,
          in_asset -> base,
          &in_asset -> loc.lat,
          &in_asset -> loc.lng,
          &in_asset -> speed,
          &in_asset -> max_deploy_time,
          &in_asset -> turn_around_time);

  if (read_status == EOF) {
    return NULL;
  } else if (read_status != 8) {
    printf("Rescue asset data looks incorrect or corrupt \n");
    return NULL;
  } else {
    return in_asset;
  }
}

/*Populates a list of assets read in from file*/
int make_asset_list(char * resource_file_name) {

  FILE * resource_file;
  char msg_buffer[1024]; //output message buffer (log_file_handler.c)

  r_asset_ptr asset_in;
  init_list(&asset_list); //initialises a linked list of assets (linked_list.c)

  resource_file = fopen(resource_file_name, "r");

  if (resource_file != NULL) {


    int count = 0;
    while ((asset_in = read_asset(resource_file)) != NULL) {

      node_ptr link_asset; 
      init_node(&link_asset, asset_in); //initialises a link list node (linked_list.c)
      add_to_list(&link_asset, &asset_list); //add asset to the list
      count++;

    }
    printf("Read in %d assets OK \n", count);

    sprintf(msg_buffer, "%d Rescue assets currently on call...\n", count);
    output_event(msg_buffer); //send formatted string to output (log_file_handler.c)
    fclose(resource_file);

  } else {
    printf("Could not find file \n");
    return 0;
  }

  return 1;
}

/*Return the asset linked list*/
list_ptr get_asset_list() {
  return asset_list;
}

/*Return a boolean - whether parameter asset is of type helicopter*/
bool is_helicopter(r_asset_ptr asset) {
  return (strcmp(asset->kind, "H") == 0);
}
