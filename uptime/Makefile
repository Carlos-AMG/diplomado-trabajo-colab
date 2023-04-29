#CROSS_COMPILE = arm-linux-gnueabi-
#CROSS_COMPILE =
CC = gcc
CFLAGS = -Wall
LIB = ./
INCLUDE := -I ../include

all: uptime.so

uptime.so: uptime.o
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -shared -o ./uptime.so uptime.o

uptime.o: $(LIB)uptime.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) $(INCLUDE) -c -fPIC $(LIB)uptime.c -o uptime.o

clean:
	rm -rf *.o ./*.so
