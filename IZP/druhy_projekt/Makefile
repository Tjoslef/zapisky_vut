CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -g -O2

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(patsubst %.c, %, $(wildcard *.c))
