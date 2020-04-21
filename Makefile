CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJECTS = card.o deck.o player.o game.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o *.gch core main
