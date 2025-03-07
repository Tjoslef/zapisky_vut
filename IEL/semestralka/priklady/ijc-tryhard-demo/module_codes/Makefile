CC=gcc
CFLAGS=-std=c18 -Wall -Wextra -pedantic

all: moduleA moduleB moduleC moduleD moduleE

moduleA: moduleA*.c
	$(CC) $(CFLAGS) $^ -o $@

moduleB: moduleB*.c
	-$(CC) $(CFLAGS) $^ -o $@

moduleC: moduleC*.c
	$(CC) $(CFLAGS) $^ -o $@

moduleD: moduleD*.c
	-$(CC) $(CFLAGS) $^ -o $@

moduleE: moduleE*.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f moduleA moduleB moduleC moduleD moduleE

