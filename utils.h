#pragma once

#include <stdlib.h>

/**
 * Prints the state of each letter and counts the number of underscores
 * @param word_to_guess - word being guessed (array of pointers)
 * @return underscore count
 */
size_t print_count_underscores(char **word_to_guess);

/**
 * Returns the distance from 'a'
 * @param letter 'a' to 'z'
 * @return 0 through 25
 */
size_t from_a(int letter);
