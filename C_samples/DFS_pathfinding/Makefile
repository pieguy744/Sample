CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: tsp


tsp: tsp.o graph.o stack.o path.o
	$(CC) -o tsp tsp.o graph.o stack.o path.o -lm

tsp.o: tsp.c graph.h stack.h path.h vertices.h
	$(CC) $(CFLAGS) -c tsp.c

graph.o: graph.c graph.h vertices.h
	$(CC) $(CFLAGS) -c graph.c

stack.o: stack.c stack.h vertices.h
	$(CC) $(CFLAGS) -c stack.c

path.o: path.c path.h stack.h vertices.h
	$(CC) $(CFLAGS) -c path.c


clean:
	rm -f tsp *.o *.exe

format:
	clang-format -i -style=file *.c *.h
