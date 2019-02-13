/**
 *                      * Hangman in C *
 * O(1) lookup using pointers to 26 letters which each have a
 * state. A letter is either empty, or the letter itself.
 * I was inspired by seeing many other Hangman implementations which
 * relied on a multiple layers of iteration, this aims to be 'simple'
 * and 'idiomatic', by using a different approach.
 *
 * @version 2.0
 * @date 1/18/19
 * @author Faraz Fazli
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "rng.h"
#include "utils.h"
#include "config.h"
#include "dictionary.h"

//Returns length of an array
#define len(x) (((sizeof(x)))/(sizeof((x)[0])))

int main() {
    char letters[ALPHABET_SIZE];
    int tries = 0;
    memset(letters, HIDDEN_LETTER, ALPHABET_SIZE);

    const char *word = get_random_word();
    size_t word_len = strlen(word); // excludes NUL
    size_t word_size = word_len + 1; // includes NUL

    char **word_to_guess = malloc(word_size * sizeof(*word_to_guess));

    // Link letters in word to 'letters' array
    for (size_t i = 0; i < word_len; i++) {
        word_to_guess[i] = &letters[dst_from_a(word[i])];
    }

    size_t num_prev_missing = word_len;
    count_missing_letters(word_to_guess, print_char);
    fputs("\nPick a letter: ", stdout);

    int chosen_letter;
    while ((chosen_letter = getchar()) != EOF) {
        // Consume '\n' from puts/printf/etc.
        if (isspace(chosen_letter)) {
            continue;
        }

        if (!isalpha(chosen_letter)) {
            puts("Please enter a valid letter.");
            continue;
        }

        chosen_letter = tolower(chosen_letter);
        size_t letter_pos = dst_from_a(chosen_letter);
        if (letters[letter_pos] != (char) HIDDEN_LETTER) {
            puts("Please pick a different letter");
            continue;
        }

        letters[letter_pos] = (char) chosen_letter;

        size_t num_missing = count_missing_letters(word_to_guess, print_char);
        if (num_missing == num_prev_missing) {
            tries++;
        }
        num_prev_missing = num_missing;

        if (num_missing == 0) {
            puts("-> YOU WIN!");
            break;
        }

        puts("");
        int tries_left = TOTAL_TRIES - tries;
        print_hangman(tries_left);
        if (tries_left > 0) {
            printf("\nTries Remaining: %d\n", tries_left);
            fputs("Pick a letter: ", stdout);
        } else {
            puts("No tries left! Game Over!");
            break;
        }
    }
    free(word_to_guess);
}
