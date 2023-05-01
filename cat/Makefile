CC = $(CROSS_COMPILE)gcc
LIB_NAME = cat
LIB_PATH = ../libs/
INC_PATH = ../include
OBJ = -o 
CFLAGS = -Wall -c

.PHONY: all install clean

all: cat.so

cat.so: cat.o 
	$(CC) -shared cat.o $(OBJ) $(LIB_PATH)cat.so

cat.o: cat.c
	$(CC) $(CFLAGS) -I $(INC_PATH) -fPIC cat.c $(OBJ) cat.o

clean: 
	rm -f *.o $(LIB_PATH)*.so