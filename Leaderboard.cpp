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

	if (!IsEmpty())
	{
		for (unsigned int i = 0; i < playersInUse; i++)
		{
			playerList[i].Draw();
		}
	}
	else
	{
		cout << "... Empty ..." << endl;
	}
	//tutorial 1:40:40 may 22
}

void Leaderboard::AddPlayer(const string &name, unsigned int score)
{
	AddPlayer(Player(name.c_str(), score));
}

void Leaderboard::AddPlayer(const Player & player)
{
	if (playersInUse < maxPlayers)
	{
		playerList[playersInUse] = player;
		playersInUse++;
	}
	else
	{
		throw exception("Out of bounds. Leaderboard full.");
	}
}

void Leaderboard::Clear()
{
	playersInUse = 0;
}
