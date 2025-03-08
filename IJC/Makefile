CC = gcc
CFLAGS = -std=c11 -O2 -pedantic -Wall -Wextra -Werror -g
#LDFLAGS = -fsanitize=address
INLINE =
32BIT =

ifneq ($(findstring inline,$(MAKECMDGOALS)),)
    INLINE = -DUSE_INLINE
endif

eratosthenes_SOURCES = eratosthenes.c error.c
steg-decode_SOURCES = ppm.c steg-decode.c error.c

all: eratosthenes steg-decode

eratosthenes: $(eratosthenes_SOURCES:.c=.o)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INLINE) $(32BIT) -o $@ $^

steg-decode: $(steg-decode_SOURCES:.c=.o)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INLINE) $(32BIT) -DERATOSTHENES_LIBRARY -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

32bit: 32BIT = -m32
32bit: all

test_eratosthenes: eratosthenes
	./eratosthenes | factor > eratosthenes_factors.txt
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
	rm -f eratosthenes steg-decode *.o steg_decode_factors.txt steg_decode_factors_results.txt

.PHONY: all clean test_steg-decode 32bit
