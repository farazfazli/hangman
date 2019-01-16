#include "rng.h"
#include <stdlib.h>

size_t rand_to(size_t max) {
    return (unsigned long) random() % max;
}
