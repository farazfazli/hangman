#include <stdio.h>
#include "utils.h"

size_t len(char **arr) {
    return sizeof(arr) / sizeof(arr[0]);
}

size_t print_count_underscores(char **word_to_guess, size_t word_len) {
    size_t num_underscores = 0;
    for (size_t i = 0; i < word_len; i++) {
        printf("%c ", *word_to_guess[i]);
        if (*word_to_guess[i] == '_') {
            num_underscores++;
        }
    }
    return num_underscores;
}

size_t from_a(int letter) {
    return (size_t) abs(letter - 'a');
}
