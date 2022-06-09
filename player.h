/** @file   player.h
    @author Janelle Kwan: jkw81, Rory Holmes: rho66
    @date   17 Oct 2021
	@brief  Move the player
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "system.h"
#include "navswitch.h"
#include "tinygl.h"
#include "pacer.h"

/** Allows the player to move over the display */
tinygl_point_t player(tinygl_point_t pos);

#endif
