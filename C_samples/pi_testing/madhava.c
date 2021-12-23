#include "mathlib.h"

#include <stdlib.h>

//counts number of terms used to approximate pi
static int m_count;

//appoximates pi using madhava formula
double pi_madhava(void) {
    double pi = 1;
    for (double k = 1, term = 1, exp = 1; absolute(term) > EPSILON; k++) {
        exp /= -3;
        term = exp / ((2 * k) + 1);
        pi += term;
        m_count = k;
    }
    pi *= sqrt_newton(12);
    return pi;
}

//returns counter
int pi_madhava_terms(void) {
    return m_count;
}
