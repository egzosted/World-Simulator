#include <iostream>
#include "Fox.h"
#include "World.h"
using namespace std;

Fox::Fox(int x, int y, World& world)
{
	this->name_ = "Fox";
	this->power_ = 3;
	this->courage_ = 7;
	this->positionX_ = x;
	this->positionY_ = y;
	world.isOccupied[positionX_][positionY_] = 1;
}

void Fox::action(World& world)
{
	int direction, found = 0, iterator = 0;
	do
	{
		direction = rand() % 4;
		if (direction == LEFT)
		{
			found = isMovementInside(world, direction);
			if (found == 1)
			{
				Organism* o = world.head->find(positionX_, positionY_ - 1);
				if (this->power_ < o->getPower())
					found = 0;
			}
		}
		else if (direction == RIGHT)
		{
			found = isMovementInside(world, direction);
			if (found == 1)
			{
				Organism* o = world.head->find(positionX_, positionY_ + 1);
				if (this->power_ < o->getPower())
					found = 0;
			}
		}
		else if (direction == UP)
		{
			found = isMovementInside(world, direction);
			if (found == 1)
			{
				Organism* o = world.head->find(positionX_ - 1, positionY_);
				if (this->power_ < o->getPower())
					found = 0;
			}
		}
		else
		{
			found = isMovementInside(world, direction);
			if (found == 1)
			{
				Organism* o = world.head->find(positionX_ + 1, positionY_);
				if (this->power_ < o->getPower())
					found = 0;
			}
		}
		iterator++;
	} while (found == 0 && iterator < 1000);
	if (found == 1)
	{
		setNextXY(direction);
		move(world);
	}
}

Organism* Fox::clone()
{
	return new Fox(*this);
}

char Fox::printSymbol()
{
	return 'F';
}