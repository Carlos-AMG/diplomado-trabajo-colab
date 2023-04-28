CROSS_COMPILE=arm-linux-gnueabihf-
CC=$(CROSS_COMPILE)gcc
AR=$(CROSS_COMPILE)ar
CFLAGS=-Wall -Wextra -Werror

# Targets
.PHONY: all clean

all: libcat.so

libcat.so: cat.o
	$(CC) -shared -o $@ $^

cat.o: cat.c cat.h
	$(CC) -c $(CFLAGS) -fPIC -o $@ $<

clean:
	rm -f *.o *.so
