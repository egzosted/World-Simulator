#pragma once
#include "Plant.h"
class Grasp : public Plant
{
public:
	Grasp(int x, int y, World& world);
	char printSymbol() override;
	Organism* clone() override;
};