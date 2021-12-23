#include "numtheory.h"
#include "randstate.h"

//passes the greatest commond divisor betwen a and b to variable d
//based on pseudocode given by Professor Long in documentaiton
void gcd(mpz_t d, mpz_t a, mpz_t b) {
    while (mpz_sgn(b) != 0) {
        mpz_set(d, b);
        mpz_mod(b, a, b);
        mpz_set(a, d);
    }
}

//computes the modular inverse of a mod n and passes it to variable i
//if there is no inverse, then pass 0 to i
//based on pseudocode given by Professor Long in documentaiton
void mod_inverse(mpz_t i, mpz_t a, mpz_t n) {
    //initialize variables
    mpz_t r, r_not, t, t_not;
    mpz_init_set(r, n);
    mpz_init_set(r_not, a);
    mpz_init(t);
    mpz_init_set_ui(t_not, 1);

    //main computation
    while (mpz_sgn(r_not) != 0) {
        mpz_t q, temp;
        mpz_init(q);
        mpz_init(temp);
        mpz_fdiv_q(q, r, r_not);
        mpz_set(temp, r);
        mpz_set(r, r_not);
        mpz_mul(r_not, q, r_not);
        mpz_sub(r_not, temp, r_not);
        mpz_set(temp, t);
        mpz_set(t, t_not);
        mpz_mul(t_not, q, t_not);
        mpz_sub(t_not, temp, t_not);
        mpz_clear(q);
        mpz_clear(temp);
    }
    if (mpz_cmp_ui(r, 1) > 0) {
        mpz_init_set_ui(i, 0); //no modular inverse found
        mpz_clear(r);
        mpz_clear(r_not);
        mpz_clear(t);
        mpz_clear(t_not);
        return;
    }
    if (mpz_sgn(t) < 0) {
        mpz_add(t, t, n);
    }
    mpz_set(i, t);
    mpz_clear(r);
    mpz_clear(r_not);
    mpz_clear(t);
    mpz_clear(t_not);
    return;
}

//computes modular eponentiation and passes the value to variable out
//based on pseudocode given by Professor Long in documentaiton
void pow_mod(mpz_t out, mpz_t base, mpz_t exponent, mpz_t modulus) {

    //initialize values
    mpz_t v, p, e;
    if (mpz_sgn(base) == 0) {
        mpz_set_ui(out, 0);
        return;
    }
    mpz_init_set_ui(v, 1);
    mpz_init_set(p, base);
    mpz_init_set(e, exponent);

    //main exponentiaiton
    while (mpz_sgn(e) > 0) {
        if (mpz_odd_p(e)) {
            mpz_mul(v, v, p);
            mpz_mod(v, v, modulus);
        }
        mpz_mul(p, p, p);
        mpz_mod(p, p, modulus);
        mpz_fdiv_q_ui(e, e, 2);
    }
    //set and clear values
    mpz_set(out, v);
    mpz_clear(v);
    mpz_clear(p);
    mpz_clear(e);
}

//implements a Miller-Rabin primality test
//based on pseudocode given by Professor Long in documentaiton
bool is_prime(mpz_t n, uint64_t iters) {
    if (mpz_cmp_ui(n, 2) == 0 || mpz_cmp_ui(n, 3) == 0) {
        return true;
    }
    if (mpz_even_p(n) || mpz_cmp_ui(n, 3) < 0) {
        return false;
    }
    mpz_t r, smod;
    uint64_t s = 1;
    mpz_init(smod);
    mpz_init(r);
    mpz_sub_ui(r, n, 1);
    mpz_fdiv_q_ui(r, r, 2);
    mpz_mod_ui(smod, r, 2);
    while (mpz_sgn(smod) == 0) {
        mpz_fdiv_q_ui(r, r, 2);
        mpz_mod_ui(smod, r, 2);
        s++;
    }
    mpz_clear(smod);
    for (uint64_t i = 0; i < iters; i++) {
        mpz_t a, b, y, temp;
        mpz_init(b);
        mpz_init(a);
        mpz_init(y);
        mpz_init(temp);
        mpz_sub_ui(b, n, 3);
        mpz_urandomm(a, state, b);
        mpz_add_ui(a, a, 2);
        pow_mod(y, a, r, n);
        mpz_sub_ui(temp, n, 1);
        if (mpz_cmp_ui(y, 1) != 0 && mpz_cmp(y, temp) != 0) {
            uint64_t j = 1;
            while (j <= s - 1 && mpz_cmp(y, temp) != 0) {
                mpz_t two;
                mpz_init_set_ui(two, 2);
                pow_mod(y, y, two, n);
                if (mpz_cmp_ui(y, 1) == 0) {
                    mpz_clear(y);
                    mpz_clear(r);
                    mpz_clear(b);
                    mpz_clear(temp);
                    mpz_clear(two);
                    mpz_clear(a);
                    return false;
                }
                j++;
                mpz_clear(two);
            }
            if (mpz_cmp(y, temp) != 0) {
                mpz_clear(y);
                mpz_clear(r);
                mpz_clear(temp);
                mpz_clear(a);
                mpz_clear(b);
                return false;
            }
        }
        mpz_clear(y);
        mpz_clear(temp);
        mpz_clear(a);
        mpz_clear(b);
    }
    mpz_clear(r);
    return true;
}

//generates a random prime number and passes it to p
void make_prime(mpz_t p, uint64_t bits, uint64_t iters) {
    mpz_rrandomb(p, state, bits);
    while (!is_prime(p, iters)) {
        mpz_rrandomb(p, state, bits);
    }
    return;
}
