CC	 := g++
CFLAGS 	:= -Wall -Wextra -O3 --std=c++17
IFLAGS  := -I/usr/local/include/boost
LDFLAGS := -lm
EXE 	:= main
CFILES	:= main.cc gaussian.cc
OBJECTS := main.o gaussian.o

all: ${EXE}

${EXE}: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LDFLAGS)

main.o: main.cc
	$(CC) $(CFLAGS) -c main.cc $(IFLAGS)

gaussian.o: gaussian.cc
	$(CC) $(CFLAGS) -c gaussian.cc $(IFLAGS)


.PHONY: clean
clean:
	rm -f $(EXE) $(OBJECTS)
