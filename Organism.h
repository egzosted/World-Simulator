#pragma once
#include <string>
using namespace std;
class World;

class Organism
{
protected:
	string name_;
	int positionX_;
	int positionY_;
	int power_;
	int courage_;
	bool adulthood_;	//flag to block organism move in same round they borned
public:
	int getX();
	int getY();
	int getPower();
	int getCourage();
	bool getAdulthood();
	void setX(int x);
	void setY(int y);
	void setAdulthood(bool x);
	void setPower(int x);
	string getName();
	bool isInside(int x, int y, int height, int width);	//method to check if location is in map
	bool isEmpty(int x, int y, World& world);
	virtual void action(World& world) = 0;
	virtual void collision(World& world, Organism* offender) = 0;
	virtual void turnOnUltimate();
	virtual void handleUltimate();	//method used to decrement power during duration of ultimate until reaching of base level
	virtual char printSymbol() = 0;
	virtual bool didDie(Organism* offender);
	virtual Organism* clone() = 0;
};