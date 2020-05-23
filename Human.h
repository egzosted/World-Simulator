#pragma once
#include "Animal.h"
class World;
class Human : public Animal
{
private:
	int startUltimate_, endUltimate_;
public:
	Human(int x, int y, World& world);
	virtual void action(World& world) override;
	virtual char printSymbol() override;
	Organism* clone() override;
	void turnOnUltimate() override;
	void handleUltimate() override;
};
