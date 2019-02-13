#include "dictionary.h"

// Adapted from https://codereview.stackexchange.com/a/211768/78786
const char* get_random_word() {
    rng_init();
    static const char *words[] = {"racing", "magic", "bow", "racecar"};
    static const size_t word_count = sizeof(words)/sizeof(words[0]);
    return words[rng_to(word_count)];
}
