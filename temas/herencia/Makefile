CXX = g++
CXXFLAGS = -g -Wall -std=c++11 -pedantic
CPPFLAGS = -I. 

EXES = combate
CLASES = combate.o POOkemon.o 

.PHONY: all clean

all: $(EXES)

combate: $(CLASES)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean: 
	@$(RM) $(EXES) *.o