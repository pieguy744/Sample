#include "mathlib.h"

#include <stdlib.h>

//counts number of factors used to approximate pi
static int v_count = 0;

//approximates pi using viete formula
double pi_viete(void) {
    double pi = 1;
    for (double k = 1, term = 0; 1 - term > EPSILON; k++) {
        if (k == 1) {
            term = sqrt_newton(2) / 2;
        } else {
            term = sqrt_newton((term * 2) + 2) / 2;
        }
        pi *= term;
        v_count = k;
    }
    pi = 2 / pi;
    return pi;
}

//returns counter
int pi_viete_factors(void) {
    return v_count;
}
