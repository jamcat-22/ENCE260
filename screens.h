/** @file   screens.h
    @author Janelle Kwan: jkw81, Rory Holmes: rho66
    @date   17 Oct 2021
	@brief  Display screens
*/

#ifndef SCREENS_H
#define SCREENS_H

#define PACER_RATE 500
#define MESSAGE_RATE 14

#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "system.h"
#include "pio.h"
#include "pacer.h"
#include "navswitch.h"
#include "pattern.h"
#include "ledmat.h"

/** Smiley face */
static const uint8_t smile[] =
{
    0b00110000,
	0b01000111,
	0b01000000,
	0b01000111,
	0b00110000
};

/** Sad face */
static const uint8_t sad[] =
{
    0b01100000,
	0b00010111,
	0b00010000,
	0b00010111,
	0b01100000
};

/** Displays a temporary smiley face */
void success(void);

/** Displays a sad face */
void fail(void);

/** Displays "YOU WON" text in win condition */
void win(void);

/** Displays "START" and calls select_length when navswitch is pushed*/
int start(void);

/** Displays length, changes value if navswitched is pushed up or down */
int select_length(void);

/** Displays character on the grid */
void display_char(char);

/** Initialises tinygl for displaying text */
void tinygl_disp(char *);

#endif
