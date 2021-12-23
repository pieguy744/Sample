#include "mathlib.h"

#include <stdlib.h>

//tracks number of terms used to appoximate pi
static int b_count = 0;

//approximate pi using the BBP formula
double pi_bbp(void) {
    double pi = 0.;
    for (double k = 0, term = 1, exp = 16; absolute(term) > EPSILON; k++) {
        exp = exp / 16;
        term
            = exp * ((4 / (8 * k + 1)) - (2 / (8 * k + 4)) - (1 / (8 * k + 5)) - (1 / (8 * k + 6)));
        pi += term;
        b_count = k;
    }
    return pi;
}

//returns count
int pi_bbp_terms(void) {
    return b_count;
}
