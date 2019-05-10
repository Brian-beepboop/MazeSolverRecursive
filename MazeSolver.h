#ifndef MAZESOLVER_H
#define MAZESOLVER_H

class Maze; // forward declaration of maze
class Creature; // forward declaration of creature

class MazeSolver {
	bool success;
public:
	//** default constructor */
	MazeSolver();
	void vectorTester() const;
	//** RECURSIVE MOVEMENT METHODS */
	bool goNorth(Creature& myCreature, Maze& myMaze);
	bool goWest(Creature& myCreature, Maze& myMaze);
	bool goEast(Creature& myCreature, Maze& myMaze);
	bool goSouth(Creature& myCreature, Maze& myMaze);
	//** accessor for success */
	bool isSuccessful() const;
	bool isAtExit(Creature& myCreature, Maze& myMaze) const;
};

#endif
