OBJS	= orquesta.o instrumento.o main.o
SOURCE	= orquesta.cpp instrumento.cpp main.cpp
HEADER	= 
OUT	= delegacion
CC	 = g++
FLAGS	 = -g3 -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

orquesta.o: orquesta.cpp
	$(CC) $(FLAGS) orquesta.cpp -std=c++11

instrumento.o: instrumento.cpp
	$(CC) $(FLAGS) instrumento.cpp -std=c++11

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)

debug: $(OUT)
	valgrind $(OUT)

valgrind: $(OUT)
	valgrind $(OUT)

valgrind_leakcheck: $(OUT)
	valgrind --leak-check=full $(OUT)

valgrind_extreme: $(OUT)
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes $(OUT)
