

all: a.out

a.out: Creature.o MazeSolver.o main.o Maze.o
	g++ -o  a.out Creature.o MazeSolver.o main.o Maze.o
	rm -f *.o

Creature.o: Creature.h Creature.cpp Maze.h
	g++ -c -g Creature.cpp
		
MazeSolver.o: MazeSolver.cpp MazeSolver.h Creature.h Maze.h
	g++ -c -g MazeSolver.cpp
		
main.o: main.cpp Maze.h Creature.h MazeSolver.h
	g++ -c -g main.cpp

Maze.o: Maze.cpp Maze.h
	g++ -c -g Maze.cpp

clean:
	rm -f a.out
	
