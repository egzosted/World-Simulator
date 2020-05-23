#pragma once
#include "Plant.h"
class KillerSosnowskyi : public Plant
{
private:
public:
	KillerSosnowskyi(int x, int y, World& world);
	void action(World& world);
	void kill(World& world, int x, int y);
	void collision(World& world, Organism* offender) override;
	char printSymbol() override;
	Organism* clone() override;
};
