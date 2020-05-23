#include <iostream>
#include "Plant.h"
#include "World.h"
#include "windows.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

void Plant::action(World& world)
{
	int reproduction = 0;
	reproduction = rand() % 100 + 1;
	if (reproduction <= 10)	//plants have 10% probability to reproduce in every round
		tryReproduce(world);
}

void Plant::collision(World& world, Organism* offender)
{
	world.report += this->name_;	world.report += " ate by ";
	world.report += offender->getName(); world.report += "\n";
	world.isOccupied[offender->getX()][offender->getY()] = 0;
	world.head->remove(positionX_, positionY_);
	offender->setX(this->getX());
	offender->setY(this->getY());
}

void Plant::poisoningCollision(World& world, Organism* offender)
{
	world.report += this->name_;	world.report += " ate by ";
	world.report += offender->getName(); world.report += "\n";
	world.report += offender->getName(); world.report += " poisoned by ";
	world.report += this->name_; world.report += "\n";
	world.isOccupied[offender->getX()][offender->getY()] = 0;
	world.isOccupied[this->getX()][this->getY()] = 0;
	world.head->remove(this->getX(), this->getY());
	offender->setX(this->getX());
	offender->setY(this->getY());
	if (offender->getName() == "Human")
		world.markEnd();
	world.head->remove(offender->getX(), offender->getY());
}

void Plant::tryReproduce(World& world)
{
	if (this->isEmpty(this->getX(), this->getY(), world))
	{
		world.report += this->getName(); world.report += " has been sown\n";
		Organism* o = this->clone();
		o->setAdulthood(false);
		o->setX(world.getFirstCoordinate());
		o->setY(world.getSecondCoordinate());
		world.head->insertByCourage(o);
		world.isOccupied[o->getX()][o->getY()] = 1;
	}
}