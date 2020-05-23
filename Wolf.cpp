#include <iostream>
#include "Wolf.h"
#include "World.h"
using namespace std;

Wolf::Wolf(int x, int y, World& world)
{
	this->name_ = "Wolf";
	this->power_ = 9;
	this->courage_ = 5;
	this->positionX_ = x;
	this->positionY_ = y;
	world.isOccupied[positionX_][positionY_] = 1;
}

Organism* Wolf::clone()
{
	return new Wolf(*this);
}

char Wolf::printSymbol()
{
	return 'W';
}