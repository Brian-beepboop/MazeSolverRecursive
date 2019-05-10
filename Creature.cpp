#include "Maze.h"
#include "Creature.h"

Maze* Creature::mazePtr = nullptr;

Creature::Creature() : crRow(mazePtr->getEntRow()), crCol(mazePtr->getEntCol()) {
	//default constructor
}

void Creature::markAsVisited() {
	mazePtr->markSquareAsVisited(crRow, crCol);
}

void Creature::markAsPath()
{
	mazePtr->markSquareAsPath(crRow, crCol);
}

void Creature::moveEast()
{
	crCol++;
}

void Creature::moveNorth()
{
	crRow--;
}

void Creature::moveSouth()
{
	crRow++;
}

void Creature::moveWest()
{
	crCol--;
}

void Creature::setMaze(Maze* mPtr) {
	mazePtr = mPtr;
}

int Creature::getCrRow() const {
	return crRow;
}

int Creature::getCrCol() const {
	return crCol;
}

const Maze* Creature::getMazePtr() {
	return mazePtr;
}
