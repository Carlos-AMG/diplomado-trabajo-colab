CC = $(CROSS_COMPILE)gcc
LIBS = -L./libs -Wl,-rpath=./libs

APP_NAME = main
LIB_NAME = uname uptime cat

OBJ = ./libs/uname.so ./libs/uptime.so ./libs/cat.so

all: $(APP_NAME)

$(APP_NAME): main.o ./libs/uname.so ./libs/uptime.so ./libs/cat.so
	$(CC) -Wall main.o ./libs/uname.so ./libs/uptime.so ./libs/cat.so -o $(APP_NAME)

./libs/uname.so:
	cd ./uname && make all

./libs/uptime.so: 
	cd ./uptime && make all
	
./libs/cat.so: 
	cd ./cat && make all

main.o: main.c ./include/uname.h ./include/uptime.h ./include/cat.h
	$(CC) -Wall -I include -c main.c -o main.o
	
install: $(APP_NAME) $(OBJ)
	sudo cp $(APP_NAME) /usr/bin/
	sudo cp $(OBJ) /usr/lib/

clean:
	cd ./uptime && make clean
	cd ./uname && make clean
	cd ./cat && make clean
	rm -f *.o $(APP_NAME)

$(shell mkdir -p libs)  # Create the 'libs' directory if it doesn't exist
