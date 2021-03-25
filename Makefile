CC = g++

CFLAGS = -g
CFLAGS_OBJ = $(CFLAGS) -c
CFLAGS_BUILD = $(CFLAGS) -o main

main: main.o actions.o controller.o Server.o parser.o
	$(CC) $(CFLAGS_BUILD) *.o

main.o:
	$(CC) $(CFLAGS_OBJ) main.cpp

actions.o:
	$(CC) $(CFLAGS_OBJ) controller/actions.cpp

controller.o:
	$(CC) $(CFLAGS_OBJ) controller/controller.cpp

Server.o:
	$(CC) $(CFLAGS_OBJ) server/Server.cpp

parser.o:
	$(CC) $(CFLAGS_OBJ) parser/parser.cpp

run: main
	./main

clean:
	rm -f main *.o

