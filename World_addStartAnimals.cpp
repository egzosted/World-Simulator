#include "World.h"
#include "Human.h"
#include <iostream>
#include "windows.h"
#include "stdlib.h"
#include "time.h"
using namespace std;

void World::addStartAnimals()
{
	Organism* h = nullptr;
	for (int i = 0; i < initialPopulation_; i++)
	{
		randXY();
		h = new Fox(coordinates[0], coordinates[1], *this);
		current->insert(h);
		isOccupied[coordinates[0]][coordinates[1]] = 1;
		current = current->next;
	}
	for (int i = 0; i < initialPopulation_; i++)
	{
		randXY();
		h = new Wolf(coordinates[0], coordinates[1], *this);
		current->insert(h);
		isOccupied[coordinates[0]][coordinates[1]] = 1;
		current = current->next;
	}
	randXY();
	h = new Human(coordinates[0], coordinates[1], *this);
	human = h;
	current->insert(h);
	current = current->next;
	for (int i = 0; i < initialPopulation_; i++)
	{
		randXY();
		h = new Sheep(coordinates[0], coordinates[1], *this);
		current->insert(h);
		isOccupied[coordinates[0]][coordinates[1]] = 1;
		current = current->next;
	}
	for (int i = 0; i < initialPopulation_; i++)
	{
		randXY();
		h = new Antelope(coordinates[0], coordinates[1], *this);
		current->insert(h);
		isOccupied[coordinates[0]][coordinates[1]] = 1;
		current = current->next;
	}
	for (int i = 0; i < initialPopulation_; i++)
	{
		randXY();
		h = new Turtle(coordinates[0], coordinates[1], *this);
		current->insert(h);
		isOccupied[coordinates[0]][coordinates[1]] = 1;
		current = current->next;
	}
	for (int i = 0; i < initialPopulation_; i++)
	{
		randXY();
		h = new Grasp(coordinates[0], coordinates[1], *this);
		current->insert(h);
		isOccupied[coordinates[0]][coordinates[1]] = 1;
		current = current->next;
	}
	for (int i = 0; i < initialPopulation_; i++)
	{
		randXY();
		h = new Yellow(coordinates[0], coordinates[1], *this);
		current->insert(h);
		isOccupied[coordinates[0]][coordinates[1]] = 1;
		current = current->next;
	}
	for (int i = 0; i < initialPopulation_; i++)
	{
		randXY();
		h = new Guarana(coordinates[0], coordinates[1], *this);
		current->insert(h);
		isOccupied[coordinates[0]][coordinates[1]] = 1;
		current = current->next;
	}
	for (int i = 0; i < initialPopulation_; i++)
	{
		randXY();
		h = new WolfBerries(coordinates[0], coordinates[1], *this);
		current->insert(h);
		isOccupied[coordinates[0]][coordinates[1]] = 1;
		current = current->next;
	}
	for (int i = 0; i < initialPopulation_; i++)
	{
		randXY();
		h = new KillerSosnowskyi(coordinates[0], coordinates[1], *this);
		current->insert(h);
		isOccupied[coordinates[0]][coordinates[1]] = 1;
		current = current->next;
	}
	current = head->next;
	while (current != nullptr)
	{
		current->organism->setAdulthood(true);
		current = current->next;
	}
}