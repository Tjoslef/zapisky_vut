CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(patsubst %.c, %, $(wildcard *.c))
