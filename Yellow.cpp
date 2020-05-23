#include <iostream>
#include "Yellow.h"
#include "World.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

Yellow::Yellow(int x, int y, World& world)
{
	this->name_ = "Yellow flower";
	this->power_ = 0;
	this->courage_ = 0;
	this->positionX_ = x;
	this->positionY_ = y;
	world.isOccupied[positionX_][positionY_] = 1;
}

void Yellow::action(World& world)
{
	int reproduction = 0;
	for (int i = 0; i < 3; i++)
	{
		reproduction = rand() % 100 + 1;
		if (reproduction <= 10)	//plants have 10% probability to reproduce in every round
		{
			tryReproduce(world);
			break;
		}			
	}	
}

Organism* Yellow::clone()
{
	return new Yellow(*this);
}

char Yellow::printSymbol()
{
	return 'Y';
}