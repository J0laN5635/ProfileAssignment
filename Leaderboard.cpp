#include "Leaderboard.h"
#include <iostream>
#include <algorithm>

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
			cout <<" [" << i+1 << "] ";
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

Player& Leaderboard::operator[](unsigned int pos)
{
	if (pos > playersInUse)
	{
		throw exception("Out of bounds");
	}
	return playerList[pos];
}

bool comparePlayerScores(const Player & lhs, const Player & rhs)
{
	return lhs.GetHighScore() < rhs.GetHighScore();
}

bool comparePlayerNames(const Player& lhs, const Player& rhs)
{
	return (strcmp(lhs.GetName(), rhs.GetName()) < 0);
}

void Leaderboard::sortLeaderboardbyscore()
{
	sort(playerList, playerList + playersInUse);
	//sort(playerList, playerList + playersInUse, comparePlayerScores);
}

void Leaderboard::sortByName()
{
	sort(playerList, playerList + playersInUse, comparePlayerNames);
}

bool Leaderboard::Search(const string& name, unsigned int& posFound)
{
	//need to sort collection before doing binary search
	sortByName();

	unsigned int l = 0;
	unsigned int r = playersInUse - 1;
	unsigned int m;

	while (l <= r)
	{
		m = (l + r) / 2;
		if (name == playerList[m].GetName())
		{
			posFound = m;
			return true;
		}

		else if (name < playerList[m].GetName())
		{
			r = m - 1;
		}

		else if (name > playerList[m].GetName())
		{
			l = m + 1;
		}
	}
	
	return false;
}

