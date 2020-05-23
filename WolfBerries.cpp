#include <iostream>
#include "WolfBerries.h"
#include "World.h"

using namespace std;

WolfBerries::WolfBerries (int x, int y, World& world)
{
	this->name_ = "WolfBerries";
	this->power_ = 99;
	this->courage_ = 0;
	this->positionX_ = x;
	this->positionY_ = y;
	world.isOccupied[positionX_][positionY_] = 1;
}

void WolfBerries::collision(World& world, Organism* offender)
{
	poisoningCollision(world, offender);
}

Organism* WolfBerries::clone()
{
	return new WolfBerries(*this);
}

char WolfBerries::printSymbol()
{
	return 'B';
}