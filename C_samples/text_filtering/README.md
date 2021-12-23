# Assignment 7 - The Great Firewall of Santa Cruz

This C program uses a Bloomfilter and Hashtable to find unnaceptable language used in the Glorious People’s Republic of Santa Cruz.

## Linked Files

Include the files: banhammer.c, messages.h, salts.h, speck.h, speck.c,
ht.h, ht.c, bst.h, bst.c, node.h, node.c, bf.h, bf.c, bv.h, bv.c, parser.h, parser.c

## Building

Build the program with:

```
clang -g -Wall -Wpedantic -Werror -Wextra -c banhammer.c
clang -g -Wall -Wpedantic -Werror -Wextra -c ht.c
clang -g -Wall -Wpedantic -Werror -Wextra -c bst.c
clang -g -Wall -Wpedantic -Werror -Wextra -c bv.c
clang -g -Wall -Wpedantic -Werror -Wextra -c bf.c
clang -g -Wall -Wpedantic -Werror -Wextra -c node.c
clang -g -Wall -Wpedantic -Werror -Wextra -c parser.c
clang -g -Wall -Wpedantic -Werror -Wextra -c speck.c
clang -o banhammer banhammer.o ht.o bst.o bv.o bf.o node.o parser.o speck.o -lm

```

or with Makefile:

```
$ make all

```

## Running

Run the program with:

```
$ ./banhammer [-hs] [-t size] [-f size]

```


Use `-h` to display help and usage

## Citations

All header files and speck.c are provided by Professor Darrell Long from UCSC
