CC=gcc
CFLAGS = -Wall
LDFLAGS=

default: callback

callback: callback.o
	$(CC) $(LDFLAGS) callback.o -o callback
	
callback.o: callback.c
		$(CC) $(CFLAGS) -c callback.c -o callback.o
		
clean:
	rm -f *.o callback
