CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: sorting


sorting: sorting.o heap.o insert.o shell.o quick.o stats.o
	$(CC) -o sorting sorting.o heap.o insert.o shell.o quick.o stats.o -lm

sorting.o: sorting.c stats.h set.h heap.h insert.h shell.h quick.h
	$(CC) $(CFLAGS) -c sorting.c

heap.o: heap.c heap.h stats.h
	$(CC) $(CFLAGS) -c heap.c

insert.o: insert.c insert.h stats.h
	$(CC) $(CFLAGS) -c insert.c

shell.o: shell.c shell.h stats.h
	$(CC) $(CFLAGS) -c shell.c

quick.o: quick.c quick.h stats.h
	$(CC) $(CFLAGS) -c quick.c

stats.o: stats.c stats.h
	$(CC) $(CFLAGS) -c stats.c


clean:
	rm -f sorting *.o *.exe

format:
	clang-format -i -style=file *.c *.h
