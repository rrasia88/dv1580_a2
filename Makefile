CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/memory_manager.c src/linked_list.c src/main.c
OBJ = $(SRC:.c=.o)
TARGET = linked_list_app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f src/*.o $(TARGET)
