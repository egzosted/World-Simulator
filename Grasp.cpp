#include <iostream>
#include "Grasp.h"
#include "World.h"

using namespace std;

Grasp::Grasp(int x, int y, World& world)
{
	this->name_ = "Grasp";
	this->power_ = 0;
	this->courage_ = 0;
	this->positionX_ = x;
	this->positionY_ = y;
	world.isOccupied[positionX_][positionY_] = 1;
}

Organism* Grasp::clone()
{
	return new Grasp(*this);
}

char Grasp::printSymbol()
{
	return 'G';
}