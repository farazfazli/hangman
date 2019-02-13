#ifndef HANGMAN_UTILS_H
#define HANGMAN_UTILS_H

#include <stdlib.h>

/**
 * Prints "hangman" ascii art
 * @param tries_left - must be <= 7 to display
 */
void print_hangman(int tries_left);

/**
 * Prints character, followed by a space
 * @param char_to_print
 */
void print_char(char char_to_print);

/**
 * Prints the state of each letter and counts the number of missing letters
 * Optionally calls a function with each character read
 * @param word_to_guess - word being guessed (array of pointers)
 * @param on_each - optional function to call on each iteration
 * @return underscore count
 */
size_t count_missing_letters(char **word_to_guess, void(on_each(char)));

/**
 * Returns the distance from 'a'
 * @param letter 'a' to 'z' (must be lower case)
 * @return 0 through 25
 */
size_t dst_from_a(int letter);

#endif //HANGMAN_UTILS_H