/* 
 * File:   rescue_handler.h
 * Author: sig2
 *
 * Created on 08 December 2013, 18:53
 */

#ifndef RESCUE_HANDLER_H
#define	RESCUE_HANDLER_H

#ifdef	__cplusplus
extern "C" {
#endif

  double get_response_time(ship_ptr ship, r_asset_ptr asset);
  bool can_return(double time, mayday_ptr md_ship, r_asset_ptr asset);
  void respond_to_mayday(ship_ptr to_rescue, mayday_ptr mayday_in);
  



#ifdef	__cplusplus
}
#endif

#endif	/* RESCUE_HANDLER_H */

