CFLAGS = -std=gnu11 -O2 -pedantic -Wall -Wextra -Werror -g
OBJ_DIR = obj
SRC_FILES = tail.c
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)
CC = gcc
EXECUTABLE = tail
all: $(EXECUTABLE)
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS)  -c $< -o $@
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
clean:
	rm -rf $(OBJ_DIR) $(EXECUTABLE)
