#include "PlayerDatabase.h"
#include <iostream>
#include "stdlib.h"
#include <string>

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
	MenuOption menuOption = getMenuOption();

	switch (menuOption)
	{
	case MenuOption::NewPlayer:
			break;

	case MenuOption::Quit:
		isGameRunning = false;
		break;
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

PlayerDatabase::MenuOption PlayerDatabase::getMenuOption()
{
	cout << "-=- Menu -=-" << endl;
	cout << "[1]: Exit" << endl;

	string userInput;
	cin.ignore(cin.rdbuf()->in_avail()); // clear pending input
	cin >> userInput;

	//Tutorial 1:25:37


}
