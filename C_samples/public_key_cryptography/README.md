# Assignment 6 - Public Key Cryptography

This C program uses a RSA encryption algorithm to encrypt and decrypt files as well as generate public/private key pairs.
## Linked Files

Include the files: numtheory.h numtheory.c randstate.h randstate.c rsa.h rsa.c keygen.c encrypt.c decrypt.c

## Building

Build the program with:

```
clang -g -Wall -Wpedantic -Werror -Wextra  -c encrypt.c
clang -g -Wall -Wpedantic -Werror -Wextra  -c randstate.c
clang -g -Wall -Wpedantic -Werror -Wextra  -c rsa.c
clang -g -Wall -Wpedantic -Werror -Wextra  -c numtheory.c
clang -o encrypt encrypt.o randstate.o rsa.o numtheory.o -lm -lgmp
clang -g -Wall -Wpedantic -Werror -Wextra  -c decrypt.c
clang -o decrypt decrypt.o randstate.o rsa.o numtheory.o -lm -lgmp
clang -g -Wall -Wpedantic -Werror -Wextra  -c keygen.c
clang -o keygen keygen.o numtheory.o rsa.o randstate.o  -lm -lgmp


```

or with Makefile:

```
$ make all

```

## Running

Run the program with:

```
$ ./keygen [-hv] [-b bits] -n pbfile -d pvfile

$ ./encrypt [-hv] [-i infile] [-o outfile] -n pubkey

$ ./decrypt [-hv] [-i infile] [-o outfile] -n privkey

```


Use `-h` to display help and usage

## Citations

All header files are provided by Professor Darrell Long from UCSC
