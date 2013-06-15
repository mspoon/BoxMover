CFLAGS=-Wall -std=c++0x `sdl2-config --cflags`
LIBS=`sdl2-config --libs`
CC=g++ $(CFLAGS)

EXECUTABLE=boxmover
OBJECTS=Game.o 

all: $(EXECUTABLE)

debug: CC += -DDEBUG -g
debug: EXECUTABLE +=d
debug: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.cpp %.h
	$(CC) -c $<

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
