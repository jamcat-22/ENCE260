/** @file   screens.c
    @author Janelle Kwan: jkw81, Rory Holmes: rho66
    @date   17 Oct 2021
	@brief  Display screens
*/

#include "screens.h"

/**
* Displays a temporary smiley face
*/
void success(void)
{
	uint8_t current_col = 0;
	int cnt = 0;
	while (1) {
        pacer_wait ();
        ledmat_display_column(smile[current_col], current_col);
        current_col++;
        if (current_col > (LEDMAT_COLS_NUM - 1)) {
            current_col = 0;
        }
		//Returns when count reached
		if (cnt == 1000) {
			return;
		}
		cnt++;
    }
}

/**
* Displays a sad face until navswitch is pushed
*/
void fail(void)
{
	uint8_t current_col = 0;
	while (1) {
        pacer_wait ();
        ledmat_display_column(sad[current_col], current_col);
        current_col++;
        if (current_col > (LEDMAT_COLS_NUM - 1)) {
            current_col = 0;
        }
		navswitch_update ();
		//Exits when navswitch is pushed
		if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
			return;
		}
    }
}

/**
 * Displays "YOU WON" text in win condition
 */
void win(void)
{
    tinygl_disp("YOU WON");

    while (1) {
        pacer_wait();
        
        tinygl_update();
        navswitch_update();

        //Exits when navswitch is pushed
		if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
			return;
		}
    }
}

/**
 * Displays "START" and calls select_length when navswitch is pushed
 */
int start(void)
{
    tinygl_disp("START");

    while (1) {
        pacer_wait();
        
        tinygl_update();
        navswitch_update();
        
        //Calls select_length when navswitch is pushed
		if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
			return select_length();
		}
    }
}

/**
 * Displays length, changes value if navswitched is pushed up or down
 */
int select_length(void) 
{
    //Initialisng method
    int length = 6;
    system_init ();
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);

    navswitch_init();

    pacer_init (PACER_RATE);

    while (1) {
        pacer_wait();
        tinygl_update ();
        navswitch_update();

        //Increases length int if not more than 9
        if (navswitch_push_event_p(NAVSWITCH_NORTH) && length < 9) {
            length++;
        }
        //Decreases length int if not more than 3
        if (navswitch_push_event_p(NAVSWITCH_SOUTH) && length > 3) {
            length--;
        }
        //Returns currently displayed length
        if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
			return length;
		}

        display_char (length + '0');
    }   
}

/**
* Displays character on the grid
*/
void display_char (char character)
{
    char buffer[2];

    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

/**
* Initialises tinygl for displaying text
*/
void tinygl_disp(char text[])
{
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text(text);
    pacer_init (PACER_RATE);
}
