CC = $(CROSS_COMPILE)gcc
LIBS = -L./libs -Wl,-rpath=./libs


APP_NAME = main
LIB_NAME = uname uptime

OBJ = ./libs/uname.so ./libs/uptime.so

all: $(APP_NAME)

$(APP_NAME): main.o ./libs/uname.so ./libs/uptime.so
	$(CC) -Wall main.o ./libs/uname.so ./libs/uptime.so -o main

./libs/uname.so:
	cd ./uname && make all

./libs/uptime.so: 
	cd ./uptime && make all

main.o: main.c ./include/uname.h ./include/uptime.h
	$(CC) -Wall -I include -c main.c -o main.o

clean:
	cd ./uptime && make clean
	cd ./uname && make clean
	rm -f *.o $(APP_NAME)
