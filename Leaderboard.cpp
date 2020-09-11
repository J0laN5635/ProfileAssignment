#include "Leaderboard.h"
#include <iostream>

using namespace std;

Leaderboard::Leaderboard(unsigned int _maxPlayers)
	: maxPlayers(_maxPlayers), playersInUse(0)
{
	if (maxPlayers == 0)
	{
		maxPlayers = 10;
	}

	if (maxPlayers > 100)
	{
		maxPlayers = 100;
	}
	
	playerList = new Player[maxPlayers];
}

Leaderboard::~Leaderboard()
{
	delete[] playerList;
} 

void Leaderboard::Draw()
{
	cout << "-=-=-=-=-=-=-=-=-=-" << endl;
	cout << "    Leaderboard" << endl;
	cout << "-=-=-=-=-=-=-=-=-=-" << endl;

	for (unsigned int i = 0; i < playersInUse; i++)
	{
		playerList[1].Draw();
	}
}
