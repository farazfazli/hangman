/**
 *                      * Hangman in C *
 * O(1) lookup using pointers to 26 letters which each have a state
 * A letter is either _ (not picked, default), or the letter itself
 * I was inspired by seeing many other Hangman implementations which
 * relied on a multiple layers of iteration, this aims to be 'simple'
 * and 'idiomatic', by using a different approach.
 *
 * @date 1/11/19
 * @author Faraz Fazli
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "rng.h"
#include "utils.h"

/**
 * Use enum to replace "magic numbers" instead of #define or const
 * Ref: Practice of Programming, p.21
 */
enum {
    ALPHABET_SIZE = 26,
    TOTAL_TRIES = 10,
};

// Words the program chooses from
static char *words[] = {"racing", "magic", "bow", "racecar"};

int main() {
    init_rng();
    char letters[ALPHABET_SIZE];

    // Let's set 'letters' to be composed of just _
    // This will later be changed as the user guesses
    memset(letters, '_', ALPHABET_SIZE);

    // Total number of elements in our array
    size_t total_elems = sizeof(words)/sizeof(words[0]);

    char *word = words[rand_to(total_elems)];
    size_t word_size = strlen(word) + 1; // includes NUL character

    // Here I used 'malloc' instead of VLA
    char **word_to_guess = malloc(word_size * sizeof(*word_to_guess));
    size_t word_len = strlen(word); // excludes NUL

    // point each element to the appropriate letter in our array
    for (size_t i = 0; i < word_len; i++) {
        word_to_guess[i] = &letters[from_a(word[i])];
    }

    int tries = 0;
    size_t num_previous_underscores = word_len;

    print_count_underscores(word_to_guess);
    fputs("\nPick a letter: ", stdout);

    // Could replace getchar() with fgets and parse each letter
    // which may serve better in the future
    int current_letter;
    while ((current_letter = getchar()) != EOF) {
        if (!isalpha(current_letter)) {
            // Simply continue - printing here causes bugs
            continue;
        }

        // convert to lower case
        current_letter = tolower(current_letter);

        // distance from 'a'
        size_t letter_pos = from_a(current_letter);

        // Letter has already been picked if it is in array
        if (letters[letter_pos] == current_letter) {
            puts("Please pick a different letter.");
            continue;
        } else {
            // Change underscore to the letter
            letters[letter_pos] = (char) current_letter;
        }

        // Finds if word still has underscores, and print word state
        size_t num_underscores = print_count_underscores(word_to_guess);

        // If letter has no correct guesses from this turn, increment tries
        if (num_underscores == num_previous_underscores) {
            tries++;
        }
        num_previous_underscores = num_underscores;

        // Win if no underscores left
        if (num_underscores == 0) {
            puts("-> YOU WIN!");
            break;
        }

        if (tries < TOTAL_TRIES) {
            printf("\nTries Remaining: %d\n", TOTAL_TRIES - tries);
            fputs("Pick a letter: ", stdout);
        } else {
            puts("No tries left! Game Over!");
            break;
        }
    }
    free(word_to_guess);
}
