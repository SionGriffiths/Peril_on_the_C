#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "rescue_assets.h"
#include "linked_list.h"
#include "log_file_handler.h"
#include <string.h>



static list_ptr asset_list;

r_asset_ptr read_asset(FILE * resources_file) {

  int read_status;
  rescue_asset * in_asset;

  //Dynamic allocation of memory for a rescue asset
  in_asset = calloc(1, sizeof (rescue_asset));


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

int make_asset_list(char * resource_file_name) {

  FILE * resource_file;


  r_asset_ptr asset_in;
  init_list(&asset_list);

  resource_file = fopen(resource_file_name, "r");

  if (resource_file != NULL) {


    int count = 0;
    while ((asset_in = read_asset(resource_file)) != NULL) {
      node_ptr link_asset;
      link_asset = calloc(1, sizeof (node));
      link_asset->next = NULL;
      link_asset->node_data = asset_in;
      add_to_list(&link_asset, &asset_list);
      count++;
    }
    printf("Read in %d assets OK \n", count);
    fprintf(get_log_file(), "%d Rescue assets currently on call...\n", count);
    fclose(resource_file);

  } else {
    printf("Could not find file \n");
    return 0;
  }

  return 1;
}

/*
void add_asset(r_asset_ptr to_add) {

  r_asset_ptr iterate = asset_head;

  if (asset_head == NULL) {
    asset_head = to_add;

  } else if (asset_head -> next == NULL) {
    asset_head -> next = to_add;

  } else {
    while (iterate != NULL) {
      if (iterate -> next == NULL) {
        iterate -> next = to_add;

        break;
      }
      iterate = iterate -> next;
    }
  }

}*/

list_ptr get_asset_list() {
  return asset_list;
}

bool is_helicopter(r_asset_ptr asset) {
  return (strcmp(asset->kind, "H") == 0);
}
