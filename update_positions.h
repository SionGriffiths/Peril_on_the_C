/* 
 * File:   update_positions.h
 * Author: sig2
 *
 * Created on 04 December 2013, 19:25
 */

#ifndef UPDATE_POSITIONS_H
#define	UPDATE_POSITIONS_H

double deg_to_rad(double angle_in);
double update_long(ship_ptr ship_in, double minutes);
double update_lat(ship_ptr ship_in, double minutes);
ship_ptr update_ship(ship_ptr ship_in, double minutes);

#endif	/* UPDATE_POSITIONS_H */

