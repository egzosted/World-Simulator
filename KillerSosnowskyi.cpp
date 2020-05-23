#include <iostream>
#include "KillerSosnowskyi.h"
#include "World.h"

using namespace std;

KillerSosnowskyi::KillerSosnowskyi(int x, int y, World& world)
{
	this->name_ = "KillerSosnowskyi";
	this->power_ = 10;
	this->courage_ = 0;
	this->positionX_ = x;
	this->positionY_ = y;
	world.isOccupied[positionX_][positionY_] = 1;
}

void KillerSosnowskyi::action(World& world)
{
	kill(world, this->getX(), this->getY() - 1); //kill left enemy
	kill(world, this->getX(), this->getY() + 1);	//kill right enemy
	kill(world, this->getX() - 1 , this->getY());	//kill up enemy
	kill(world, this->getX() + 1, this->getY()); //kill down enemy
	int reproduction = 0;
	reproduction = rand() % 100 + 1;
	if (reproduction <= 10)	//plants have 10% probability to reproduce in every round
		tryReproduce(world);
}

void KillerSosnowskyi::kill(World& world, int x, int y)
{
	if (isInside(x, y, world.getHeight(), world.getWidth()) && world.isOccupied[x][y] == 1)
	{
		Organism* o = world.head->find(x, y);
		if (o->getCourage() > 0)	//we want to kill only animals
		{
			world.isOccupied[x][y] = 0;
			world.report += o->getName(); world.report += " poisoned by ";
			world.report += this->getName(); world.report += "\n";
			if (o->getName() == "Human")
				world.markEnd();
			world.head->remove(x, y);
		}	
	}
}


void KillerSosnowskyi::collision(World& world, Organism* offender)
{
	poisoningCollision(world, offender);
}

Organism* KillerSosnowskyi::clone()
{
	return new KillerSosnowskyi(*this);
}

char KillerSosnowskyi::printSymbol()
{
	return 'K';
}