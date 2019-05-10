#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Maze.h"
#include "Creature.h"
#include "MazeSolver.h"

using namespace std;

void mazeTester()
{
	//Initial Maze
	cout << "Initialize the maze test: " << endl << endl;
	ifstream myFile("MazeTest.txt");
	Maze myMaze(myFile);
	myMaze.display();
	// Test Boolean Functions
	cout << "Initializing Tests on squares in maze: " << endl << endl;
	cout << "isWall(0,0) returns: " << myMaze.isWall(0, 0) << "; should be 1." << endl;
	cout << "isWall(1,1) returns: " << myMaze.isWall(1, 1) << "; should be 0." << endl;
	cout << "isClear(0,0) returns: " << myMaze.isClear(0, 0) << "; should be 0." << endl;
	cout << "isClear(1,1) returns: " << myMaze.isClear(1, 1) << "; should be 1." << endl;
	cout << "isClear(4,12) returns: " << myMaze.isClear(4, 12) << "; should be 0." << endl;
	cout << "Visited(1,1) returns: " << myMaze.visited(1, 1) << "; should be 0." << endl << endl;
	Creature myCreature;
	myMaze.display();
	MazeSolver myMazeSolver;
	myMazeSolver.goNorth(myCreature, myMaze);
}


int main() {
	mazeTester();
	cout << "Testing is COMPLETE! Exit? hit y ";
	std::string y;
	getline(std::cin, y);
	while (y != "y")
	{
		std::cout << endl << "Invalid Input. Exit?<y>:";
		getline(std::cin, y);
	}
	return 0;
}
