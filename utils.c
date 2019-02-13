#include <stdio.h>
#include <stdlib.h>
#include "config.h"

/* Compiler will optimize "puts" calls for ascii art,
 * left as-is for more readability */
void print_hangman(int tries_left) {
    if (tries_left > 7) {
        return;
    }
    switch (tries_left) {
        case 7:
            puts("┏━━━╤━");
            puts("┃┃    ");
            puts("┃┃");
            puts("┃┃");
            puts("┃┃");
            puts("┻┻━━━━━━━");
            break;
        case 6:
            puts("┏━━━╤━");
            puts("┃┃  O ");
            puts("┃┃");
            puts("┃┃");
            puts("┃┃");
            puts("┻┻━━━━━━━");
            break;
        case 5:
            puts("┏━━━╤━");
            puts("┃┃  O ");
            puts("┃┃  | ");
            puts("┃┃    ");
            puts("┃┃    ");
            puts("┻┻━━━━━━━");
            break;
        case 4:
            puts("┏━━━╤━");
            puts("┃┃  O ");
            puts("┃┃ ╲| ");
            puts("┃┃    ");
            puts("┃┃    ");
            puts("┻┻━━━━━━━");
            break;
        case 3:
            puts("┏━━━╤━");
            puts("┃┃  O ");
            puts("┃┃ ╲|╱");
            puts("┃┃    ");
            puts("┃┃    ");
            puts("┻┻━━━━━━━");
            break;
        case 2:
            puts("┏━━━╤━");
            puts("┃┃  O ");
            puts("┃┃ ╲|╱");
            puts("┃┃  | ");
            puts("┃┃    ");
            puts("┻┻━━━━━━━");
            break;
        case 1:
            puts("┏━━━╤━");
            puts("┃┃  O ");
            puts("┃┃ ╲|╱");
            puts("┃┃  | ");
            puts("┃┃ ╱  ");
            puts("┻┻━━━━━━━");
            break;
        case 0:
            puts("┏━━━╤━");
            puts("┃┃  O ");
            puts("┃┃ ╲|╱");
            puts("┃┃  | ");
            puts("┃┃ ╱ ╲");
            puts("┻┻━━━━━━━");
            break;
    }
}

void print_char(char char_to_print) {
    putchar(char_to_print);
    putchar(' ');
}

size_t count_missing_letters(char **word_to_guess, const void(on_each(char))) {
    size_t num_missing = 0;
    while (*word_to_guess) {
        if (on_each != NULL) {
            on_each(**word_to_guess);
        }
        if (**word_to_guess++ == HIDDEN_LETTER) {
            num_missing++;
        }
    }
    return num_missing;
}

size_t dst_from_a(int letter) {
    return (size_t) abs(letter - 'a');
}
