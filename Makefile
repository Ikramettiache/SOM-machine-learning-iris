CC = gcc
CFLAGS = -W -Wall 
 

all: main.o init.o utils.o som.o
	$(CC) main.o init.o utils.o som.o -lm -o iris

utils.o : utils.h
	$(CC) $(CFLAGS) -c utils.c -o utils.o

main.o: utils.h
	$(CC)  $(CFLAGS) -c main.c -o main.o

init.o: utils.h
	$(CC)  $(CFLAGS) -c init.c -o init.o

som.o: utils.h
	$(CC)  $(CFLAGS) -c som.c -o som.o

clean:
	rm -rf *.o iris