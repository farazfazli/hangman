#include "rng.h"
#include <stdlib.h>
#include <time.h>

void init_rng(void) {
    srand((unsigned int) time(NULL));
}

size_t rand_to(size_t max) {
    return (unsigned long) random() % max;
}
