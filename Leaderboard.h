#pragma once
#include "Player.h"
#include <string>

using namespace std;

class Leaderboard
{
public:
	// maxPlayers range bwteen 1-100
	//Defines Max capatcity of leaderboard
	Leaderboard(unsigned int maxPlayers = 10);
	~Leaderboard();

	bool IsEmpty() const { return (playersInUse == 0); }
	bool IsFull() const { return (playersInUse >= maxPlayers); }
	unsigned int size() const { return playersInUse; }
	unsigned int capacity() const { return maxPlayers; }

	void Draw();
	void AddPlayer(const string &name, unsigned int score);
	void AddPlayer(const Player& player);
	void Clear();



private:
	Player* playerList = nullptr;

	unsigned int maxPlayers = 0;
	unsigned int playersInUse = 0;

};

