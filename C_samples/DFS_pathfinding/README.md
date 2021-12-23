# Assignment 4 - Perambulations of Denver Long

This C program uses a recursive depth-first search to find the shortest possible hamiltonian path through a list of locations.

## Linked Files

Include the files: path.h path.c graph.h graph.c stack.h stack.c tsp.c vertices.h

## Building

Build the program with:

```
clang -Wall -Wpedantic -Werror -Wextra -c tsp.c
clang -Wall -Wpedantic -Werror -Wextra -c graph.c
clang -Wall -Wpedantic -Werror -Wextra -c stack.c
clang -Wall -Wpedantic -Werror -Wextra -c path.c
clang -o tsp tsp.o graph.o stack.o path.o -lm

```

or with Makefile:

```
$ make all

```

## Running

Run the program with:

```
$ ./tsp [-u] [-v] [-h] [-i infile] [-o outfile]

```

Use `-h` to display help and usage

## Citations

All header files are provided by Professor Darrell Long from UCSC
