#include "mathlib.h"

#include <stdlib.h>

//counts number of terms used to approximate e
static int e_count = 0;

//approximates e using a taylor series
double e(void) {
    double e = 1.;
    for (double k = 1, term = 1.; term > EPSILON; k++) {
        term = term / k;
        e += term;
        e_count = k;
    }
    return e;
}

//returns count
int e_terms(void) {
    return e_count;
}
