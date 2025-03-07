CC=gcc
CFLAGS=-std=c18 -Wall -Wextra -pedantic

SRCS := $(wildcard *.c)
EXECS := $(SRCS:.c=)

all: $(EXECS)

%: %.c
	-$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f $(EXECS)
