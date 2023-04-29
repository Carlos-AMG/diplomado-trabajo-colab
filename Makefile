#CROSS_COMPILE = arm-linux-gnueabi-
#CROSS_COMPILE =
CC = gcc
CFLAGS = -Wall
INCLUDE := -I include
TARGET=little_busybox
DIRBIN = ./bin

all: $(TARGET)

$(TARGET):
	cd ./uptime/ && make all
	@test ! -d $(DIRBIN) && mkdir $(DIRBIN)
	cp ./uptime/uptime.so $(DIRBIN)
	cp ./uptime/uptime.so ./
	$(CROSS_COMPILE)$(CC) $(CFLAGS) $(INCLUDE) -c main.c -o main.o 
	$(CROSS_COMPILE)$(CC) $(CFLAGS) main.o -o $(DIRBIN)/$(TARGET) ./uptime.so
	rm -rf *.so

install:

clean:
	rm -rf *.o $(DIRBIN)
	cd ./uptime && make clean
