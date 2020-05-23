#include <iostream>
#include "Guarana.h"
#include "World.h"

using namespace std;

Guarana::Guarana(int x, int y, World& world)
{
	this->name_ = "Guarana flower";
	this->power_ = 0;
	this->courage_ = 0;
	this->positionX_ = x;
	this->positionY_ = y;
	world.isOccupied[positionX_][positionY_] = 1;
}

void Guarana::collision(World& world, Organism* offender)
{
	world.report += this->name_;	world.report += " ate by ";
	world.report += offender->getName(); world.report += "\n";
	world.isOccupied[offender->getX()][offender->getY()] = 0;
	world.head->remove(positionX_, positionY_);
	int offenderPower = offender->getPower() + 3;
	offender->setPower(offenderPower);
	offender->setX(this->getX());
	offender->setY(this->getY());
}

Organism* Guarana::clone()
{
	return new Guarana(*this);
}

char Guarana::printSymbol()
{
	return 'U';
}