#pragma once
#include "Animal.h"

class Antelope : public Animal
{
private:
	const int JUMP_ = 1, WALK_ = 0;	// scope of antelope is equal to 2 fields
public:
	Antelope(int x, int y, World& world);
	void action(World& world) override;
	void collision(World& world, Organism* offender) override;
	void setJumpXY(int direction);
	bool escape(World& world);
	bool isMovementInsideAnt(World& world, int direction, int jump);
	char printSymbol() override;
	Organism* clone() override;
};
