#include "World.h"
#include <iostream>
#include "windows.h"
#include "stdlib.h"
#include "time.h"
using namespace std;

void World::generateSymbols()
{
	int x, y;
	currentPS = head->next;
	while (currentPS != nullptr)
	{
		x = (currentPS->organism)->getX();
		y = (currentPS->organism)->getY();
		board[x][y] = currentPS->organism->printSymbol();
		currentPS = currentPS->next;
	}
}

void World::randXY()
{
	do
	{
		coordinates[0] = rand() % height_;
		coordinates[1] = rand() % width_;
	} while (isOccupied[coordinates[0]][coordinates[1]] == 1);
}

void World::printBoard()
{
	for (int i = 0; i < height_; i++)
	{
		for (int j = 0; j < width_; j++)
		{
			if (isOccupied[i][j] == 0)
				cout << '*';
			else
				cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
}

int World::checkDirection()
{
	if (direction_ != LEFT && direction_ != RIGHT && direction_ != UP && direction_ != DOWN)
		return false;
}