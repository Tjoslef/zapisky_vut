CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -g -O0

%: %.c
	$(CC) $(CFLAGS) $< -static -o $@

clean:
	rm -f $(patsubst %.c, %, $(wildcard *.c))
