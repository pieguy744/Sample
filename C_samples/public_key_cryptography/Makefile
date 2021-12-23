CC = clang
CFLAGS = -g -Wall -Wpedantic -Werror -Wextra $(shell pkg-config --cflags gmp)
LFLAGS = $(shell pkg-config --libs gmp)

all: encrypt decrypt keygen

keygen: keygen.o numtheory.o rsa.o randstate.o
	$(CC) -o keygen keygen.o numtheory.o rsa.o randstate.o  -lm $(LFLAGS)

decrypt: decrypt.o randstate.o rsa.o numtheory.o 
	$(CC) -o decrypt decrypt.o randstate.o rsa.o numtheory.o -lm $(LFLAGS)

encrypt: encrypt.o randstate.o rsa.o numtheory.o 
	$(CC) -o encrypt encrypt.o randstate.o rsa.o numtheory.o -lm $(LFLAGS)

keygen.o: keygen.c rsa.h randstate.h numtheory.h
	$(CC) $(CFLAGS) -c keygen.c

decrypt.o: decrypt.c rsa.h
	$(CC) $(CFLAGS) -c decrypt.c

encrypt.o: encrypt.c rsa.h
	$(CC) $(CFLAGS) -c encrypt.c

rsa.o: rsa.c rsa.h numtheory.h randstate.h
	$(CC) $(CFLAGS) -c rsa.c

numtheory.o: numtheory.c numtheory.h randstate.h
	$(CC) $(CFLAGS) -c numtheory.c

randstate.o: randstate.c randstate.h
	$(CC) $(CFLAGS) -c randstate.c


clean:
	rm -f keygen encrypt decrypt *.o

format:
	clang-format -i -style=file *.c *.h
