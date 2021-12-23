# Assignment 3 - Sorting

This C program implements sorting algortithms of varying complexities to measure the
efficiency of each algorithm.

## Linked Files

Include the files: sorting.c stats.c set.c heap.c insert.c shell.c quick.c
stats.h set.h heap.h insert.h shell.h quick.h
## Building

Build the program with:

```

clang -Wall -Wpedantic -Werror -Wextra -c sorting.c
clang -Wall -Wpedantic -Werror -Wextra -c heap.c
clang -Wall -Wpedantic -Werror -Wextra -c insert.c
clang -Wall -Wpedantic -Werror -Wextra -c shell.c
clang -Wall -Wpedantic -Werror -Wextra -c quick.c
clang -Wall -Wpedantic -Werror -Wextra -c stats.c
clang -o sorting sorting.o heap.o insert.o shell.o quick.o stats.o -lm


```

or with Makefile:

```

$ make all

```

## Running

Run the program with:

```

./sorting [-haeisqn:p:r:] [-n length] [-p elements] [-r seed]

```

Use `-h` to display help and usage


## Citations

All header files are provided by Professor Darrell Long from UCSC
