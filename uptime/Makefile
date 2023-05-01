CC = $(CROSS_COMPILE)gcc
LIB_NAME = uptime
LIB_PATH = ../libs/
INC_PATH = ../include
OBJ = -o 
CFLAGS = -Wall -c

.PHONY: all install clean

all: uptime.so

uptime.so: uptime.o 
	$(CC) -shared uptime.o $(OBJ) $(LIB_PATH)uptime.so

uptime.o: uptime.c
	$(CC) $(CFLAGS) -I $(INC_PATH) -fPIC uptime.c $(OBJ) uptime.o

clean: 
	rm -f *.o $(LIB_PATH)*.so