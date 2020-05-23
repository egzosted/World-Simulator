#include "Organism.h"
#include "World.h"

bool Organism::isInside(int x, int y, int height, int width)
{
	if (x < 0 || y < 0 || x >= height || y >= width)
		return false;
	return true;
}

int Organism::getX()
{
	return positionX_;
}

int Organism::getY()
{
	return positionY_;
}

int Organism::getPower()
{
	return power_;
}

int Organism::getCourage()
{
	return courage_;
}

bool Organism::getAdulthood()
{
	return adulthood_;
}

void Organism::setX(int x)
{
	positionX_ = x;
}

void Organism::setY(int y)
{
	positionY_ = y;
}

void Organism::setPower(int x)
{
	power_ = x;
}

void Organism::setAdulthood(bool x)
{
	adulthood_ = x;
}

string Organism::getName()
{
	return name_;
}


bool Organism::didDie(Organism*offender)
{
	if (this->power_ <= offender->power_)
		return true;
	return false;
}

bool Organism::isEmpty(int x, int y, World& world)
{
	if (y-1 >= 0 && world.isOccupied[x][y - 1] == 0)	//first we check reproduction on left side
	{
		world.setCoordinates(x, y - 1);
		return true;
	}
	if (y+1 < world.getWidth() && world.isOccupied[x][y + 1] == 0)	//check reproduction on right side
	{
		world.setCoordinates(x, y + 1);
		return true;
	}
	if (x-1 >= 0 && world.isOccupied[x-1][y] == 0)	//check reproduction on top side
	{
		world.setCoordinates(x - 1, y);
		return true;
	}
	if (x + 1 < world.getHeight() && world.isOccupied[x + 1][y] == 0)
	{
		world.setCoordinates(x + 1, y);
		return true;
	}
	return false;
}

void Organism::turnOnUltimate()
{

}

void Organism::handleUltimate()
{

}