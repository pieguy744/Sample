CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: mathlib-test

mathlib-test: mathlib-test.o viete.o newton.o e.o madhava.o bbp.o euler.o
	$(CC) -o mathlib-test mathlib-test.o viete.o newton.o e.o madhava.o bbp.o euler.o -lm

mathlib-test.o: mathlib-test.c mathlib.h
	$(CC) $(CFLAGS) -c mathlib-test.c

e.o: e.c mathlib.h
	$(CC) $(CFLAGS) -c e.c

viete.o: viete.c mathlib.h
	$(CC) $(CFLAGS) -c viete.c

newton.o: newton.c mathlib.h
	$(CC) $(CFLAGS) -c newton.c

madhava.o: madhava.c mathlib.h
	$(CC) $(CFLAGS) -c madhava.c

bbp.o: bbp.c mathlib.h
	$(CC) $(CFLAGS) -c bbp.c

euler.o: euler.c mathlib.h
	$(CC) $(CFLAGS) -c euler.c

clean:
	rm -f mathlib-test *.o

format:
	clang-format -i -style=file *.c *.h
