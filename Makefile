CXX = g++
CXXFLAGS = -std=c++14 -Wall -fconcepts

OBJECTS = card.o deck.o player.o game.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o *.gch core main
