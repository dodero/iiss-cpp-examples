CXX = g++
CXXFLAGS = -g -Wall -std=c++11 -pedantic
CPPFLAGS = -I. 

EXES = prueba
CLASES = Prueba.o Aventura.o 

.PHONY: all clean

all: $(EXES)

prueba: $(CLASES)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean: 
	@$(RM) $(EXES) *.o