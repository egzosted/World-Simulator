#pragma once
#include "Animal.h"

class Wolf : public Animal
{
public:
	Wolf(int x, int y, World& world);
	virtual char printSymbol() override;
	Organism* clone() override;
};