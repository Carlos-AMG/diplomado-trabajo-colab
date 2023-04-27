CROSS_COMPILE=arm-linux-gnueabihf-
CC=$(CROSS_COMPILE)gcc
CFLAGS=-Wall -Wextra -fPIC
LIB_NAME=libuname.so

all: $(LIB_NAME)

$(LIB_NAME): uname.so
	$(CC) -shared $^ -o $@

uname.so: uname.c uname.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(LIB_NAME) uname.so
