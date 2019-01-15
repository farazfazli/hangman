/**
 *                      * Hangman in C *
 * O(1) runtime using pointers to 26 letters which each have a state
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
#include <time.h>
#include <stdlib.h>

/**
 * Enum instead of #define, from Practice of Programming
 */
enum {
    ALPHABET_SIZE = 26,
    WORD_LENGTH = 3,
    TOTAL_TRIES = 10,
};

static char *words[] = {"car", "dog", "cat", "bag"};

static size_t rand_to(size_t max);

static size_t from_a(int letter);

/**
 * Returns the distance from 'a'
 * @param letter 'a' to 'z'
 * @return 0 through 25
 */
static size_t from_a(int letter) {
    return (size_t) abs(letter - 'a');
}

static size_t rand_to(size_t max) {
    return (unsigned long) rand() / (RAND_MAX / max + 1);
}

void print_letters_state(char **word_to_guess, size_t word_len);

// Prints current word (for each index, either _ or letter)
void print_letters_state(char **word_to_guess, size_t word_len) {
    for (size_t i = 0; i < word_len; i++) {
        printf("%c ", *word_to_guess[i]);
    }
}

size_t count_underscores(char **word_to_guess, size_t word_len);

size_t count_underscores(char **word_to_guess, size_t word_len) {
    size_t num_underscores = 0;
    for (size_t i = 0; i < word_len; i++) {
        if (*word_to_guess[i] == '_') {
            num_underscores++;
        }
    }
    return num_underscores;
}

int main() {
    char letters[ALPHABET_SIZE];

    // Let's set 'letters' to be composed of just _
    // This will later be changed as the user guesses
    memset(letters, '_', ALPHABET_SIZE);

    // Seed rng with NULL (predictable but good enough for us)
    srand((unsigned int) time(NULL));

    size_t words_size = sizeof(words) / sizeof(words[0]);

    char *word = words[rand_to(words_size)];

    //char *word_to_guess[WORD_LENGTH]; // TODO: VLA?
    char *word_to_guess[WORD_LENGTH];

    size_t word_len = strlen(word); // doesn't count \0
    for (size_t i = 0; i < word_len; i++) {
        word_to_guess[i] = &letters[from_a(word[i])];
    }

    int tries = 0;
    size_t num_previous_underscores = word_len;
    int current_letter;

    print_letters_state(word_to_guess, word_len);
    fputs("\nPick a letter: ", stdout);

    // possibly replace getchar() with fgets and parse
    while ((current_letter = getchar()) != EOF) {
        if (!isalpha(current_letter)) {
            // Invalid input, simply continue
            continue;
        }

        // convert to lower case
        current_letter = tolower(current_letter);

        // distance from 'a'
        size_t letter_pos = from_a(current_letter);

        // letter has already been picked if it is in array
        if (letters[letter_pos] == current_letter) {
            puts("Please pick a different letter.");
            continue;
        } else {
            // Change underscore to the letter
            letters[letter_pos] = (char) current_letter;
        }

        print_letters_state(word_to_guess, word_len);
        puts("");

        // Finds if word still has underscores
        size_t num_underscores = count_underscores(word_to_guess, word_len);

        // if letter has no correct guesses yet
        if (num_underscores == num_previous_underscores) {
            tries++;
        }

        num_previous_underscores = num_underscores;

        // Win if no underscores left
        if (num_underscores == 0) {
            puts("YOU WIN!");
            break;
        }

        if (tries < TOTAL_TRIES) {
            printf("Tries Remaining: %d\n", TOTAL_TRIES - tries);
            fputs("Pick a letter: ", stdout);
        } else {
            puts("All tries over! Game Over!");
            break;
        }
    }
}
