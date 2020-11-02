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

	unsigned int PlayersInUse() const { return playersInUse; }
	unsigned int MaxPlayers() const { return maxPlayers; }

	unsigned int size() const { return playersInUse; }
	unsigned int capacity() const { return maxPlayers; }

	Player& GetPlayer(unsigned int index) const { return playerList[index]; }

	void Draw();
	void AddPlayer(const string &name, unsigned int score);
	void AddPlayer(const Player& player);
	void Clear();

	Player& operator[](unsigned int pos);

	//return iterators to basic array
	const Player* begin() const { return playerList; }
	const Player* end() const { return playerList + playersInUse; }

	void sortLeaderboardbyscore();
	void sortByName();

	//Binary Search the collection & returns true on success and updates pos to reflect position
	//returns false if not found
	bool Search(const string& name, unsigned int& posFound);



private:
	Player* playerList = nullptr;

	unsigned int maxPlayers = 0;
	unsigned int playersInUse = 0;

};

