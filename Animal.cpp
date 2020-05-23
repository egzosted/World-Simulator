#include <iostream>
#include "Animal.h"
#include "World.h"

using namespace std;

void Animal::action(World& world)
{
	basicAction(world);
}

void Animal::basicAction(World& world)
{
	int direction, found = 0;
	do
	{
		direction = rand() % 4;
		found = isMovementInside(world, direction);
	} while (found == 0);
	setNextXY(direction);
	move(world);
}

void Animal::reproduce(World& world)	//klasa pozycja
{
	if (this->isEmpty(this->getX(), this->getY(), world))
	{
		world.report += this->getName(); world.report += " has borned\n";
		Organism* o = this->clone();
		o->setAdulthood(false);
		o->setX(world.getFirstCoordinate());
		o->setY(world.getSecondCoordinate());
		world.head->insertByCourage(o);
		world.isOccupied[o->getX()][o->getY()] = 1;
	}
}

void Animal::move(World& world)
{
	if (world.isOccupied[nextX_][nextY_] == 0)
	{
		world.isOccupied[positionX_][positionY_] = 0;
		positionY_ = nextY_;
		positionX_ = nextX_;
		world.isOccupied[nextX_][nextY_] = 1;
	}
	else
	{
		Organism* o = world.head->find(nextX_, nextY_);
		o->collision(world, this);
	}
}


int Animal::isMovementInside(World& world, int direction)
{
	int found = 0;
	if (direction == LEFT)
		found = isInside(positionX_, positionY_ - 1, world.getHeight(), world.getWidth());
	else if (direction == RIGHT)
		found = isInside(positionX_, positionY_ + 1, world.getHeight(), world.getWidth());
	else if (direction == UP)
		found = isInside(positionX_ - 1, positionY_, world.getHeight(), world.getWidth());
	else
		found = isInside(positionX_ + 1, positionY_, world.getHeight(), world.getWidth());
	return found;
}

void Animal::setNextXY(int direction)
{
	if (direction == LEFT)
	{
		nextY_ = positionY_ - 1;
		nextX_ = positionX_;
	}
	else if (direction == RIGHT)
	{
		nextY_ = positionY_ + 1;
		nextX_ = positionX_;
	}
	else if (direction == UP)
	{
		nextY_ = positionY_;
		nextX_ = positionX_ - 1;
	}
	else
	{
		nextX_ = positionX_ + 1;
		nextY_ = positionY_;
	}
}

void Animal::collision(World& world, Organism* offender)
{
	int isDead = 0;
	isDead = didDie(offender);
	if (isDead == 0)
		defenderWon(world, offender);
	else if (this->name_ == offender->getName())
		reproduce(world);
	else
		offenderWon(world, offender);
}

void Animal::defenderWon(World& world, Organism* offender)
{
	world.isOccupied[offender->getX()][offender->getY()] = 0;
	if (offender->getName() == "Human")
		world.markEnd();
	world.report += offender->getName(); world.report += " killed by ";
	world.report += name_; world.report += "\n";
	world.head->remove(offender->getX(), offender->getY());
}

void Animal::offenderWon(World& world, Organism* offender)
{
	world.isOccupied[offender->getX()][offender->getY()] = 0;
	if (name_ == "Human")
		world.markEnd();
	world.report += name_; world.report += " killed by ";
	world.report += offender->getName(); world.report += "\n";
	world.head->remove(positionX_, positionY_);
	offender->setX(this->getX());
	offender->setY(this->getY());
}