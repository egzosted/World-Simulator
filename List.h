#pragma once
#include "Organism.h"

class List
{
public:
	int i;
	Organism* organism = nullptr;
	List* next;
	void insert(Organism* o);
	void insertByCourage(Organism* o);
	Organism* find(int x, int y);
	void remove(int x, int y);
	~List();
};