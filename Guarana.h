#pragma once
#include "Plant.h"
class Guarana : public Plant
{
public:
	Guarana(int x, int y, World& world);
	void collision(World& world, Organism* offender) override;
	char printSymbol() override;
	Organism* clone() override;
};