#include "Leaderboard.h"

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
