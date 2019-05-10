#ifndef MAZE_H
#define MAZE_H

#include "Creature.h"
#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

struct SquareData
{
	int Col;
	int Row;
	char State;
	void setCol(const int& col)
	{
		Col = col;
	}
	void setRow(const int& row)
	{
		Row = row;
	}
	void setState(const char& state)
	{
		State = state;
	}
};

class Maze {
private:
	vector<SquareData*> squares;
	int mazeWidth;
	int mazeLength;
	int exitRow;
	int exitCol;
	int entRow;
	int entCol;
	
	const char pathMarker = 'p';
	const char visitMarker = 'v';
	const char wallMarker = 'x';
	const char clearMarker = ' ';

	int getIndexOfSquare(const int& squareRow, const int& squareCol) const;
public:
	Maze();						//Default Constructor

	Maze(std::ifstream& inputFile);
								 
	Maze(const Maze& myMaze);		// Copy Constructor
	
	virtual ~Maze();			//Desctructor
	void clear();
	void display() const;
	bool isWall(const int& squareRow, const int& squareCol) const;
	bool isClear(const int& squareRow, const int& squareCol) const;
	bool isOnPath(const int& squareRow, const int& squareCol) const;
	bool visited(const int& squareRow, const int& squareCol) const;

	SquareData* getSquare(const int& squareRow, const int& squareCol) const;
	
	char getSquareState(const int& squareRow, const int& squareCol) const;
	bool markSquareAsPath(const int& squareRow, const int& squareCol);
	bool markSquareAsVisited(const int& squareRow, const int& squareCol);
	bool markSquareAsClear(const int& squareRow, const int& squareCol);

	int numSquares() const;
	int getEntRow() const;
	int getEntCol() const;
	int getExitRow() const;
	int getExitCol() const;
	int getMazeWidth() const;
	int getMazeLength() const;
	char getClearSymbol() const;
	void vectorDisplay() const;
	char getPathSymbol() const;
};

#endif
