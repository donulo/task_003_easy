CC=gcc
CFLAGS=-Wall -Werror -Wextra

all: clean ip_check mask_check ip_tools

ip_tools: ip_lib.o
	$(CC) $(CFLAGS) ip_tools.c  ip_lib.o -o ../bin/ip_tools

mask_check: ip_lib.o
	$(CC) $(CFLAGS) mask_check.c ip_lib.o -o mask_check

ip_check: ip_lib.o
	$(CC) $(CFLAGS) ip_check.c ip_lib.o -o ip_check

ip_lib.o: clean
	$(CC) $(CFLAGS) -c ip_lib.c -o ip_lib.o

clean:
	rm -rf *.o