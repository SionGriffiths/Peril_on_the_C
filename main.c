/* 
 * File:   main.c
 * Author: sig2
 *
 * Created on 19 November 2013, 18:15
 */

#include <stdio.h>
#include <stdlib.h>
#include "rescue_assets.h"

/*
 * 
 */
int main(int argc, char** argv) {

  make_asset_list("rescue_assets.txt");
  
  r_asset_ptr itar = get_r_asset_head();
  int count =0;
  while(itar != NULL){
    printf("Asset is %s \n", itar -> callsign);
    itar = itar -> next;
    count++;
  }
  
  printf("%d", count);
  return (EXIT_SUCCESS);
}

