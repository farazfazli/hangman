#ifndef HANGMAN_RNG_H
#define HANGMAN_RNG_H

#include <stdlib.h>

/**
 * Initializes Random Number Generator
 * Note: RNG is based on the current time and thus does not produce secure values.
 * This is intentional, as the RNG is solely used to select a random current word.
 */
void rng_init(void);

/**
 * Helper method for Random Number Generation
 * @param max - max number
 * @return between 0 to max
 */
size_t rng_to(size_t max);

#endif //HANGMAN_RNG_H