#include <iostream>
#include "Turtle.h"
#include "World.h"
#include <ctime>
#include <stdlib.h>
using namespace std;

Turtle::Turtle(int x, int y, World& world)
{
	this->name_ = "Turtle";
	this->power_ = 2;
	this->courage_ = 1;
	this->positionX_ = x;
	this->positionY_ = y;
	world.isOccupied[positionX_][positionY_] = 1;
}

void Turtle::action(World& world)
{
	int movement = 0;
	movement = rand() % 100 + 1;
	if (movement > 75)
		basicAction(world);
}

void Turtle::collision(World& world, Organism* offender)
{
	int isAlive = 0;
	isAlive = didDie(offender);	//nadpisac did die
	if (isAlive == 0)
		offenderWon(world, offender);
	else if (this->name_ == offender->getName())
		reproduce(world);
	else
	{
		world.report += "Turtle has been unsuccesfully attacked by ";
		world.report += offender->getName();
		world.report += "\n";
	}
}

bool Turtle::didDie(Organism* offender)
{
	if (offender->getPower() < 5)
		return true;
	return false;
}

Organism* Turtle::clone()
{
	return new Turtle(*this);
}

char Turtle::printSymbol()
{
	return 'T';
}