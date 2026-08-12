CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LIBS = -lm

SRC = src/Complexo.c src/main.c
EXEC = main.exe

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC) $(LIBS)

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC)
