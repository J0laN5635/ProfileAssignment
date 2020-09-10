#pragma once
#include "Player.h"

class Leaderboard
{
public:
	// maxPlayers range bwteen 1-100
	//Defines Max capatcity of leaderboard
	Leaderboard(unsigned int maxPlayers = 10);
	~Leaderboard();

private:
	Player* playerList = nullptr;

	unsigned int maxPlayers = 0;
	unsigned int playersInUse = 0;

};

