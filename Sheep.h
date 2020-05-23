#pragma once
#include "Animal.h"

class Sheep : public Animal
{
public:
	Sheep(int x, int y, World& world);
	virtual char printSymbol() override;
	Organism* clone() override;
};
