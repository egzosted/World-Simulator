#pragma once
#include "Animal.h"

class Fox : public Animal
{
public:
	Fox(int x, int y, World& world);
	virtual void action(World& world) override;
	virtual char printSymbol() override;
	Organism* clone() override;
};
