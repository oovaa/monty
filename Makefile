CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = monty

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ) $(TARGET)
