/* 
 * File:   rescue_handler.h
 * Author: sig2
 *
 * Description : Defines functions that facilitate mayday response functionality 
 *               
 * Created December 2013
 */

#ifndef RESCUE_HANDLER_H
#define	RESCUE_HANDLER_H

#ifdef	__cplusplus
extern "C" {
#endif

  /*Function prototype for the function that calculates the time for an
   * asset to reach a ship */
  double get_response_time(ship_ptr ship, r_asset_ptr asset);
  
  /*Function prototype for the function that calculates whether an asset
   can return safely from attending a ship*/
  bool can_return(double time, mayday_ptr md_ship, r_asset_ptr asset);
  
  /*Function prototype for the function that despatches assets to respond to a
   mayday*/
  void respond_to_mayday(ship_ptr to_rescue, mayday_ptr mayday_in);
  



#ifdef	__cplusplus
}
#endif

#endif	/* RESCUE_HANDLER_H */

