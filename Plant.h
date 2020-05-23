#pragma once
#include "Organism.h"
class World;
class Plant : public Organism
{
protected:
	int nextX_, nextY_;
	const int LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3;
public:
	void tryReproduce(World& world);
	void poisoningCollision(World& world, Organism* offender);	//offender dies after eating of plant
	virtual void collision(World& world, Organism* offender) override;
	virtual void action(World& world) override;
};
