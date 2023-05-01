CC = $(CROSS_COMPILE)gcc
LIB_NAME = uname
LIB_PATH = ../libs/
INC_PATH = ../include
OBJ = -o 
CFLAGS = -Wall -c

.PHONY: all install clean

all: uname.so

uname.so: uname.o 
	$(CC) -shared uname.o $(OBJ) $(LIB_PATH)uname.so

uname.o: uname.c
	$(CC) $(CFLAGS) -I $(INC_PATH) -fPIC uname.c $(OBJ) uname.o

clean: 
	rm -f *.o $(LIB_PATH)*.so