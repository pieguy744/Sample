#include "mathlib.h"

#include <stdlib.h>

//Counts the number of terms used to approximate pi
static int el_count = 0;

//calculates pi using Euler fomula
double pi_euler(void) {
    double pi = 0.;
    for (double k = 1, term = 1.; term > EPSILON; k++) {
        term = 1 / (k * k);
        pi += term;
        el_count = k;
    }
    pi = sqrt_newton(pi * 6);
    return pi;
}

//returns counter
int pi_euler_terms(void) {
    return el_count;
}
