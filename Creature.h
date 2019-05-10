#ifndef CREATURE_H
#define CREATURE_H


class Maze;

class Creature {

private:

	const char creatureChar = 'B'; 
	static Maze* mazePtr;
	
	int crRow;
	int crCol;
public:

	Creature();
	void markAsVisited();
	void markAsPath();
	void moveWest();
	void moveEast();
	void moveNorth();
	void moveSouth();

	static void setMaze(Maze* mPtr);
	int getCrRow() const;
	int getCrCol() const;
	static const Maze* getMazePtr();
};
#endif


