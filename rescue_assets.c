#include <stdio.h>
#include <stdlib.h>
#include "rescue_assets.h"
#include "navigation.h"

r_asset_ptr asset_head = NULL;

r_asset_ptr read_asset(FILE * resources_file) {

  int read_status;
  rescue_asset * in_asset;

  //Dynamic allocation of memory for a rescue asset
  in_asset = calloc(1, sizeof (rescue_asset));


  //name, type, base, lat, long, speed, range, turn around time
  //%1s used for kind because C is a fucking wanker.
  read_status = fscanf(resources_file, "%s%1s%s%f%f%f%d%d",
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
  } else {
    return in_asset;
  }
}

void make_asset_list(char * resource_file_name) {

  FILE * resource_file;

  r_asset_ptr head;
  r_asset_ptr asset_in;

  resource_file = fopen(resource_file_name, "r");

  if (resource_file != NULL) {

    head = read_asset(resource_file);
    add_asset(head);
  }

  while ((asset_in = read_asset(resource_file)) != NULL) {
    add_asset(asset_in);
  }
}

void add_asset(r_asset_ptr to_add) {

  r_asset_ptr iterate = asset_head;

  if (asset_head == NULL) {
    asset_head = to_add;

  }
  else if (asset_head -> next == NULL) {
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

}

r_asset_ptr get_r_asset_head() {
  return asset_head;
}