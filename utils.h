#pragma once

#include <stdlib.h>

/**
 * Returns length of array
 * @param arr - words array
 * @return length
 */
size_t len(char **arr);

/**
 * Prints the state of each letter and counts the number of underscores
 * @param word_to_guess - word being guessed (array of pointers)
 * @param word_len - length of word (excluding NUL char)
 * @return underscore count
 */
size_t print_count_underscores(char **word_to_guess, size_t word_len);

/**
 * Returns the distance from 'a'
 * @param letter 'a' to 'z'
 * @return 0 through 25
 */
size_t from_a(int letter);
