/** @file   pattern.h
    @author Janelle Kwan: jkw81, Rory Holmes: rho66
    @date   17 Oct 2021
	@brief  Displays pattern
*/

#ifndef PATTERN_H
#define PATTERN_H

#include "system.h"
#include "pio.h"
#include "pacer.h"

static const pio_t rows[] =
{
    LEDMAT_ROW1_PIO, LEDMAT_ROW2_PIO, LEDMAT_ROW3_PIO, 
    LEDMAT_ROW4_PIO, LEDMAT_ROW5_PIO, LEDMAT_ROW6_PIO,
    LEDMAT_ROW7_PIO
};

static const pio_t cols[] =
{
    LEDMAT_COL1_PIO, LEDMAT_COL2_PIO, LEDMAT_COL3_PIO,
    LEDMAT_COL4_PIO, LEDMAT_COL5_PIO
};

/** Clears display */
void clear(void);

/** Displays pattern */
void pattern(int* col_pattern, int* row_pattern, int pattern_count);

#endif
