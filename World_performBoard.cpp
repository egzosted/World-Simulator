#include "World.h"
#include "Human.h"
#include <iostream>
#include "windows.h"
#include "stdlib.h"
#include "time.h"
using namespace std;

int World::performBoard(int direction, int ultimate)
{
	if (ultimate == 1)
		human->turnOnUltimate();
	direction_ = direction;
	if (!(checkDirection()))
		return false;
	current = head->next;
	while (current != nullptr)
	{
		if(current->organism->getAdulthood() == true)
			(current->organism)->action(*this);
		current = current->next;
	}
	current = head->next;
	while (current != nullptr)
	{
		current->organism->setAdulthood(true);
		current = current->next;
	}
	return true;
}

void World::setCoordinates(int x, int y)
{
	coordinates[0] = x;
	coordinates[1] = y;
}

int World::getFirstCoordinate()
{
	return coordinates[0];
}

int World::getSecondCoordinate()
{
	return coordinates[1];
}