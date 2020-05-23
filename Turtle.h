#pragma once
#include "Animal.h"

class Turtle : public Animal
{
public:
	Turtle(int x, int y, World& world);
	void action(World& world) override;
	void collision(World& world, Organism* offender) override;
	bool didDie(Organism* offender) override;
	char printSymbol() override;
	Organism* clone() override;
};