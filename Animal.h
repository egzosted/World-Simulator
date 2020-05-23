#pragma once
#include "Organism.h"
class World;
class Animal : public Organism
{
protected:
	int nextX_, nextY_;
	const int LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3;
public:
	int isMovementInside(World& world, int direction);
	void basicAction(World& world);
	void setNextXY(int direction);
	void reproduce(World& world);
	void defenderWon(World& world, Organism* offender);
	void offenderWon(World& world, Organism* offender);
	virtual void move(World& world);
	virtual void collision(World& world, Organism* offender) override;
	virtual void action(World& world) override;
};