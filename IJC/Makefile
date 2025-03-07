CC = gcc
CFLAGS = -std=c11 -O2 -Wall -Wextra -Werror -D_GNU_SOURCE -D_DEFAULT_SOURCE
INLINE =
32BIT =

ifeq ($(findstring -i,$(MAKECMDGOALS)),-i)
    INLINE = -DUSE_INLINE
endif

# Find all .c files in the current directory based on arguments
ifeq ($(MAKECMDGOALS),eratosthenes)
    SOURCES := eratosthenes.c error.c
    TARGET := eratosthenes
endif

ifeq ($(MAKECMDGOALS),steg-decode)
    SOURCES := ppm.c steg-decode.c error.c
    TARGET := steg-decode
endif

OBJECTS := $(SOURCES:.c=.o)
OUTPUT_FILE = primes_factors.txt

# Default target: build the program
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(INLINE) $(32BIT) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

32bit: 32BIT = -m32
32bit: all

test: $(TARGET)
	./$(TARGET) | factor > $(OUTPUT_FILE)
	@echo "Test completed. Output in $(OUTPUT_FILE)"

# Clean rule
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean test 32bit
