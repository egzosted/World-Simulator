#pragma once
#include "List.h"
#include "Animal.h"
#include "Plant.h"
#include "Human.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grasp.h"
#include "Yellow.h"
#include "Guarana.h"
#include "WolfBerries.h"
#include "KillerSosnowskyi.h"
class World
{
private:
	int width_, height_, initialPopulation_, coordinates[2], direction_, round_;	//coordinates represent future location of organism
	bool end_;
	const int numberOfSpecies = 10;
	char** board;	//2d array containing symbols of organisms
	Organism* human;
public:
	const int LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80; //ascii codes of arrow keys
	List* head = nullptr;
	List* current = nullptr;
	List* currentPS = nullptr;
	string report;
	int** isOccupied = nullptr;
	World();
	int getWidth();
	int getHeight();
	int getDirection();
	int getFirstCoordinate();
	int getSecondCoordinate();
	int getEnd();
	int getRound();
	int checkDirection();
	void getInfo();	//method to get from user size of board and beginning population
	void initFlags(); //dynamic allocation of 2d arrays
	void addStartAnimals(); //method to create first units
	void generateSymbols();	//method to assign symbols to proper indexes of board based on organism locations
	void markEnd();
	void setRound(int r);
	void incrementRound();
	void randXY();	//draw of coordinates
	void setCoordinates(int x, int y);
	void saveGame(string filename);
	void loadGame(string filename);
	int performBoard(int direction, int ultimate);
	void printBoard();	//method to print 2d array of symbols
	~World();
};
