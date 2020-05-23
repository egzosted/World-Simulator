#include "World.h"
#include <iostream>
#include "windows.h"
#include "stdlib.h"
#include "time.h"
using namespace std;

World::World()
{
	end_ = false;
	round_ = 1;
	report = "";
	head = new List;
	current = head;
	currentPS = head;
	head->next = nullptr;
}

void World::getInfo()
{
	cout << "Welcome to World Simulator 2019!" << endl;
	Sleep(1000);
	system("cls");
	int width, height;
	cout << "Enter size of board! (75 is minimum value of area)\n" << "width: ";
	cin >> width;
	cout << "and height: ";
	cin >> height;
	Sleep(1000);
	if (width * height < 75 || width <= 0 || height <= 0)
	{
		cout << "Our organisms need more space :(";
		exit(0);
	}
	char c;
	cout << "Choose initial population of species: s - small, a - average, b - big: ";
	cin >> c;
	switch (c)
	{
	case 's':
		initialPopulation_ = 3;
		break;
	case 'a':
		initialPopulation_ = 5;
		break;
	case 'b':
		initialPopulation_ = 7;
		break;
	default:
		cout << "Incorrect value!" << endl;
		Sleep(1000);
		exit(0);
	}
	width_ = width;
	height_ = height;
	Sleep(2000);
	system("cls");
}

void World::initFlags()
{
	isOccupied = new int*[height_];
	for (int i = 0; i < height_; i++)
		isOccupied[i] = new int[width_];

	for (int i = 0; i < height_; i++)
		for (int j = 0; j < width_; j++)
			isOccupied[i][j] = 0;

	board = new char*[height_];
	for (int i = 0; i < height_; i++)
		board[i] = new char[width_];
}

int World::getWidth()
{
	return width_;
}

int World::getHeight()
{
	return height_;
}

int World::getEnd()
{
	return end_;
}

int World::getRound()
{
	return round_;
}

void World::setRound(int r)
{
	round_ = r;
}

void World::incrementRound()
{
	round_++;
}

void World::markEnd()
{
	end_ = true;
}

World::~World()
{
	current = head->next;
	while (current != nullptr)
	{
		free(current->organism);
		current = current->next;
	}
	delete head;
	delete current;
	delete currentPS; 
	for (int i = 0; i < height_; i++)
	{
		delete[] board[i];
		delete[] isOccupied[i];
	}
	delete[] board;
	delete[] isOccupied;
}

int World::getDirection()
{
	return direction_;
}