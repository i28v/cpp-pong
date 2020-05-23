CXX = g++
src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)

CXXFLAGS = -Wall -O2 -I/usr/include/SDL2/ -I./include/
LDFLAGS = -lSDL2 -lSDL2_image
	
main: $(obj)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
		
clean:
	rm -f $(obj) main
