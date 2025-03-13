CC = gcc
CFLAGS = -std=c11 -O2 -pedantic -Wall -Wextra -Werror -g
INLINE = -DUSE_INLINE
32BIT =
eratosthenes_SOURCES = prime.c eratosthenes.c error.c
steg-decode_SOURCES = ppm.c steg-decode.c error.c eratosthenes.c

all: prime-i prime steg-decode

prime-i: $(eratosthenes_SOURCES:.c=-i.o)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INLINE) $(32BIT) -o $@ $^

prime: $(eratosthenes_SOURCES:.c=.o)
	$(CC) $(CFLAGS) $(LDFLAGS) $(32BIT) -o $@ $^

steg-decode: $(steg-decode_SOURCES:.c=.o)
	$(CC) $(CFLAGS) $(LDFLAGS) $(32BIT)  -o $@ $^

%-i.o: %.c
	$(CC) $(CFLAGS) $(INLINE) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

32bit: 32BIT = -m32
32bit: all

test_eratosthenes: prime
	./prime | factor > eratosthenes_factors.txt
	@echo "Eratosthenes test completed. Output in eratosthenes_factors.txt"

.PHONY: test_steg-decode
test_steg-decode: steg-decode steg_decode_factors_results.txt
	@echo "Steg-decode test chain executed. Final output in steg_decode_factors_results.txt"

steg_decode_factors.txt:
	./steg-decode du1-obrazek.ppm > steg_decode_factors.txt

factorize: steg_decode_factors.txt
	parallel -L 1 factor < steg_decode_factors.txt > steg_decode_factors_results.txt
	@echo "Steg-decode factorization completed. Output in steg_decode_factors_results.txt"

steg_decode_factors_results.txt: factorize

clean:
	rm -f prime-i prime steg-decode *.o steg_decode_factors.txt steg_decode_factors_results.txt

.PHONY: all clean test_steg-decode 32bit
