#include "rng.h"
#include <stdlib.h>
#include <time.h>

void rng_init(void) {
    srand((unsigned int) time(NULL));
}

size_t rng_to(size_t max) {
    return (unsigned int) rand() / ((unsigned) RAND_MAX / max + 1u);
}
