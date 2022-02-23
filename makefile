CFLAGS := -Wall -Wextra -O0 -g0

SRC_DIR := src
BIN_DIR := exe

all: main

main: main.o schedule.o	
	gcc *.o $(CFLAGS) -o scheduler.exe

main.o:
	gcc -c $(SRC_DIR)/main.c

schedule:
	gcc -c $(SRC_DIR)/schedule.c

clean:
	del *.o
	cls
