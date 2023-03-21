CC=gcc
STD= -std=gnu99
BIN=game.bin
OBJ=direction.o main.o tools.o game2048.o
FLAG= -Wall -Werror -DDEBUG

all: $(OBJ)
	$(CC) -o $(BIN) $(OBJ) && ./game.bin
main.o: main.c game2048.h
	$(CC) $(STD) $(FLAG) -c main.c
game2048.o: game2048.c game2048.h tools.h direction.h
	$(CC) $(STD) $(FLAG) -c game2048.c
tools.o: tools.c game2048.h tools.h 
	$(CC) $(STD) $(FLAG) -c tools.c
direction.o: direction.c game2048.h direction.h tools.h
	$(CC) $(STD) $(FLAG) -c direction.c
	
clean:
	rm -rf $(BIN) $(OBJ)
