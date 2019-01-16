#include <stdlib.h>

#pragma once

// initializes random number generator
void init_rng(void);

/**
 * Helper method for Random Number Generation
 * @param max - max number
 * @return between 0 to max
 */
size_t rand_to(size_t max);
