#include "mathlib.h"

#include <stdlib.h>

static int n_count = 0;

//approximates the quare root of variable x
//based on python code written by Professor Long
double sqrt_newton(double x) {
    double z = 0.;
    double y = 1.;
    n_count = 0;
    while (absolute(z - y) > EPSILON) {
        z = y;
        y = 0.5 * (z + x / z);
        n_count++;
    }
    return y;
}

//returns count
int sqrt_newton_iters(void) {
    return n_count;
}
