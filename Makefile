CXX = g++
CXXFLAGS = -std=c++17 -Wall -fconcepts -fpermissive

main: 
	$(CXX) $(CXXFLAGS) *.cpp -o $@ 

clean:
	$(RM) *.o *.gch core main
