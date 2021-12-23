#include "rsa.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define OPTIONS "hvn:i:o:"

int main(int argc, char **argv) {
    int opt = 0;
    bool h = false;
    bool v = false;
    char *public = "rsa.pub";
    char *input = NULL;
    char *output = NULL;

    FILE *f_in = stdin;
    FILE *f_out = stdout;
    FILE *pbfile;

    //parse user inputs
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'h': h = true; break;
        case 'v': v = true; break;
        case 'o': output = optarg; break;
        case 'i': input = optarg; break;
        case 'n':
        public
            = optarg;
            break;
        }
    }

    //help page
    if (h) {
        printf("SYNOPSIS\n   Encrypts data using RSA encryption.\n");
        printf("   Encrypted data is decrypted by the decrypt program.\n\n");
        printf("USAGE\n  %s [-hv] [-i infile] [-o outfile] -n pubkey\n\n", argv[0]);
        printf("OPTIONS\n  -h              display program help and usage.\n");
        printf("  -v              Display verbose program output.\n");
        printf("  -i infile       Input file of data to encrypt (default: stdin).\n");
        printf("  -o outfile      Output file for encrypted data (default: stdout).\n");
        printf("  -n pbfile       Public key file (default: rsa.pub).\n");
        return 0;
    }

    //open files
    pbfile = fopen(public, "r");
    if (f_in == NULL) {
        perror("Error opening file.");
        return 0;
    }
    if (input) {
        f_in = fopen(input, "r");
        if (f_in == NULL) {
            perror("Error opening file.");
            return 0;
        }
    }
    if (output) {
        f_out = fopen(output, "w");
        if (f_out == NULL) {
            perror("Error opening file.\n");
            return 0;
        }
    }

    //initialize values
    mpz_t n, e, s, sign;
    mpz_init(n);
    mpz_init(s);
    mpz_init(e);
    mpz_init(sign);
    //may need to free user later
    char user[32];

    //read in public key
    rsa_read_pub(n, e, s, user, pbfile);
    //convert the user variable to mpz_t
    mpz_set_str(sign, user, 62);
    //verbose printing
    if (v) {
        printf("user = %s\n", user);
        gmp_printf("s (%lu bits) = %Zd\n", mpz_sizeinbase(s, 2), s);
        gmp_printf("n (%lu bits) = %Zd\n", mpz_sizeinbase(n, 2), n);
        gmp_printf("e (%lu bits) = %Zd\n", mpz_sizeinbase(e, 2), e);
    }

    //verify if the username matches s
    if (!rsa_verify(sign, s, e, n)) {
        fprintf(stderr, "Could not verify username.");
        mpz_clear(n);
        mpz_clear(s);
        mpz_clear(e);
        mpz_clear(sign);
        fclose(f_out);
        fclose(f_in);
        fclose(pbfile);
        return 0;
    }

    //encrypt the file
    rsa_encrypt_file(f_in, f_out, n, e);

    //clear all variable from memory
    mpz_clear(n);
    mpz_clear(s);
    mpz_clear(e);
    mpz_clear(sign);
    fclose(f_out);
    fclose(f_in);
    fclose(pbfile);
    return 0;
}
