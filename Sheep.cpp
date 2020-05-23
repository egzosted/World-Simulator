#include <iostream>
#include "Sheep.h"
#include "World.h"
using namespace std;

Sheep::Sheep(int x, int y, World& world)
{
	this->name_ = "Sheep";
	this->power_ = 4;
	this->courage_ = 4;
	this->positionX_ = x;
	this->positionY_ = y;
	world.isOccupied[positionX_][positionY_] = 1;
}

Organism* Sheep::clone()
{
	return new Sheep(*this);
}

char Sheep::printSymbol()
{
	return 'S';
}