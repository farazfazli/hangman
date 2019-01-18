#ifndef HANGMAN_CONFIG_H
#define HANGMAN_CONFIG_H
/**
 * Use enum to replace "magic numbers" instead of #define or const
 * Ref: Practice of Programming, p.21
 */
enum {
    ALPHABET_SIZE = 26,
    TOTAL_TRIES = 10,
    HIDDEN_LETTER = '_',
};

static char *words[] = {"racing", "magic", "bow", "racecar"};

#endif //HANGMAN_CONFIG_H
