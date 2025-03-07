CC = gcc
CFLAGS = -std=c11 -O2 -Wall -Wextra -Werror -D_GNU_SOURCE -D_DEFAULT_SOURCE
INLINE =
32BIT =

ifneq ($(findstring inline,$(MAKECMDGOALS)),)
    INLINE = -DUSE_INLINE
endif

eratosthenes_SOURCES = eratosthenes.c error.c
steg-decode_SOURCES = ppm.c steg-decode.c error.c

all: eratosthenes steg-decode

eratosthenes: $(eratosthenes_SOURCES:.c=.o)
	$(CC) $(CFLAGS) $(INLINE) $(32BIT) -o $@ $^

steg-decode: $(steg-decode_SOURCES:.c=.o)
	$(CC) $(CFLAGS) $(INLINE) $(32BIT) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

32bit: 32BIT = -m32
32bit: all

test_eratosthenes: eratosthenes
	./eratosthenes | factor > eratosthenes_factors.txt
	@echo "Eratosthenes test completed. Output in eratosthenes_factors.txt"

test_steg_decode: steg-decode
	./steg-decode du1-obrazek.ppm | factor > steg_decode_factors.txt
	@echo "Steg-decode test completed. Output in steg_decode_factors.txt"
clean:
	rm -f eratosthenes steg-decode *.o

.PHONY: all clean test 32bit
