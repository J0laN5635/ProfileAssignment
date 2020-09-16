#include "PlayerDatabase.h"
#include <iostream>
#include "stdlib.h"
#include <string>
#include <algorithm>

using namespace std;


void PlayerDatabase::Init()
{
	//Load the leaderboard from file
}

void PlayerDatabase::Shutdown()
{
	//Save the leaderboard
}

bool PlayerDatabase::IsGameRunning()
{
	return false;
}

void PlayerDatabase::Update()
{
	string menuOption = getMenuOption();

	if (menuOption == "n")
	{
		cout << "New Player" << endl;
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

void PlayerDatabase::displayerMenu()
{
}

string PlayerDatabase::getMenuOption()
{
	cout << "-=- Menu -=-" << endl;
	cout << "Q)uit" << endl;

	string userInput;
	cin.ignore(cin.rdbuf()->in_avail()); // clear pending input
	cin >> userInput;

	transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

	return userInput;

}
