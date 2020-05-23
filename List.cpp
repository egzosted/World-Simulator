#pragma once
#include "List.h"
#include <iostream>
using namespace std;

void List::insert(Organism* o)
{
	List* x = new List;
	x->organism = o;
	this->next = x;
	x->next = nullptr;
}

void List::insertByCourage(Organism* o)
{
	List* ptr = this;
	List* x = new List;
	List* dx = nullptr;
	while (ptr != nullptr)
	{
		if (ptr->next == nullptr || ptr->next->organism->getCourage() < o->getCourage())
		{
			x->organism = o;
			dx = ptr->next;
			ptr->next = x;
			x->next = dx;
			dx = nullptr;
			return;
		}
		ptr = ptr->next;
	}
}

Organism* List::find(int x, int y)
{
	List* findPTR = nullptr;
	findPTR = this->next;
	while (findPTR != nullptr)
	{
		if (findPTR->organism->getX() == x && findPTR->organism->getY() == y)
		{
			Organism* o = findPTR->organism;
			return o;
		}
		findPTR = findPTR->next;
	}
}

void List::remove(int x, int y)
{
	List* findPTR = nullptr;
	List* dx = nullptr;
	findPTR = this;
	while (true)
	{
		if (findPTR->next->organism->getX() == x && findPTR->next->organism->getY() == y)
		{
			dx = findPTR->next->next;
			findPTR->next = dx;
			return;
		}
			findPTR = findPTR->next;
	}
	return;
}

List::~List()
{
	delete next;
}