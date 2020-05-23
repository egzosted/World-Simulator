#pragma once
#include "Plant.h"
class Yellow : public Plant
{
public:
	Yellow(int x, int y, World& world);
	void action(World& world) override;
	char printSymbol() override;
	Organism* clone() override;
};
