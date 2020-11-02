#include "PlayerDatabase.h"
#include <iostream>
#include "stdlib.h"
#include <string>
#include <algorithm>
#include "iostreamutils.h"

using namespace std;


void PlayerDatabase::Init()
{
	//Load the leaderboard from file

	try
	{
		leaderboard.AddPlayer("Joel", 300);
		leaderboard.AddPlayer("Zaydan", 190);
		leaderboard.AddPlayer("Paul", 2);

		//Sorts leaderboard by highscore
		leaderboard.sortLeaderboardbyscore();

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
	displayMenu();
	string menuOption = getMenuOption();

	if (menuOption == "a")
	{
		addNewPlayer();
	}

	else if (menuOption == "m")
	{
		modifyPlayerByName();
	}

	else if (menuOption == "n")
	{
		leaderboard.sortByName();
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
	cout << "(A)dd Player" << endl;
	cout << "(M)odify by name" << endl;
	cout << "Sort by (N)ame" << endl;
	cout << "(C)lear Leaderboard" << endl;
	cout << "(Q)uit" << endl;
	cout << "-=-=-=-=-=-=-=-=-" << endl;
	cout << "> ";
}

string PlayerDatabase::getMenuOption()
{
	string userInput;
	cinclear(); // clear pending input & errir fkags
	cin >> userInput;

	transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

	return userInput;

}

void PlayerDatabase::addNewPlayer()
{
	if (!leaderboard.IsFull())
	{
		Player p;
		if (p.LoadFromConsole())
		{
			leaderboard.AddPlayer(p);

			leaderboard.sortLeaderboardbyscore();
		}
	}

	else
	{
		cout << "Leaderboard is full." << endl;
		getchar();
	}
}

void PlayerDatabase::modifyPlayerByIndex()
{
	cinclear();
	cout << "Enter index of player to modify> ";
	
	unsigned int pos = 0;
	unsigned int input;
	cin >> input;
	pos = input - 1;

	if (pos < leaderboard.PlayersInUse())
	{
		leaderboard[pos].LoadFromConsole();
		leaderboard.sortLeaderboardbyscore();
	}

}

void PlayerDatabase::modifyPlayerByName()
{
	cinclear();
	cout << "Enter Name of Player to modify>";
	string name;
	cin >> name;

	//Ask leaderbaord to binary search and return pos in array
	unsigned int pos = 0;

	if (leaderboard.Search(name, pos))
	{
		//Update the player data
		leaderboard[pos].LoadFromConsole();

		//Sort Players by highscore
		leaderboard.sortLeaderboardbyscore();
	}

}


