#include <iostream>
#include "Antelope.h"
#include "World.h"
#include <ctime>
#include <stdlib.h>
using namespace std;

Antelope::Antelope(int x, int y, World& world)
{
	this->name_ = "Antelope";
	this->power_ = 4;
	this->courage_ = 4;
	this->positionX_ = x;
	this->positionY_ = y;
	world.isOccupied[positionX_][positionY_] = 1;
}

void Antelope::action(World& world)
{
	int direction, found = 0, jump;
	do
	{
		direction = rand() % 4;
		jump = rand() % 2;
		found = isMovementInsideAnt(world, direction, jump);
	} while (found == 0);
	if (jump == WALK_)
		setNextXY(direction);
	else
		setJumpXY(direction);
	move(world);
}

void Antelope::collision(World& world, Organism* offender)
{
	int escape = 0, successfulEscape = 0;
	escape = rand() % 100 + 1;
	if(escape > 50)
		successfulEscape = this->escape(world);
	if (this->name_ == offender->getName())
		reproduce(world);
	else if (escape <= 50 || (escape > 50 && successfulEscape == 0))	//antelope has 50% probability to avoid fight with offender and escape to the closest empty field
	{
		int isDead = 0;
		isDead = didDie(offender);
		if (isDead == 0)
			defenderWon(world, offender);
		else
			offenderWon(world, offender);
	}
	else 
	{
		world.isOccupied[world.getFirstCoordinate()][world.getSecondCoordinate()] = 1;
		world.isOccupied[offender->getX()][offender->getY()] = 0;
		offender->setX(this->getX());
		offender->setY(this->getY());
		this->setX(world.getFirstCoordinate());
		this->setY(world.getSecondCoordinate());
	}
}

bool Antelope::escape(World& world)
{
	int foundPlace = 0;
	foundPlace = isEmpty(getX(), getY(), world);
	if (foundPlace == 0)
		return false;
	else
		return true;
}

bool Antelope::isMovementInsideAnt(World& world, int direction, int jump)
{
	int found = 0;
	if(direction == LEFT && jump == JUMP_)
		found = isInside(positionX_, positionY_ - 2, world.getHeight(), world.getWidth());
	else if (direction == LEFT && jump == WALK_)
		found = isInside(positionX_, positionY_ - 1, world.getHeight(), world.getWidth());
	else if(direction == RIGHT && jump == JUMP_)
		found = isInside(positionX_, positionY_ + 2, world.getHeight(), world.getWidth());
	else if(direction == RIGHT && jump == WALK_)
		found = isInside(positionX_, positionY_ + 1, world.getHeight(), world.getWidth());
	else if (direction == UP && jump == JUMP_)
		found = isInside(positionX_ - 2, positionY_, world.getHeight(), world.getWidth());
	else if (direction == UP && jump == WALK_)
		found = isInside(positionX_ - 1, positionY_, world.getHeight(), world.getWidth());
	else if (direction == DOWN && jump == JUMP_)
		found = isInside(positionX_ + 2, positionY_, world.getHeight(), world.getWidth());
	else
		found = isInside(positionX_ + 1, positionY_, world.getHeight(), world.getWidth());
	return found;
}

void Antelope::setJumpXY(int direction)
{
	if (direction == LEFT)
	{
		nextY_ = positionY_ - 2;
		nextX_ = positionX_;
	}
	else if (direction == RIGHT)
	{
		nextY_ = positionY_ + 2;
		nextX_ = positionX_;
	}
	else if (direction == UP)
	{
		nextY_ = positionY_;
		nextX_ = positionX_ - 2;
	}
	else
	{
		nextX_ = positionX_ + 2;
		nextY_ = positionY_;
	}

}

Organism* Antelope::clone()
{
	return new Antelope(*this);
}

char Antelope::printSymbol()
{
	return 'A';
}