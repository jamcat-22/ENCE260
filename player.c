/** @file   player.c
    @author Janelle Kwan: jkw81, Rory Holmes: rho66
    @date   17 Oct 2021
	@brief  Move the player
*/

#include "player.h"

/**
* Allows the player to move over the display
* Returns player position when navswitch is pushed
*/
tinygl_point_t player(tinygl_point_t pos)
{
	pacer_init (500);
    navswitch_init ();
	tinygl_init (300);

    while (1)
    {
        pacer_wait ();
		tinygl_pixel_set (pos, 1);
		
		//Moves the player
        if (navswitch_push_event_p (NAVSWITCH_WEST) && pos.x > 0) {
            tinygl_pixel_set (pos, 0);
			pos.x--;
        }
        if (navswitch_push_event_p (NAVSWITCH_EAST) && pos.x < TINYGL_WIDTH - 1) {
            tinygl_pixel_set (pos, 0);
			pos.x++;
        }
        if (navswitch_push_event_p (NAVSWITCH_SOUTH) && pos.y < TINYGL_HEIGHT - 1) {
            tinygl_pixel_set (pos, 0);
			pos.y++;
        }
        if (navswitch_push_event_p (NAVSWITCH_NORTH) && pos.y > 0) {
            tinygl_pixel_set (pos, 0);
			pos.y--;
        }
		
		navswitch_update ();
		tinygl_update ();
		
		//Returns player position when navswitch pushed
        if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
			return pos;
        }
    }
}
