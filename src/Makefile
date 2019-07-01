CC = gcc
math=lm

all: rice_encode

rice_encode: rice_encode.o stats.o 
	$(CC) -o rice_encode rice_encode.o stats.o -$(math)

rice_encode.o stats.o: rice_encode.c stats.c
	$(CC) -c rice_encode.c stats.c
