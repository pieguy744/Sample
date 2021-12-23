CC = clang
CFLAGS = -g -Wall -Wpedantic -Werror -Wextra

all: banhammer

banhammer: banhammer.o ht.o bst.o bv.o bf.o node.o parser.o speck.o
	$(CC) -o banhammer banhammer.o ht.o bst.o bv.o bf.o node.o parser.o speck.o -lm

banhammer.o: banhammer.c ht.h bst.h node.h bf.c bf.h bv.h salts.h messages.h parser.h 
	$(CC) $(CFLAGS) -c banhammer.c

ht.o: ht.c ht.h bst.h node.h salts.h speck.h
	$(CC) $(CFLAGS) -c ht.c

bst.o: bst.c bst.h node.h
	$(CC) $(CFLAGS) -c bst.c

bv.o: bv.c bv.h
	$(CC) $(CFLAGS) -c bv.c

bf.o: bf.c bf.h bv.h salts.h speck.h
	$(CC) $(CFLAGS) -c bf.c

node.o: node.c node.h
	$(CC) $(CFLAGS) -c node.c

parser.o: parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c

speck.o: speck.c speck.h
	$(CC) $(CFLAGS) -c speck.c


clean:
	rm -f banhammer *.o

format:
	clang-format -i -style=file *.c *.h
