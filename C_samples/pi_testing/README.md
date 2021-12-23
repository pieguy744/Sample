# Assignment 2 - A Little Slice of Pi

This C program tests various approximations of e, pi and a square root function against
the math.h C library.

## Linked Files

Include the file: mathlib.h euler.c e.c madhava.c newton.c bbp.c viete.c

## Building

Build the program with:

```
$ clang -Wall -Wextra -Werror -Wpedantic -o euler.c euler.c
$ clang -Wall -Wextra -Werror -Wpedantic -o e e.c
$ clang -Wall -Wextra -Werror -Wpedantic -o madhava madhava.c
$ clang -Wall -Wextra -Werror -Wpedantic -o newton newton.c
$ clang -Wall -Wextra -Werror -Wpedantic -o bbp bbp.c
$ clang -Wall -Wextra -Werror -Wpedantic -o viete viete.c
$ clang -Wall -Wextra -Werror -Wpedantic -o mathlib-test mathlib-test.c
$ clang -o mathlib-test mathlib-test.o euler.o e.o madhava.o newton.o bbp.o viete.o

```

or with Makefile:

```
$ make all

```

## Running

Run the program with:

```
$ ./mathlib-test [-aebmrvnsh]

```


Use `-h` to display help and usage

## Citations

All header files are provided by Professor Darrell Long from UCSC
