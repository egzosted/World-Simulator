#include <iostream>
#include "World.h"
#include "Organism.h"
#include "Animal.h"
#include "Human.h"
#include "List.h"
#include <windows.h>
#include "conio.h"
#include <cstdlib>
#include "time.h"
using namespace std;

int main()
{
	srand(time(NULL));
	SetConsoleTitle("Michal Piekarski 175456");
	int ch = 0, ultimate = 0;
	string filename;
	World world;
	world.getInfo();
	world.initFlags();	//this method requires width and height so it cant'be before getInfo()
	world.addStartAnimals();	//this method requires flags so it can't be before initFlags()
	while (ch != 'q' && world.getEnd() == 0)
	{
		cout << world.getRound() << ". round of simulation" << endl << endl;
		cout << "Press the button (q --> exit, r-->ulti, s-->save, l-->load, v-->show_symbols)" << endl;
		world.generateSymbols();
		world.printBoard();
		cout << world.report << endl;
		world.report = "";
		ch = _getch();
		if (ch == 'R' || ch == 'r')
		{
			ultimate = 1;
			ch = _getch();
		}
		if (ch == 'S' || ch == 's')
		{
			cout << "Enter filename: ";
			cin >> filename;
			world.saveGame(filename);
			ch = _getch();
		}
		if (ch == 'L' || ch == 'l')
		{
			cout << "Enter filename: ";
			cin >> filename;
			world.loadGame(filename);
			ch = _getch();
		}
		if (ch == 224)
			ch = _getch();
		if (world.performBoard(ch, ultimate))
			world.incrementRound();
		else
			cout << "You pressed incorrect button!" << endl;
		ultimate = 0;
	}

	world.generateSymbols();
	world.printBoard();
	cout << world.report << endl;

	/*for (int i = 0; i < world.getHeight(); i++)
	{
		for (int j = 0; j < world.getWidth(); j++)
		{
			cout << world.isOccupied[i][j] << " ";
		}
		cout << endl;
	}*/

	system("pause");
	return 0;
}