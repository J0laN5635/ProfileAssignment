#include "PlayerDatabase.h"
#include <iostream>
#include "stdlib.h"
#include <string>
#include <algorithm>

using namespace std;


void PlayerDatabase::Init()
{
	//Load the leaderboard from file

	try
	{
		leaderboard.AddPlayer("Joel", 300);
		leaderboard.AddPlayer("Zaydan", 190);
		leaderboard.AddPlayer("Paul", 2);
	}
	catch (exception & err)
	{
		cout << "Error" << err.what() << "Press any key to continue" << endl;
		getchar();
	}
}

void PlayerDatabase::Shutdown()
{
	//Save the leaderboard
}

bool PlayerDatabase::IsGameRunning()
{
	return isGameRunning;
}

void PlayerDatabase::Update()
{
	string menuOption = getMenuOption();

	if (menuOption == "a")
	{
		addNewPlayer();
	}

	else if (menuOption == "c")
	{
		leaderboard.Clear();
	}

	else if (menuOption == "q")
	{
		isGameRunning = false;
	}

}

void PlayerDatabase::Draw()
{
	//Draw leaderboard and Main Menu
	system("cls");
	leaderboard.Draw();
}

void PlayerDatabase::displayMenu()
{
	cout << endl << "-=- Main Menu -=-" << endl;
	cout << "A)dd Player" << endl;
	cout << "C)lear Leaderboard" << endl;
	cout << "Q)uit" << endl;
	cout << "-=-=-=-=-=-=-=-=-" << endl;
	cout << "> ";
}

string PlayerDatabase::getMenuOption()
{
	string userInput;
	cin.ignore(cin.rdbuf()->in_avail()); // clear pending input
	cin >> userInput;

	transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

	return userInput;

	//Tutorial 1:01 May 22
}

void PlayerDatabase::addNewPlayer()
{
	if (!leaderboard.IsFull())
	{
		Player p;
		if (p.LoadFromConsole())
		{
			leaderboard.AddPlayer(p);
		}
	}

	else
	{
		cout << "Leaderboard is full." << endl;
		getchar();
	}
}
