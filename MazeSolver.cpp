#include "MazeSolver.h"
#include "Maze.h"
#include "Creature.h"
using namespace std;

MazeSolver::MazeSolver() : success(false) {
	//default constructor
}

bool MazeSolver::isSuccessful() const {
	return success;
}


bool MazeSolver::goNorth(Creature& myCreature, Maze& myMaze)
{ // creature coming from the south
	// if space to the north is within the maze
	cout << "Heading North." << endl;
	if ((myCreature.getCrRow() - 1) >= 0)
	{
		
		char stateOfNorth = myMaze.getSquareState(myCreature.getCrRow() - 1, myCreature.getCrCol());
		cout << "North reads: " << stateOfNorth << endl;
		
		if (stateOfNorth == myMaze.getClearSymbol() || stateOfNorth == myMaze.getPathSymbol()) // if the path is clear, it has not been visited
		{
			cout << "Moving the creature north. " << endl;
			myCreature.moveNorth();
			cout << "Movement is passed .. Marking the path..." << endl;
			myCreature.markAsPath();
			cout << "Path Marked." << endl;
			myMaze.display();
			
			if (isAtExit(myCreature, myMaze))
			{
				cout << "Creature has made it out of the maze!" << endl;
				success = true;
			}
			else
			{
				success = goNorth(myCreature, myMaze); // else try to go north again
				if (!success)
				{
					success = goWest(myCreature, myMaze); // else try to go west
					if (!success)
					{
						success = goEast(myCreature, myMaze);// else try to go east
						if (!success)
						{
							cout << "Heading back South!" << endl << endl;
							myCreature.markAsVisited(); // else mark the square as visited
							goSouth(myCreature, myMaze); // and head back south
						}
					}
				}
			}
		}
	}
	else success = false;
	return success;
}

bool MazeSolver::goWest(Creature& myCreature, Maze& myMaze) {
	cout << "Heading West." << endl;
	if ((myCreature.getCrCol() - 1) >= 0)
	{
		//get the state of the space to the north
		char stateOfWest = myMaze.getSquareState(myCreature.getCrRow(), myCreature.getCrCol() - 1);
		cout << "West reads: " << stateOfWest << endl;
		// and if space to the west is clear
		if (stateOfWest == myMaze.getClearSymbol() || stateOfWest == myMaze.getPathSymbol()) // if the path is clear, it has not been visited
		{
			cout << "Moving the creature west. " << endl;
			myCreature.moveWest();
			cout << "Movement passed .. Marking the path..." << endl;
			myCreature.markAsPath();
			cout << "Path Marked." << endl;
			myMaze.display();
			// if we're at the exit, we're done
			if (isAtExit(myCreature, myMaze))
			{
				cout << "Creature has made it out of maze!" << endl;
				success = true;
			}
			else
			{
				success = goNorth(myCreature, myMaze); // else try to go north again
				if (!success)
				{
					success = goWest(myCreature, myMaze); // else try to go west
					if (!success)
					{
						success = goSouth(myCreature, myMaze);// else try to go south
						if (!success)
						{
							cout << "Heading back East!" << endl << endl;
							myCreature.markAsVisited(); // else mark the square as visited
							goEast(myCreature, myMaze); // and head back east
						}
					}
				}
			}
		}
	}
	else success = false;
	return success;
}

bool MazeSolver::goEast(Creature& myCreature, Maze& myMaze) {
	// coming from the west
	cout << "Heading East!" << endl;
	if ((myCreature.getCrCol() + 1) < myMaze.getMazeWidth())
	{
		//get the state of the space to the east
		char stateOfEast = myMaze.getSquareState(myCreature.getCrRow(), myCreature.getCrCol() + 1);
		cout << "East reads: " << stateOfEast << endl;
		// and if space to the east is clear
		if (stateOfEast == myMaze.getClearSymbol() || stateOfEast == myMaze.getPathSymbol()) // if the square is clear or on path, it has not been visited
		{
			cout << "Moving the creature east. " << endl;
			myCreature.moveEast();
			cout << "Movement pass... Marking the path..." << endl;
			myCreature.markAsPath();
			cout << "Path Marked." << endl;
			myMaze.display();
			// if we're at the exit, we're done
			if (isAtExit(myCreature, myMaze))
			{
				cout << "Creature has made it out of the maze!" << endl;
				success = true;
			}
			else
			{
				success = goNorth(myCreature, myMaze); // else try to go north again
				if (!success)
				{
					success = goEast(myCreature, myMaze); // else try to go east
					if (!success)
					{
						success = goSouth(myCreature, myMaze);// else try to go south
						if (!success)
						{
							cout << "Heading back West!" << endl << endl;
							myCreature.markAsVisited(); // else mark the square as visited
							goWest(myCreature, myMaze); // and head back West
						}
					}
				}
			}
		}
	}
	else success = false;
	return success;
}

bool MazeSolver::goSouth(Creature& myCreature, Maze& myMaze) {
	cout << "HeadingSouth!" << endl;
	if ((myCreature.getCrRow() + 1) < myMaze.getMazeLength())
	{
		//get the state of the space to the east
		char stateOfSouth = myMaze.getSquareState(myCreature.getCrRow() + 1, myCreature.getCrCol());
		cout << "South reads: " << stateOfSouth << endl;
		// and if space to the east is clear
		if (stateOfSouth == myMaze.getClearSymbol() || stateOfSouth == myMaze.getPathSymbol()) // if the square is clear or on path, it has not been visited
		{
			cout << "Moving the creature South. " << endl;
			myCreature.moveSouth();
			cout << "Movement passed... Marking the path..." << endl;
			myCreature.markAsPath();
			cout << "Path Marked." << endl;
			myMaze.display();
			// if we're at the exit, we're done
			if (isAtExit(myCreature, myMaze))
			{
				cout << "Creature has made it out of the maze!" << endl;
				success = true;
			}
			else
			{
				success = goWest(myCreature, myMaze); // else try to go north again
				if (!success)
				{
					success = goSouth(myCreature, myMaze); // else try to go south again
					if (!success)
					{
						success = goEast(myCreature, myMaze);// else try to go east
						if (!success)
						{
							cout << "No where to go, lets head back!" << endl << endl;
							myCreature.markAsVisited(); // else mark the square as visited
							goNorth(myCreature, myMaze); // and head back north
						}
					}
				}
			}
		}
	}
	else success = false;
	return success;
}

bool MazeSolver::isAtExit(Creature& myCreature, Maze& myMaze) const {
	const Maze* theMazePtr = myCreature.getMazePtr();
	int currentCreatureRow = myCreature.getCrRow();
	int currentCreatureCol = myCreature.getCrCol();
	int mazeExitRow = myMaze.getExitRow();
	int mazeExitCol = myMaze.getExitCol();
	return (mazeExitRow == currentCreatureRow) && (mazeExitCol == currentCreatureCol);
}
