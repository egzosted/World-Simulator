#include <iostream>
#include "Human.h"
#include "World.h"
using namespace std;

Human::Human(int x, int y, World& world)
{
	this->name_ = "Human";
	this->power_ = 5;
	this->courage_ = 4;
	this->positionX_ = x;
	this->positionY_ = y;
	this->startUltimate_ = 0;
	this->endUltimate_ = 0;
	world.isOccupied[positionX_][positionY_] = 1;
}

void Human::action(World& world)
{
	handleUltimate();
	int direction;
	if (world.getDirection() == world.LEFT)
		direction = LEFT;
	else if (world.getDirection() == world.RIGHT)
		direction = RIGHT;
	else if (world.getDirection() == world.UP)
		direction = UP;
	else
		direction = DOWN;
	if (!(isMovementInside(world, direction)))
		return;
	setNextXY(direction);
	move(world);
}

char Human::printSymbol()
{
	return 'H';
}

Organism* Human::clone()
{
	return new Human(*this);
}

void Human::turnOnUltimate()
{
	if (startUltimate_ == endUltimate_)
	{
		this->power_ += 5;
		endUltimate_ = 10;
	}
}

void Human::handleUltimate()
{
	if (endUltimate_ >= 5 && endUltimate_ < 10)
		this->power_--;
	if (endUltimate_ > 0)
		endUltimate_--;
}