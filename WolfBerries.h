#pragma once
#include "Plant.h"
class WolfBerries : public Plant
{
public:
	WolfBerries(int x, int y, World& world);
	void collision(World& world, Organism* offender) override;
	char printSymbol() override;
	Organism* clone() override;
};