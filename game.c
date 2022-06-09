/** @file   game.c
    @author Janelle Kwan: jkw81, Rory Holmes: rho66
    @date   17 Oct 2021
	@brief  Memory game
*/

#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "pattern.h"
#include "player.h"
#include "screens.h"
#include <stdlib.h>

/**
* Returns a random integer
*/
int random_coord(int range)
{
	return rand() % range;
}

/**
* Main function for the game
*/
int main (void)
{
    system_init ();
	pacer_init (500);
    
	//Set variables
    bool show_start = true;
	int pattern_count = 0;
    int max_pattern;
	int col_pattern[9];
	int row_pattern[9];
	bool pattern_display = true;
	tinygl_point_t pos;
	clear();

	while (1) {
		pacer_wait ();
        
		//If it is the start of a new game
        if (show_start) {
            max_pattern = start();
            show_start = false;
        }        
		
		//Adds to pattern and displays, if the player sequence isn't complete
		if (pattern_display == true && pattern_count < max_pattern) {
			col_pattern[pattern_count] = random_coord(5);
			row_pattern[pattern_count] = random_coord(7);
			pattern_count++;
			pattern_display = false;
			pattern(col_pattern, row_pattern, pattern_count); //Displays pattern
		}
		//Sets player position to center
		pos.x = TINYGL_WIDTH / 2;
		pos.y = TINYGL_HEIGHT / 2;
		
		//Checks to see if player position is the same as the pattern
		for (int i = 0; i < pattern_count; i++) {
			pos = player(pos); //Gets player position after moving
			//If the player has chosen correctly
			if (pos.x == col_pattern[i] && pos.y == row_pattern[i]) {
				if (i == max_pattern - 1) { //If the player has completed the pattern
					win();
					show_start = true; //Restart
					pattern_count = 0;
				} else if (i == pattern_count - 1){ //If the player has completed a part of the pattern
					success();
				}
			} else {
				fail();
                show_start = true; //Restart
				pattern_count = 0;
			}
		}
		pattern_display = true;
	}
	
}
