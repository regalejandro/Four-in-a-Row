CC= gcc
CFLAGS= -g -Wall -std=gnu99
LIBS = 

OBJS = connect4.o settings.o

all: connect4

connect4: connect4.c $(OBJS) 
	$(CC) $(CFLAGS) -o connect4 $(OBJS) $(LIBS)

connect4.o: connect4.c connect4.h settings.h
	$(CC) $(CFLAGS) -c connect4.c

settings.o: settings.c settings.h
	$(CC) $(CFLAGS) -c settings.c

cleano:
	rm -f *.o

clean:
	rm -f connect4 *.o