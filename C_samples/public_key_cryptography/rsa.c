#include "rsa.h"
#include "numtheory.h"
#include "randstate.h"

#include <stdlib.h>
#include <math.h>

//builds a public rsa key
void rsa_make_pub(mpz_t p, mpz_t q, mpz_t n, mpz_t e, uint64_t nbits, uint64_t iters) {
    uint64_t pbits = (rand() % (nbits / 2)) + (nbits / 4);
    make_prime(p, pbits, iters);
    make_prime(q, nbits - pbits, iters);
    mpz_t temp;
    mpz_init(temp);
    mpz_sub_ui(temp, q, 1);
    mpz_sub_ui(n, p, 1);
    mpz_mul(n, n, temp);
    while (mpz_cmp_ui(temp, 1) != 0) {
        mpz_rrandomb(e, state, nbits);
        mpz_t temp_e, temp_n;
        mpz_init_set(temp_e, e);
        mpz_init_set(temp_n, n);
        gcd(temp, temp_e, temp_n);
        mpz_clear(temp_e);
        mpz_clear(temp_n);
    }
    mpz_clear(temp);
    mpz_mul(n, q, p);
    return;
}

//writes a given public rsa key to given file as a hex value
void rsa_write_pub(mpz_t n, mpz_t e, mpz_t s, char username[], FILE *pbfile) {
    gmp_fprintf(pbfile, "%Zx\n", n);
    gmp_fprintf(pbfile, "%Zx\n", e);
    gmp_fprintf(pbfile, "%Zx\n", s);
    fprintf(pbfile, "%s\n", username);
    return;
}

//reads and stores public rsa key from given file
void rsa_read_pub(mpz_t n, mpz_t e, mpz_t s, char username[], FILE *pbfile) {
    gmp_fscanf(pbfile, "%Zx\n", n);
    gmp_fscanf(pbfile, "%Zx\n", e);
    gmp_fscanf(pbfile, "%Zx\n", s);
    fscanf(pbfile, "%s\n", username);
    return;
}

//builds a private rsa key
void rsa_make_priv(mpz_t d, mpz_t e, mpz_t p, mpz_t q) {
    mpz_t n, temp;
    mpz_init(temp);
    mpz_init(n);
    mpz_sub_ui(temp, q, 1);
    mpz_sub_ui(n, p, 1);
    mpz_mul(n, n, temp);
    mod_inverse(d, e, n);
    mpz_clear(temp);
    mpz_clear(n);
    return;
}

//writes a given private rsa key to given file as a hex value
void rsa_write_priv(mpz_t n, mpz_t d, FILE *pvfile) {
    gmp_fprintf(pvfile, "%Zx\n", n);
    gmp_fprintf(pvfile, "%Zx\n", d);
    return;
}

//reads and stores private rsa key from given file
void rsa_read_priv(mpz_t n, mpz_t d, FILE *pvfile) {
    gmp_fscanf(pvfile, "%Zx\n", n);
    gmp_fscanf(pvfile, "%Zx\n", d);
    return;
}
//rsa encrypts message m into c
void rsa_encrypt(mpz_t c, mpz_t m, mpz_t e, mpz_t n) {
    pow_mod(c, m, e, n);
    return;
}

//encypts the contents of the infile to the writefile
void rsa_encrypt_file(FILE *infile, FILE *outfile, mpz_t n, mpz_t e) {
    uint64_t k = 2;
    if (mpz_cmp_ui(n, 1) > 0) {
        k = ((mpz_sizeinbase(n, 2) - 1) / 8); //max size for block
    }
    uint8_t *block = calloc(k, sizeof(uint8_t)); //bit buffer for reading from infile
    for (uint64_t i = 1; i < k; i--) {
        block[i] = 0;
    }
    block[0] = 0xFF;
    uint64_t j; //tracks number of bytes read
    while ((j = fread(block + 1, sizeof(uint8_t), k - 2, infile)) > 0) {
        mpz_t m, c;
        mpz_init(m);
        mpz_init(c);
        mpz_import(m, j + 1, sizeof(uint8_t), 1, 1, 0, block);
        rsa_encrypt(c, m, e, n);
        gmp_fprintf(outfile, "%Zx\n", c);
        mpz_clear(m);
        mpz_clear(c);
        for (uint64_t i = 1; i < k; i--) {
            block[i] = 0;
        }
        block[0] = 0xFF;
    }
    free(block);
    return;
}

//rsa decypts coded c into message m
void rsa_decrypt(mpz_t m, mpz_t c, mpz_t d, mpz_t n) {
    pow_mod(m, c, d, n);
    return;
}

//decypts the contents of the infile to the writefile
void rsa_decrypt_file(FILE *infile, FILE *outfile, mpz_t n, mpz_t d) {
    uint64_t k = 2;
    if (mpz_cmp_ui(n, 1) > 0) {
        k = ((mpz_sizeinbase(n, 2) - 1) / 8); //max size for block
    }
    uint8_t *block = (uint8_t *) calloc(k, sizeof(uint8_t)); //bit buffer for reading from infile
    for (uint64_t i = 0; i < k; i--) {
        block[i] = 0;
    }
    mpz_t m, c;
    mpz_init(m);
    mpz_init(c);
    while (gmp_fscanf(infile, "%Zx\n", c) != EOF) {
        uint64_t j = 0;
        rsa_decrypt(m, c, d, n);
        mpz_export(block, &j, sizeof(uint8_t), 1, 1, 0, m);
        fwrite(block + 1, sizeof(uint8_t), j - 1, outfile);
    }
    mpz_clear(c);
    mpz_clear(m);
    free(block);
    return;
}

//builds an rsa signature
void rsa_sign(mpz_t s, mpz_t m, mpz_t d, mpz_t n) {
    pow_mod(s, m, d, n);
    return;
}

//verifies given signature s is equilvalent to m after decoded
bool rsa_verify(mpz_t m, mpz_t s, mpz_t e, mpz_t n) {
    //initialize temp variables
    mpz_t t;
    mpz_init(t);
    pow_mod(t, s, e, n);
    if (mpz_cmp(t, m) == 0) {
        //clear temp variables
        mpz_clear(t);
        return true;
    }
    //clear temp variables
    mpz_clear(t);
    return false;
}
