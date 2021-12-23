#include "rsa.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define OPTIONS "hvn:i:o:"

int main(int argc, char **argv) {
    int opt = 0;
    bool h = false;
    bool v = false;
    char *private = "rsa.priv";
    char *input = NULL;
    char *output = NULL;

    FILE *f_in = stdin;
    FILE *f_out = stdout;
    FILE *pvfile;

    //parse user inputs
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'h': h = true; break;
        case 'v': v = true; break;
        case 'i': input = optarg; break;
        case 'o': output = optarg; break;
        case 'n':
        private
            = optarg;
            break;
        }
    }

    //help page
    if (h) {
        printf("SYNOPSIS\n   Decrypts data using RSA decryption.\n");
        printf("   Encrypted data is encrypted by the encrypt program.\n\n");
        printf("USAGE\n  %s [-hv] [-i infile] [-o outfile] -n privkey\n\n", argv[0]);
        printf("OPTIONS\n  -h              display program help and usage.\n");
        printf("  -v              Display verbose program output.\n");
        printf("  -i infile       Input file of data to encrypt (default: stdin).\n");
        printf("  -o outfile      Output file for encrypted data (default: stdout).\n");
        printf("  -n pvfile       Private key file (default: rsa.priv).\n");
        return 0;
    }

    //open files
    pvfile = fopen(private, "r");
    if (f_in == NULL) {
        perror("Error opening file.\n");
        return 0;
    }
    if (input) {
        f_in = fopen(input, "r");
        if (f_in == NULL) {
            perror("Error opening file.\n");
            fclose(pvfile);
            return 0;
        }
    }
    if (output) {
        f_out = fopen(output, "w");
        if (f_out == NULL) {
            fclose(pvfile);
            fclose(f_in);
            perror("Error opening file.\n");
            return 0;
        }
    }

    //initialize values
    mpz_t n, d;
    mpz_init(n);
    mpz_init(d);

    //read in public key
    rsa_read_priv(n, d, pvfile);

    //verbose printing
    if (v) {
        gmp_printf("n (%lu bits) = %Zd\n", mpz_sizeinbase(n, 2), n);
        gmp_printf("d (%lu bits) = %Zd\n", mpz_sizeinbase(d, 2), d);
    }

    //encrypt the file
    rsa_decrypt_file(f_in, f_out, n, d);

    //clear all variable from memory
    mpz_clear(d);
    mpz_clear(n);
    fclose(f_out);
    fclose(f_in);
    fclose(pvfile);
}
