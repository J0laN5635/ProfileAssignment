#pragma once
#include "Player.h"

using namespace std;

class Leaderboard
{
public:
	// maxPlayers range bwteen 1-100
	//Defines Max capatcity of leaderboard
	Leaderboard(unsigned int maxPlayers = 10);
	~Leaderboard();

	void Draw();

private:
	Player* playerList = nullptr;

	unsigned int maxPlayers = 0;
	unsigned int playersInUse = 0;

};

