/** @file   pattern.c
    @author Janelle Kwan: jkw81, Rory Holmes: rho66
    @date   17 Oct 2021
	@brief  Displays pattern
*/

#include "pattern.h"

/**
* Clears/initialises the display
*/
void clear(void)
{
	for (uint8_t i = 0; i < LEDMAT_ROWS_NUM; i++) {
		pio_config_set (rows[i], PIO_OUTPUT_HIGH);
	}
	for (uint8_t i = 0; i < LEDMAT_COLS_NUM; i++) {
		pio_config_set (cols[i], PIO_OUTPUT_HIGH);
	}
}

/**
* Displays the pattern provided
*/
void pattern(int* col_pattern, int* row_pattern, int pattern_count)
{
	pacer_init (1);
	clear();
	//Individually displays the pattern
	for (int i = 0; i < pattern_count; i++) {
		pacer_wait ();
		pio_output_low (cols[col_pattern[i]]);
		pio_output_low (rows[row_pattern[i]]);
		pacer_wait ();
		clear();
	}
}
