#include "mathlib.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define OPTIONS "aebmrvnsh"

int main(int argc, char **argv) {
    int opt = 0;
    bool e_in = false;
    bool b = false;
    bool m = false;
    bool r = false;
    bool v = false;
    bool n = false;
    bool s = false;
    bool h = false;

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a': e_in = b = m = r = v = n = true; break;
        case 'e': e_in = true; break;
        case 'b': b = true; break;
        case 'm': m = true; break;
        case 'r': r = true; break;
        case 'v': v = true; break;
        case 'n': n = true; break;
        case 's': s = true; break;
        case 'h': h = true; break;
        }
    }
    if (e_in) {
        double my_e = e();
        double diff = absolute(my_e - M_E);
        printf("e() = %16.15lf, M_E = %16.15lf, diff = %16.15lf \n", my_e, M_E, diff);
        if (s) {
            printf("e() terms = %d\n", e_terms());
        }
    }
    if (b) {
        double pi = pi_bbp();
        double diff = absolute(pi - M_PI);
        printf("pi_bbp() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf \n", pi, M_PI, diff);
        if (s) {
            printf("pi_bbp() terms = %d\n", pi_bbp_terms());
        }
    }
    if (m) {
        double pi = pi_madhava();
        double diff = absolute(pi - M_PI);
        printf("pi_madhava() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf \n", pi, M_PI, diff);
        if (s) {
            printf("pi_madhava() terms = %d\n", pi_madhava_terms());
        }
    }
    if (r) {
        double pi = pi_euler();
        double diff = absolute(pi - M_PI);
        printf("pi_euler() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf \n", pi, M_PI, diff);
        if (s) {
            printf("pi_euler() terms = %d\n", pi_euler_terms());
        }
    }
    if (v) {
        double pi = pi_viete();
        double diff = absolute(pi - M_PI);
        printf("pi_viete() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf \n", pi, M_PI, diff);
        if (s) {
            printf("pi_viete() terms = %d\n", pi_viete_factors());
        }
    }
    if (n) {
        for (double i = 0; i < 10; i += 0.1) {
            double m_sqrt = sqrt(i);
            double my_sqrt = sqrt_newton(i);
            double diff = absolute(my_sqrt - m_sqrt);
            printf("sqrt_newton(%f) = %16.15lf, sqrt(%f) = %16.15lf, diff = %16.15lf \n", i,
                my_sqrt, i, m_sqrt, diff);
            if (s) {
                printf("sqrt_newton() terms = %d\n", sqrt_newton_iters());
            }
        }
    }
    if (h) {
        printf("SYNOPSIS\n   A test harness for the small numerical library.\n\n");
        printf("USAGE\n   %s [-aebmrvnsh]\n\n", argv[0]);
        printf("OPTIONS\n  -a   Runs all tests.\n  -e   Runs e test.\n  -b   Runs BBP pi test.\n");
        printf("  -m   Runs Madhava pi test.\n  -r   Runs Euler pi test.\n");
        printf("  -v   Runs Viete pi test.\n  -n   Runs Newton square root tests.\n");
        printf("  -s   Print verbose statistics.\n  -h   Display program synopsis and usage.\n");
    }
    return 0;
}
