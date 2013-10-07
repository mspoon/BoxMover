CFLAGS=-Wall -std=c++0x `sdl2-config --cflags`
LIBS=`sdl2-config --libs`
CC=g++ $(CFLAGS)

EXECUTABLE=boxmover
OBJECTS=Vector2D.o System.o EntityManager.o RenderSystem.o MovementSystem.o InputSystem.o Game.o 

all: $(EXECUTABLE)

debug: clean
debug: CC += -DDEBUG -g -O0
debug: EXECUTABLE +=d
debug: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.cpp %.h
	$(CC) -c $<

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
