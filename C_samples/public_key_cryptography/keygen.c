#include "randstate.h"
#include "numtheory.h"
#include "rsa.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

#define OPTIONS "hvb:i:n:d:s:"

int main(int argc, char **argv) {
    int opt = 1;
    bool h = false;
    bool v = false;
    uint64_t bits = 256;
    uint64_t iters = 50;
    uint64_t seed = time(NULL);
    char *private = "rsa.priv";
    char *public = "rsa.pub";

    FILE *pbfile;
    FILE *pvfile;

    //parse user inputs
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'h': h = true; break;
        case 'v': v = true; break;
        case 'b': bits = atoi(optarg); break;
        case 'i': iters = atoi(optarg); break;
        case 'n':
        public
            = optarg;
            break;
        case 'd':
        private
            = optarg;
            break;
        case 's': seed = atoi(optarg); break;
        }
    }

    //help page
    if (h) {
        printf("SYNOPSIS\n   Encrypts data using RSA encryption.\n\n");
        printf("USAGE\n  %s [-hv] [-b bits] -n pbfile -d pvfile\n\n", argv[0]);
        printf("OPTIONS\n  -h              display program help and usage.\n");
        printf("  -v              Display verbose program output.\n");
        printf("  -b bits         Minimum bits needed for public key n (default: 256).\n");
        printf("  -i confidence   Miller-Rabin iterations for testing primes (default: 50).\n");
        printf("  -n pbfile       Public key file (default: rsa.pub).\n");
        printf("  -d pvfile       Private key file (default: rsa.priv).\n");
        printf("  -s seed         Random seed for testing.\n");
        return 0;
    }

    //open public and private files
    pvfile = fopen(private, "w");
    if (pvfile == NULL) {
        perror("Error opening file.");
        return 0;
    }
    pbfile = fopen(public, "w");
    if (pbfile == NULL) {
        perror("Error opening file.");
        return 0;
    }
    fchmod(fileno(pbfile), 0600);
    fchmod(fileno(pvfile), 0600);

    //initiate the random state
    randstate_init(seed);

    //get username from the enviroment may have to free later
    char *user = getenv("USER");
    mpz_t name, s, p, q, n, e, d;
    mpz_init(name);
    mpz_init(s);
    mpz_init(p);
    mpz_init(d);
    mpz_init(q);
    mpz_init(n);
    mpz_init(e);
    mpz_set_str(name, user, 62);

    rsa_make_pub(p, q, n, e, bits, iters);

    rsa_make_priv(d, e, p, q);
    rsa_sign(s, name, d, n);
    rsa_write_pub(n, e, s, user, pbfile);
    rsa_write_priv(n, d, pvfile);

    //verbose printing
    if (v) {
        printf("user = %s\n", user);
        gmp_printf("s (%lu bits) = %Zd\n", mpz_sizeinbase(s, 2), s);
        gmp_printf("p (%lu bits) = %Zd\n", mpz_sizeinbase(p, 2), p);
        gmp_printf("q (%lu bits) = %Zd\n", mpz_sizeinbase(q, 2), q);
        gmp_printf("n (%lu bits) = %Zd\n", mpz_sizeinbase(n, 2), n);
        gmp_printf("e (%lu bits) = %Zd\n", mpz_sizeinbase(e, 2), e);
        gmp_printf("d (%lu bits) = %Zd\n", mpz_sizeinbase(d, 2), d);
    }

    //clear values
    mpz_clear(name);
    mpz_clear(s);
    mpz_clear(p);
    mpz_clear(d);
    mpz_clear(q);
    mpz_clear(n);
    mpz_clear(e);
    randstate_clear();
    fclose(pbfile);
    fclose(pvfile);
    return 0;
}
